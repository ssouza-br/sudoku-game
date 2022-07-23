import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
import time
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///sudoku.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # hist = db.execute(
    #     "SELECT symbol, name, SUM(quantity) as quantity, price, cash FROM transactions WHERE users_id = ? GROUP BY name ORDER BY time ASC", session["user_id"])
    # print(hist)
    return render_template("index.html")


@app.route("/game", methods=["GET", "POST"])
@login_required
def game():
    if request.method == "POST":
        json_res = db.execute("SELECT * FROM answer_games WHERE COD_MATRIZ = 1")
        print(json_res)
        for key, val in request.form.items():
            # print('ordem ', key[2])
            # print('nitem ', key[:2])
            if int(json_res[int(key[2])-1][str(key[:2])]) == int(val):
                flash(
                    'Vc acertou linha:{} coluna:{}, campeão!!!'.format(key[2], str(key[1])), 'success')
                # print('acertou '+key)
                # print('val', val)
                # print('digitado', json_res[int(key[2])-1][str(key[:2])])
            else:
                flash(u'Vc errou linha:{} coluna:{}, campeão!!!'.format(key[2], str(key[1])), 'error')
                # print('errou '+key)
                # print('val', val)
                # print('digitado', json_res[int(key[2])-1][str(key[:2])])
        return redirect("/")
    else:
        return render_template("game.html")

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    # return render_template("history.html", res=hist)


@app.route("/new", methods=["GET", "POST"])
@login_required
def new():
    if request.method == "POST":
        level = request.form.get("level")
        numGame = request.form.get("#game")
        numGame = 1

        res = db.execute("SELECT * FROM new_games WHERE COD_MATRIZ= ?", numGame)
        print(res)
        return render_template("game.html",res=res)

    else:
        return render_template("new.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/register", methods=["GET", "POST"])
def register():
    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        """Register user"""
        username = request.form.get("username")
        hash = generate_password_hash(request.form.get("password"))
        confirmation = request.form.get("confirmation")

        if not username:
            return apology("must provide username to registrated", 400)

        if not hash:
            return apology("must provide password to registrated", 400)

        if not confirmation:
            return apology("must provide passowrd again to registrated", 400)

        if confirmation != request.form.get("password"):
            return apology("passwords mismatched", 400)

        user_list = [i['username'] for i in db.execute("SELECT username FROM users")]
        if username in user_list:
            return apology("username already registrated", 400)
        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")
        # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html")