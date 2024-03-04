# include <iostream>
# include <vector>

using namespace std;

struct SudokuStruct {
    int sud[9][9];
};

struct ReiheSpalteQuadratStruct {
    int rsq[9];
};

struct Koordinaten {
	int kon[2];
};

namespace sk
{
	
    vector<Koordinaten> freieFelderErmitteln(SudokuStruct sudoku)
    {
		vector<Koordinaten> freieFelder;
		for (int i = 0; i < 9 ; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (sudoku.sud[i][j] == 0)
				{
					Koordinaten temp = {i,j};
					freieFelder.push_back(temp);
				}				
			}			
		} 
		return freieFelder;
    }
            
    vector<int> moeglicheEintraegeErmittelnRSQ(int felder[])
    {
    	vector<int> temp;
    	printf("\n");
		for (int i = 0; i < 9; i++)
		{
			printf("%d ", felder[i]);
		}		
		return temp;
    }   

    void bekommeQuadrat(int pos)
    {

    }
    
    vector<int> moeglicheEintraegeErmittelnAlle(SudokuStruct sudoku, Koordinaten reiheSpalte)
    {
		vector<int> temp;
		int qTemp = 0;
		int sr[9];
		int ss[9];
		int sq[9];		
		
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (reiheSpalte.kon[0] == i)
				{
					sr[j] = sudoku.sud[i][j];
				}
				if (reiheSpalte.kon[1] == j)
				{
					ss[i] = sudoku.sud[i][j];
				}
				if ( ((reiheSpalte.kon[0] + 1) / 3 == (i + 1) / 3) && ((reiheSpalte.kon[1] + 1) / 3 == (j + 1) / 3 ) ) //fragwuerdig
				{
					sq[qTemp] = sudoku.sud[i][j];
					qTemp++;
				}
			}
		}
		
		vector<int> r = moeglicheEintraegeErmittelnRSQ(sr);
		//vector<int> s = moeglicheEintraegeErmittelnRSQ(ss);
		//vector<int> q = moeglicheEintraegeErmittelnRSQ(sq);
		
		return temp;
    }
    
    vector< vector<int> > moeglicheEintraegeErmitteln(SudokuStruct sudoku, vector<Koordinaten> freieFelder) 
    {
		vector< vector<int> > moeglicheEintraege;
		for (int i = 0; i < freieFelder.size(); i++)
		{
			moeglicheEintraege.push_back(moeglicheEintraegeErmittelnAlle(sudoku, freieFelder[i]));
		}		
		return moeglicheEintraege;
    }
    
    SudokuStruct kombinierteFelderUndMoeglicheEintraege (SudokuStruct sudoku)
    {
    	vector<Koordinaten> freieFelder = freieFelderErmitteln(sudoku);
    	vector< vector<int> > moeglicheEintraege = moeglicheEintraegeErmitteln(sudoku, freieFelder);    	
        return sudoku; //return aender zu freieFelder + moeglicheEintraege
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

