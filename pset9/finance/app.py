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
db = SQL("sqlite:///finance.db")

# History list


# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


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
    hist = db.execute(
        "SELECT symbol, name, SUM(quantity) as quantity, price, cash FROM transactions WHERE users_id = ? GROUP BY name ORDER BY time ASC", session["user_id"])
    print(hist)
    return render_template("index.html", res=hist)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        """Register user"""
        try:
            qty = int(request.form.get("shares"))
        except ValueError:
            return apology("must provide integers quatitity of shares to buy", 400)

        try:
            symbol = request.form.get("symbol").upper()
        except ValueError:
            return apology("must provide symbol to buy", 400)

        if not symbol.isalnum():
            return apology("must provide alphanumeric symbol to buy", 400)

        if not request.form.get("shares"):
            return apology("must provide quatitity of shares to buy", 400)

        if qty < 0:
            return apology("must provide positive quatitity of shares to buy", 400)

        t = datetime.now()

        dict_res = lookup(symbol)

        cash = db.execute("SELECT CASH FROM users WHERE id = ?", session["user_id"])
        if len(cash) != 0:
            cash = cash[0]['cash']

        cost = qty * dict_res['price']

        dict_res['cost'] = cost
        dict_res['qty'] = qty
        dict_res['symbol'] = dict_res['symbol'].upper()

        if cost <= cash:
            new_cash = cash - cost
            db.execute("UPDATE users SET CASH = ? WHERE id = ?",
                       new_cash, session["user_id"])
            dict_res['cash'] = new_cash

            if len(db.execute(
                    "SELECT * FROM transactions WHERE users_id = ? and symbol = ?", session["user_id"], dict_res['symbol'])) == 0:
                db.execute(
                    "INSERT INTO transactions (users_id, symbol, name, price, quantity, cash, time) VALUES (?, ?, ?, ?, ?, ?, ?)", session["user_id"], dict_res['symbol'], dict_res['name'], dict_res['price'], dict_res['qty'], dict_res['cash'], t)
            else:
                temp = db.execute(
                        "SELECT quantity FROM transactions WHERE users_id = ? and symbol = ?", session["user_id"], dict_res['symbol'])
                if len(temp)!=0:
                    db.execute("UPDATE transactions SET quantity = ?, cash = ?, time = ? WHERE users_id = ? and symbol = ?", temp[0]['quantity'] + dict_res['qty'], dict_res['cash'], t, session["user_id"], dict_res['symbol'])
            return redirect("/")
        else:
            return apology("You don't have money enough to buy these shares")

        # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("buy.html")



@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    hist = db.execute(
        "SELECT * FROM transactions WHERE users_id = ? ORDER BY time ASC", session["user_id"])
    return render_template("history.html", res=hist)

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


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        """Register user"""
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("must provide symbol to quote", 400)

        dict_res = lookup(symbol)
        if dict_res != None:
            # Redirect user to home page
            return render_template("quoted.html", dict_res=dict_res)
        else:
            return apology("invalid symbol to quote", 400)
        # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("quote.html")

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

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        """Register user"""
        symbol = request.form.get("symbol").upper()
        qty = int(request.form.get("shares"))

        if not symbol:
            return apology("must provide symbol to buy", 400)

        if not qty:
            return apology("must provide quatitity of shares to buy", 400)

        if qty < 0:
            return apology("must provide positive quatitity of shares to buy", 400)

        current_qty = db.execute("SELECT quantity FROM transactions WHERE users_id = ? and symbol = ?", session["user_id"], symbol)
        current_qty = current_qty[0]['quantity']
        if qty > current_qty:
            return apology("don't try to sell more that you have", 400)

        t = datetime.now()

        dict_res = lookup(symbol)

        cash = db.execute(
            "SELECT CASH FROM users WHERE id = ?", session["user_id"])
        cash = cash[0]['cash']

        cost = qty * dict_res['price']

        dict_res['cost'] = cost
        dict_res['qty'] = -1*qty
        dict_res['symbol'] = dict_res['symbol'].upper()

        new_cash = cash + cost
        db.execute("UPDATE users SET CASH = ? WHERE id = ?",
                    new_cash, session["user_id"])
        dict_res['cash'] = new_cash

        db.execute(
            "INSERT INTO transactions (users_id, symbol, name, price, quantity, cash, time) VALUES (?, ?, ?, ?, ?, ?, ?)", session["user_id"], dict_res['symbol'], dict_res['name'], dict_res['price'], dict_res['qty'], dict_res['cash'], t)

        return redirect("/")

        # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("sell.html")