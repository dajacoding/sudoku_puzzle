from collections import Counter

sudokuStart = [
    [4, 3, 0, 5, 0, 6, 9, 0, 0],        
    [0, 9, 0, 0, 0, 0, 0, 0, 8],        
    [0, 0, 0, 0, 0, 2, 0, 0, 0],        
    [0, 0, 7, 0, 0, 0, 0, 1, 0],        
    [0, 0, 0, 0, 3, 0, 0, 0, 0],        
    [6, 0, 0, 4, 0, 9, 8, 0, 0],        
    [0, 0, 0, 0, 2, 0, 5, 0, 0],        
    [0, 0, 6, 3, 0, 5, 0, 0, 7],        
    [3, 0, 0, 0, 8, 0, 0, 0, 0]
]

def testReihe(reihe):
    return test(Counter(reihe))    

def testSpalte(sudoku, spalte):
    temp = [s[spalte] for s in sudoku]
    return test(Counter(temp))

def testQuadrat(sudoku, posSpalte, posReihe):
    x = getQuadrant(posReihe)
    y = getQuadrant(posSpalte)
    temp = []
    for xx in x:
        for yy in y:
            temp.append(sudoku[xx][yy])
    return test(Counter(temp))

def getQuadrant(pos):
    if pos < 3:
        return [0, 1, 2]
    elif pos < 6:
        return [3, 4, 5]
    else:
        return [6, 7, 8]

def test(liste):
    for i in liste.items():
        if i[0] > 0 and i[1] > 1:
            return False
    return True

def tests(sudoku, reihe, spalte):
    if testReihe(sudoku[reihe]) and testSpalte(sudoku, spalte) and testQuadrat(sudoku, spalte, reihe): return True
    return False

def eintragung(sudoku):
    temp = sudoku
    historie = []
    for row in sudoku:
        for collumn in row:
            if collumn == 0:
                for e in range(1, 10):
                    temp[row][collumn] = e
                    if tests:
                        historie.append([row, collumn, e])
                        break
                    else:
                        temp[row][collumn] = 0     
                         # historie um ein element zurück, => löschen
    return

def hauptfunktion():
    
    return

hauptfunktion()
