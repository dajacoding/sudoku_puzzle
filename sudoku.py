from copy import deepcopy as dc
from collections import Counter

def startFunktion():
    sudokuStart = [
        [0, 9, 0, 1, 0, 0, 0, 0, 0],        
        [1, 0, 6, 0, 0, 8, 7, 0, 0],        
        [0, 0, 0, 5, 0, 0, 0, 3, 0],        
        [0, 0, 0, 0, 6, 0, 0, 0, 7],        
        [0, 0, 2, 0, 0, 0, 0, 0, 0],        
        [4, 0, 8, 0, 0, 1, 6, 0, 0],        
        [0, 2, 0, 0, 0, 0, 4, 0, 0],        
        [0, 7, 0, 0, 0, 9, 0, 0, 0],        
        [9, 0, 4, 8, 0, 0, 0, 0, 5]]    
    if recursEintragung(sudokuStart): print('Fin')
    
def recursEintragung(sudoku):
    if zeichneSudoku(sudoku): return True   
    for wahrscheinlichkeit in range(5):
        for k in kombinierteFelderUndMoeglicheEintraege(sudoku):       
            if len(k[1]) == wahrscheinlichkeit:
                if wahrscheinlichkeit == 0: return False
                for eintrag in k[1]:
                    sudokuSave = dc(sudoku)
                    sudoku[k[0][0]][k[0][1]] = eintrag
                    if recursEintragung(sudoku): return True
                    sudoku = sudokuSave

def kombinierteFelderUndMoeglicheEintraege(sudoku):    
    freieFelder = freieFelderErmitteln(sudoku)   
    moeglicheEintraege = moeglicheEintraegeErmitteln(sudoku, freieFelder)
    return [[freieFelder[x], moeglicheEintraege[x]] for x in range(len(freieFelder))]

def freieFelderErmitteln(sudoku):
    temp = []
    for f in [[[y, x] for x in range(9) if sudoku[y][x] == 0] for y in range(9)]:
        temp += f
    return temp

def moeglicheEintraegeErmitteln(sudoku, felderListe):
    return [moeglicheEintraegeErmittelnAlle(sudoku, f[0], f[1]) for f in felderListe]

def moeglicheEintraegeErmittelnAlle(sudoku, reihe, spalte):
    r = moeglicheEintraegeErmittelnReihe(sudoku[reihe])
    s = moeglicheEintraegeErmittelnSpalte(sudoku, spalte)
    q = moeglicheEintraegeErmittelnQuadrat(sudoku, reihe, spalte)
    return [x[0] for x in Counter(r + s + q).items() if x[1] == 3]

def moeglicheEintraegeErmittelnReihe(reihe):
    return [y for y in [x + 1 for x in range(9)] if y not in reihe]

def moeglicheEintraegeErmittelnSpalte(sudoku, spalte):
    return moeglicheEintraegeErmittelnReihe([x[spalte] for x in sudoku])

def moeglicheEintraegeErmittelnQuadrat(sudoku, reihe, spalte):
    temp = [[sudoku[x][y] for y in bekommeQuadrat(spalte)] for x in bekommeQuadrat(reihe)]
    return moeglicheEintraegeErmittelnReihe(temp[0] + temp[1] + temp[2])

def bekommeQuadrat(pos):
    if   pos < 3: return [0, 1, 2]
    elif pos < 6: return [3, 4, 5]
    else:         return [6, 7, 8]

def zeichneSudoku(sudoku):
    if len(freieFelderErmitteln(sudoku)) == 0: 
        for r, reihe in enumerate(sudoku):
            print(str(reihe[0])+' '+str(reihe[1])+' '+str(reihe[2])+' | '+str(reihe[3])+' '+str(reihe[4])+' '+str(reihe[5])+' | '+str(reihe[6])+' '+str(reihe[7])+' '+str(reihe[8]))
            if (r + 1) % 3 == 0 and (r + 1) != 9:
                print('------ ------- ------')
        print()
        return True
    

startFunktion()