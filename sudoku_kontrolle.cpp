# include <iostream>

struct SudokuStruct {
    int sud[9][9];
};

struct ReiheSpalteQuadratStruct {
    int rsq[9];
};

struct EintraegeStruct
{
    int mog[9];
};

namespace sk
{
    SudokuStruct kombinierteFelderUndMoeglicheEintraege (SudokuStruct sudoku)
    {
        return sudoku;
    }

    void freieFelderErmitteln(SudokuStruct sudoku)
    {

    }

    void moeglicheEintraegeErmitteln(SudokuStruct sudoku, int felderListe) 
    {

    }

    void moeglicheEintraegeErmittelnAlle(SudokuStruct sudoku, int reihe, int spalte)
    {

    }
        
    void moeglicheEintraegeErmittelnReihe(int reihe)
    {

    }   

    void moeglicheEintraegeErmittelnSpalte(SudokuStruct sudoku, int spalte)
    {

    } 

    void moeglicheEintraegeErmittelnQuadrat(SudokuStruct sudoku, int reihe, int spalte)
    {

    }

    void bekommeQuadrat(int pos)
    {

    }
}

// def kombinierteFelderUndMoeglicheEintraege(sudoku):    
//     freieFelder = freieFelderErmitteln(sudoku)   
//     moeglicheEintraege = moeglicheEintraegeErmitteln(sudoku, freieFelder)
//     return [[freieFelder[x], moeglicheEintraege[x]] for x in range(len(freieFelder))]

// def freieFelderErmitteln(sudoku):
//     temp = []
//     for f in [[[y, x] for x in range(9) if sudoku[y][x] == 0] for y in range(9)]:
//         temp += f
//     return temp

// def moeglicheEintraegeErmitteln(sudoku, felderListe):
//     return [moeglicheEintraegeErmittelnAlle(sudoku, f[0], f[1]) for f in felderListe]

// def moeglicheEintraegeErmittelnAlle(sudoku, reihe, spalte):
//     r = moeglicheEintraegeErmittelnReihe(sudoku[reihe])
//     s = moeglicheEintraegeErmittelnSpalte(sudoku, spalte)
//     q = moeglicheEintraegeErmittelnQuadrat(sudoku, reihe, spalte)
//     return [x[0] for x in Counter(r + s + q).items() if x[1] == 3]

// def moeglicheEintraegeErmittelnReihe(reihe):
//     return [y for y in [x + 1 for x in range(9)] if y not in reihe]

// def moeglicheEintraegeErmittelnSpalte(sudoku, spalte):
//     return moeglicheEintraegeErmittelnReihe([x[spalte] for x in sudoku])

// def moeglicheEintraegeErmittelnQuadrat(sudoku, reihe, spalte):
//     temp = [[sudoku[y][x] for x in bekommeQuadrat(spalte)] for y in bekommeQuadrat(reihe)]
//     return moeglicheEintraegeErmittelnReihe(temp[0] + temp[1] + temp[2])

// def bekommeQuadrat(pos):
//     if   pos < 3: return [0, 1, 2]
//     elif pos < 6: return [3, 4, 5]
//     else:         return [6, 7, 8]

