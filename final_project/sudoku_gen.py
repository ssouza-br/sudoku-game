from cs50 import SQL

db = SQL("sqlite:///sudoku.db")

sudo = [[1, 2, 3,  4, 5, 6,  7, 8, 9],
        [4, 5, 6,  7, 8, 9,  1, 2, 3],
        [7, 8, 9,  1, 2, 3,  4, 5, 6],

        [2, 3, 1,  5, 6, 4,  8, 9, 7],
        [5, 6, 4,  8, 9, 7,  2, 3, 1],
        [8, 9, 7,  2, 3, 1,  5, 6, 4],

        [3, 1, 2,  6, 4, 5,  9, 7, 8],
        [6, 4, 5,  9, 7, 8,  3, 1, 2],
        [9, 7, 8,  3, 1, 2,  6, 4, 5]]

for i in range(9):
    for j in range(9):
        db.execute("INSERT INTO new_games(COD_MATRIZ, ORDEM, N1, N2, N3, N4, N5, N6, N7, N8, N9) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?),
        i,  ")

