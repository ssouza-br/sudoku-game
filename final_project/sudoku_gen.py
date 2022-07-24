from cs50 import SQL
from dokusan import generators
import numpy as np

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

print(type(sudo))

# sudo = generators.random_sudoku(avg_rank=150)

# print(np.array([[1,2,3],[4,5,6]]))

#arr = np.array(list(str(generators.random_sudoku(avg_rank=150)))).reshape(9,9)
# lst = [int(ch) for ch in sudo]
# sudo = list(sudo)
#sudo = [int(num) for num in sudo].reshape(9,9)
#print(arr)
# print(sudo[0][0])
# print(sudo[0][8])
# print(sudo[8][8])

# for j in range(100):
#     sudo = np.array(
#         list(str(generators.random_sudoku(avg_rank=150)))).reshape(9, 9)
# #     sudo = np.array(list(str(sudo)))
# #     sudo = np.array([int(num) for num in sudo]).reshape(9, 9)
#     print(sudo)
#     for i in range(9):
#         db.execute("INSERT INTO new_games (COD_MATRIZ, ORDEM, N1, N2, N3, N4, N5, N6, N7, N8, N9) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", j+1, i+1, sudo[i][0], sudo[i][1], sudo[i][2], sudo[i][3], sudo[i][4], sudo[i][5], sudo[i][6], sudo[i][7], sudo[i][8])
#     print('jogo: ', j, 'salvo no banco')
