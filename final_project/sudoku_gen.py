from cs50 import SQL
from dokusan import generators
import numpy as np

db = SQL("sqlite:///sudoku.db")

# sudo = [[1, 2, 3,  4, 5, 6,  7, 8, 9],
#         [4, 5, 6,  7, 8, 9,  1, 2, 3],
#         [7, 8, 9,  1, 2, 3,  4, 5, 6],

#         [2, 3, 1,  5, 6, 4,  8, 9, 7],
#         [5, 6, 4,  8, 9, 7,  2, 3, 1],
#         [8, 9, 7,  2, 3, 1,  5, 6, 4],

#         [3, 1, 2,  6, 4, 5,  9, 7, 8],
#         [6, 4, 5,  9, 7, 8,  3, 1, 2],
#         [9, 7, 8,  3, 1, 2,  6, 4, 5]]

sudo = generators.random_sudoku(avg_rank=150)
# sudo = np.array(list(str(sudo))).reshape(9,9)
print(list(sudo))

# for j in range(100):
#     sudo = generators.random_sudoku(avg_rank=150)
#     #sudo = np.array(list(int(sudo))).reshape(9,9)
#     print(sudo)
#     for i in range(9):
#         db.execute("INSERT INTO new_games(COD_MATRIZ, ORDEM, N1, N2, N3, N4, N5, N6, N7, N8, N9) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", j+1, i+1, sudo[i][0], sudo[i][1], sudo[i][2], sudo[i][3], sudo[i][4], sudo[i][5], sudo[i][6], sudo[i][7], sudo[i][8])
#     print('jogo: ', j, 'salvo no banco')
# # # db.execute("UPDATE new_games SET N2 = NULL, N4 = NULL, N6 = NULL, N8 = NULL WHERE COD_MATRIZ = 1 and ORDEM = 7")


