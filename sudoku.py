from copy import deepcopy as dc
from collections import Counter

def startFunktion():
    sudokuStart = [
        [0, 6, 0, 0, 0, 9, 3, 0, 0],        
        [0, 7, 0, 0, 1, 0, 0, 0, 0],        
        [3, 0, 1, 0, 0, 2, 0, 4, 0],        
        [0, 1, 0, 0, 0, 0, 0, 0, 0],        
        [0, 0, 0, 0, 0, 4, 0, 0, 8],        
        [9, 0, 5, 0, 2, 0, 7, 0, 0],        
        [0, 0, 0, 9, 0, 0, 0, 7, 0],        
        [2, 0, 3, 0, 5, 0, 9, 0, 0],        
        [6, 0, 0, 0, 0, 0, 0, 0, 0]]   
    if recursEintragung(sudokuStart): print('Fin') 

def recursEintragung(sudoku):
    if zeichneSudoku(sudoku): return True
    temp = dc(sudoku)
    kombinationen = kombinierteFelderUndMoeglicheEintraege(sudoku)
    if 0 in [len(k[1]) for k in kombinationen]: return False

    for anzahlMoeglichkeiten in range(1, 5):
        for k in kombinationen: 
            if len(k[1]) == anzahlMoeglichkeiten:

                for eintrag in k[1]:                    
                    sudoku[k[0][0]][k[0][1]] = eintrag
                    if recursEintragung(sudoku): return True
                    sudoku = temp
                    
    print('fuck ')

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
    temp = [[sudoku[y][x] for x in bekommeQuadrat(spalte)] for y in bekommeQuadrat(reihe)]
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
    return False  

if __name__ == '__main__':
    startFunktion()