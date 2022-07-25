from cs50 import SQL
from dokusan import generators, solvers
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

# print(type(sudo))


sudo = generators.random_sudoku(avg_rank=150)
print(sudo)
solution = solvers.backtrack(sudo)
print(solution)


# lst = list(str(generators.random_sudoku(avg_rank=150)))
# print(lst)
# # print(np.array([[1,2,3],[4,5,6]]))

# arr = np.array(list(str(generators.random_sudoku(avg_rank=150)))).reshape(9,9)
# lst2 = arr.tolist()

# ls2 = ['' if lst2[i][j] == '0' else lst2[i][j] for j in range(9) for i in range(9)]
# print(ls2)

# sudo = list(str(generators.random_sudoku(avg_rank=150)))
# sudo = ['' if sudo[i] == '0' else sudo[i] for i in range(81)]
# arr = np.array(sudo).reshape(9,9)
# sudo = arr.tolist()
# #sudo = sudo.tolist()
# print(sudo)

# arr = np.array(list(str(generators.random_sudoku(avg_rank=150))))

# ls2 = [if arr[i]=='0']
# [entry for tag in tags for entry in entries if tag in entry]

# print(lst2)
# # lst = [int(ch) for ch in sudo]
# # sudo = list(sudo)
# #sudo = [int(num) for num in sudo].reshape(9,9)
# #print(arr)
# # print(sudo[0][0])
# # print(sudo[0][8])
# # print(sudo[8][8])

# for j in range(10):
#     sudo = list(str(generators.random_sudoku(avg_rank=150)))
#     sudo = ['' if sudo[i] == '0' else sudo[i] for i in range(81)]
#     arr = np.array(sudo).reshape(9, 9)
#     sudo = arr.tolist()
#     print(sudo)
#     for i in range(9):
#         db.execute("INSERT INTO new_games (COD_MATRIZ, ORDEM, N1, N2, N3, N4, N5, N6, N7, N8, N9) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", j+1, i+1, sudo[i][0], sudo[i][1], sudo[i][2], sudo[i][3], sudo[i][4], sudo[i][5], sudo[i][6], sudo[i][7], sudo[i][8])
#     print('jogo: ', j, 'salvo no banco')
