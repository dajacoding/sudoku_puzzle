from copy import deepcopy as dc
from collections import Counter

def startFunktion():
    sudokuStart = [
        [4, 3, 0, 5, 0, 6, 9, 0, 0],        
        [0, 9, 0, 0, 0, 0, 0, 0, 8],        
        [0, 0, 0, 0, 0, 2, 0, 0, 0],        
        [0, 0, 7, 0, 0, 0, 0, 1, 0],        
        [0, 0, 0, 0, 3, 0, 0, 0, 0],        
        [6, 0, 0, 4, 0, 9, 8, 0, 0],        
        [0, 0, 0, 0, 2, 0, 5, 0, 0],        
        [0, 0, 6, 3, 0, 5, 0, 0, 7],        
        [3, 0, 0, 0, 8, 0, 0, 0, 0]]
    recursEintragung(sudokuStart, 0)
    
def recursEintragung(sudokuAlt, reihe): # eintragung ist fatal fehlerhaft!!!!!!!!!!!!!!!!!!!!!!
    sudoku = dc(sudokuAlt)
    freieFelder = [x for x in range(9) if sudoku[reihe][x] == 0]
    moeglicheZahlen = moeglicheZahlenErmitteln(sudoku[reihe])
    sudokuSammlung = []
    for f in freieFelder:
        for m in moeglicheZahlen:
            sudokuVersionsSave = dc(sudoku)
            sudoku = versuchEintragung(sudoku, reihe, f, m)
            if sudoku == False:
                sudoku = sudokuVersionsSave
            else:
                sudokuSammlung.append(sudoku)
            if reihe == 8 and keineNull(sudoku):
                printFertig(sudoku)
            
    if reihe < 8:
        for s in sudokuSammlung:
            t = 0
            for r in range(reihe):
                for f in range(r):
                    if s[r][f] == 0:
                        t += 1
            if t > 0:
                break
            recursEintragung(s, reihe + 1)
            
def keineNull(sudoku):
    for reihe in sudoku:
        for feld in reihe:
            if feld == 0:
                return False
    return True
            
def versuchEintragung(sudoku, reihe, feld, zahl):
    sudoku[reihe][feld] = zahl
    if pruefungen(sudoku, reihe, feld):
        return sudoku
    return False
    
def pruefungen(sudoku, reihe, spalte):
    if pruefungReihe(sudoku[reihe]) and pruefungSpalte(sudoku, spalte) and pruefungQuadrat(sudoku, reihe, spalte): 
        return True
    return False
    
def moeglicheZahlenErmitteln(reihe):
    alleZahlen = [x + 1 for x in range(9)]
    if 0 in reihe:
        temp = set(reihe)
        temp.remove(0)
        return [a for a in alleZahlen if a not in temp]
    
def pruefung(liste):
    for i in liste.items():
        if i[0] > 0 and i[1] > 1:
            return False
    return True
    
def pruefungReihe(reihe):
    return pruefung(Counter(reihe))
    
def pruefungSpalte(sudoku, spalte):
    temp = [s[spalte] for s in sudoku]
    return pruefung(Counter(temp))
    
def pruefungQuadrat(sudoku, posReihe, posSpalte):
    x = getQuadrant(posReihe)
    y = getQuadrant(posSpalte)
    temp = []
    for xx in x:
        for yy in y:
            temp.append(sudoku[xx][yy])
    return pruefung(Counter(temp))

def getQuadrant(pos):
    if pos < 3:
        return [0, 1, 2]
    elif pos < 6:
        return [3, 4, 5]
    else:
        return [6, 7, 8]
    
def printFertig(sudoku):
    for reihe in sudoku:
        print(reihe)

startFunktion()
