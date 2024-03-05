# include <stdio.h>
# include <stdbool.h>
# include <vector>

using namespace std;

struct SudokuStruct {
    int sud[9][9];
};

struct Koordinaten {
	int kon[2];
};

struct Situation {
    vector<Koordinaten> frei;
    vector< vector<int> > moeg; 
};

SudokuStruct bekommeStartSudoku() 
{
    SudokuStruct sudokuStart = {
        0, 6, 0, 0, 0, 9, 3, 0, 0,        
        0, 7, 0, 0, 1, 0, 0, 0, 0,        
        3, 0, 1, 0, 0, 2, 0, 4, 0,        
        0, 1, 0, 0, 0, 0, 0, 0, 0,        
        0, 0, 0, 0, 0, 4, 0, 0, 8,        
        9, 0, 5, 0, 2, 0, 7, 0, 0,        
        0, 0, 0, 9, 0, 0, 0, 7, 0,        
        2, 0, 3, 0, 5, 0, 9, 0, 0,        
        6, 0, 0, 0, 0, 0, 0, 0, 0};  
    return sudokuStart;
}

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
        
vector<int> moeglicheEintraegeErmittelnRSQ(int r[], int s[], int q[])
{
    vector<int> temp;
    for (int i = 1; i <= 9; i++)
    {
        int z = 0;
        for (int j = 0; j < 9; j++)
        {
            if ((r[j] == i ) || (s[j] == i) || (q[j] == i))
            {
                z++;
            } 
        }
        if (z == 0)
        {
            temp.push_back(i);
        }
    }	
    return temp;
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
            if (((reiheSpalte.kon[0] / 3) == (i / 3)) && ((reiheSpalte.kon[1] / 3) == (j / 3 ))) 
            {
                sq[qTemp] = sudoku.sud[i][j];
                qTemp++;
            }
        }
    }
    temp = moeglicheEintraegeErmittelnRSQ(sr, ss, sq);
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

Situation kombinierteFelderUndMoeglicheEintraege (SudokuStruct sudoku)
{
    Situation sit;
    sit.frei = freieFelderErmitteln(sudoku);
    sit.moeg = moeglicheEintraegeErmitteln(sudoku, sit.frei); 
    return sit; 
}

SudokuStruct kopieren(SudokuStruct original)
{
    SudokuStruct temp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            temp.sud[i][j] = original.sud[i][j];
        }
    }
    return temp;
}

bool fertig(SudokuStruct sudoku)
{
    int temp;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku.sud[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

bool recursionEintragung(SudokuStruct sudoku) 
{
    if (fertig(sudoku) == true) {return true;}
    SudokuStruct kopie = kopieren(sudoku);
    Situation sit = kombinierteFelderUndMoeglicheEintraege(sudoku);
    for (int i = 0; i < 4; i++)
    {
        for (int m = 0; m < sit.moeg.size(); m++)
        {
            if (sit.moeg[m].size() == i)
            {
                if (i > 0)
                {
                    for (int p = 0; p < sit.moeg[m].size(); p++)
                    {
                        sudoku.sud[sit.frei[m].kon[0]][sit.frei[m].kon[1]] = sit.moeg[m][p];
                        if (recursionEintragung(sudoku) == true){return true;} else {sudoku = kopie;}
                        //printf("%d %d %d \n", sit.frei[m].kon[0], sit.frei[m].kon[1], sit.moeg[m][p]);
                    }
                }
                else 
                {
                    return false;
                }
            }
        }
    }
    printf("fuck");
    return false;
}

int main()
{    
    if (recursionEintragung(bekommeStartSudoku()) == true) {printf("Fin");} else {printf("Nope");}
    return 0;
}

// def zeichneSudoku(sudoku):
