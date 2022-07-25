from cs50 import SQL
from dokusan import generators, solvers
import numpy as np

def sudo_to_list(sudo):
    sudo = list(str(sudo))
    sudo = ['' if sudo[i] == '0' else sudo[i] for i in range(81)]
    arr = np.array(sudo).reshape(9, 9)
    return arr.tolist()

db = SQL("sqlite:///sudoku.db")

sudo = generators.random_sudoku(avg_rank=150)
print(sudo)
solution = solvers.backtrack(sudo)
print(solution)

# delete from current_games;
# delete from sqlite_sequence where name = 'current_games';

# delete from new_games;
# delete from sqlite_sequence where name = 'new_games';

# delete from answer_games;
# delete from sqlite_sequence where name = 'answer_games';

for j in range(10):
    sudo_new = generators.random_sudoku(avg_rank=150)
    sudo = sudo_to_list(sudo_new)

    sudo_answer = solvers.backtrack(sudo)
    sudo_a = sudo_to_list(sudo_answer)

    for i in range(9):
        db.execute("INSERT INTO new_games (COD_MATRIZ, ORDEM, N1, N2, N3, N4, N5, N6, N7, N8, N9) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", j+1, i+1, sudo[i][0], sudo[i][1], sudo[i][2], sudo[i][3], sudo[i][4], sudo[i][5], sudo[i][6], sudo[i][7], sudo[i][8])
        db.execute("INSERT INTO answer_games (COD_MATRIZ, ORDEM, N1, N2, N3, N4, N5, N6, N7, N8, N9) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)", j+1, i+1, sudo_a[i][0], sudo_a[i][1], sudo_a[i][2], sudo_a[i][3], sudo_a[i][4], sudo_a[i][5], sudo_a[i][6], sudo_a[i][7], sudo_a[i][8])
    print('jogo: ', j, 'salvo no banco')
