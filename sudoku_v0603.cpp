# include <stdio.h>
# include <stdbool.h>
# include <vector>

using namespace std;

// Definition des Spielstandes
struct SudokuStruct {
    int sud[9][9];
};

// Angabe zu Feld in Sudoku
struct Koordinaten {
	int kon[2];
};

// Liste aus noch unbelegten Feldern
// und dazugehoerigen moeglichen Eintragungen
struct Situation {
    vector<Koordinaten> frei;
    vector< vector<int> > moeg; 
};

struct Unique {
    bool gefunden;
    Situation uni;  
};


// das zu loesende Sudoku
// noch zu erledigen: Entwicklung zu Eingabemaske
SudokuStruct bekommeStartSudoku() 
{
    SudokuStruct sudokuStart = {
        0, 0, 6, 0, 0, 0, 0, 7, 0,        
        8, 0, 0, 0, 0, 0, 0, 4, 6,        
        0, 0, 5, 3, 9, 0, 0, 0, 0,        
        0, 0, 0, 0, 0, 0, 3, 0, 1,        
        2, 0, 7, 0, 0, 0, 0, 6, 9,        
        0, 0, 0, 5, 0, 0, 0, 0, 0,        
        0, 0, 0, 0, 0, 0, 0, 0, 0,        
        0, 0, 9, 7, 0, 0, 0, 1, 5,        
        0, 6, 0, 0, 2, 8, 0, 0, 0};  
    return sudokuStart;
}


// Ermittlung freier Felder (jene mit default "0" - Eintrag)
// uebergabe: aktuellen Spielstand als Sudoku
// Rueckgabe: Vektor mit Koordinaten fuer freie Felder
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
        
        
// Ermittlung von nichtvorhandenen Eintragungen zwischen "1" und "9"
// Uebergabe: 3x Liste (Reihe, Spalte, Quadrat)
// Rueckgabe: Vektor mit Ziffern, die in keiner der Listen vorhanden ist
vector<int> moeglicheEintraegeErmittelnRSQ(int r[], int s[], int q[])
{
    vector<int> temp;
    for (int i = 1; i <= 9; i++)
    {
        int z = 0;
        for (int j = 0; j < 9; j++)
        {
            if ((r[j] == i ) || (s[j] == i) || (q[j] == i)) {z++;} 
        }
        if (z == 0) {temp.push_back(i);}
    }	
    return temp;
}   


// Ermittlung von moeglichen Eintragungen je Feld
// Uebergabe: aktuellen Spielstand (Sudoku) und Koordinaten fuer ein Feld
// Rueckgabe: Vektor mit (zu diesem Spielstand) legalen Eintragemoeglichkeiten
vector<int> moeglicheEintraegeErmittelnAlle(SudokuStruct sudoku, Koordinaten reiheSpalte)
{
    int qTemp = 0;
    int sr[9];
    int ss[9];
    int sq[9];		
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (reiheSpalte.kon[0] == i) {sr[j] = sudoku.sud[i][j];}
            if (reiheSpalte.kon[1] == j) {ss[i] = sudoku.sud[i][j];}
            if (((reiheSpalte.kon[0] / 3) == (i / 3)) && ((reiheSpalte.kon[1] / 3) == (j / 3 ))) 
            {
                sq[qTemp] = sudoku.sud[i][j];
                qTemp++;
            }
        }
    }
    return moeglicheEintraegeErmittelnRSQ(sr, ss, sq);
}


// Iterieren durch alle freien Felder
// Uebergabe: aktuellen Spielstand (Sudoku) und eine Liste (Vektor) mit allen freien Feldern 
// Rueckgabe: Vektor mit Vektoren an legalen Eintragungen
vector< vector<int> > moeglicheEintraegeErmitteln(SudokuStruct sudoku, vector<Koordinaten> freieFelder) 
{
    vector< vector<int> > moeglicheEintraege;
    for (int i = 0; i < freieFelder.size(); i++)
    {
        moeglicheEintraege.push_back(moeglicheEintraegeErmittelnAlle(sudoku, freieFelder[i]));
    }		
    return moeglicheEintraege;
}


Unique findeUnique(Situation sit)
{
    Unique unikat;
    for (int i = 0; i < 9; i++)
    {
        vector<int> reihe;
        vector<int> spalte;
        for (int m = 0; m < sit.moeg.size(); m++)
        {
            if (sit.frei[m].kon[0] == i)
            {
                for (int j = 0; j < sit.moeg[m].size(); j++)
                {
                    reihe.push_back(sit.moeg[m][j]);                    
                }
            }
            if (sit.frei[m].kon[1] == i)
            {
                for (int j = 0; j < sit.moeg[m].size(); j++)
                {
                    spalte.push_back(sit.moeg[m][j]);                    
                }
            }
        }  
        int rr[10] {};
        for (int r = 0; r < reihe.size(); r++)
        {
            rr[reihe[r]]++;
        }
        for (int r = 0; r < 10; r++)
        {
            if (rr[r] == 1) 
            {
                for (int m = 0; m < sit.moeg.size(); m++)
                {
                    if (sit.frei[m].kon[0] == i)
                    {
                        for (int j = 0; j < sit.moeg[m].size(); j++)
                        {
                            if (sit.moeg[m][j] == r)
                            {
                                unikat.gefunden = true;
                                unikat.uni.frei.push_back(sit.frei[m]);
                                vector<int> eintrag;
                                eintrag.push_back(r);
                                unikat.uni.moeg.push_back(eintrag);
                                return unikat;
                            }                    
                        }
                    }                            
                }  
            }
        }
    }
    
    unikat.gefunden = false;
    return unikat;
}

// Ermitteln von freien Feldern und Eintragemoeglichkeiten fuer jedes Feld
// Uebergabe: aktuellen Spielstand (Sudoku)
// Rueckgabe: Struct mit einem Vektor fuer Koordinaten und einem Vektor fuer legale Eintragungen
Situation kombinierteFelderUndMoeglicheEintraege (SudokuStruct sudoku)
{
    Situation sit;
    sit.frei = freieFelderErmitteln(sudoku);
    sit.moeg = moeglicheEintraegeErmitteln(sudoku, sit.frei); 
    
    // einzigartiges finden
    Unique unikat = findeUnique(sit);
    if (unikat.gefunden == true)
    {
        sit = unikat.uni;
    }
    
    return sit; 
}


// Drucken des Spielstandes (Sudoku)
// Uebergabe: aktuellen Spielstand (Sudoku)
void drucken (SudokuStruct sudoku)
{
	printf("\n");
	for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
        	printf(" %d", sudoku.sud[i][j]);
        }
        printf("\n");
    }
}


// Pruefen, ob in jedem Feld eine Eintragung ungleich "0" vorhanden ist 
// Uebergabe: aktuellen Spielstand (Sudoku)
// Rueckgabe: bool: false -> Forsetzung; true -> Kaskade an Beendigungen der Funktion "recursionEintragung()" -> beendet Programm
bool fertig(SudokuStruct sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku.sud[i][j] == 0) {return false;}
        }
    }
    drucken(sudoku);
    return true;
	
}


// Pruefen auf "0" - Felder ohne Eintragemoeglichkeit
// Uebergabe: Liste an moeglichen Eintragungen (von "Situation" bereitgestellt)
// Rueckgabe: bool: true -> Abbruch dieser Rekursion; false -> Weiterfuehrung dieser Rekursion
bool falscherWeg(vector< vector<int> > moeg)
{
	for (int m = 0; m < moeg.size(); m++)
    {
    	if (moeg[m].size() == 0) {return true;}
	}
	return false;
}


// Rekursion, die Spielstand sichert und eine einzelne Eintragung vornimmt und ruecknimmt
// Uebergabe: aktuellen Spielstand (Sudoku)
// Rueckgabe: bool: false -> Rueckabwicklung der letzten Eintragung; true -> beenden des Programms
bool recursionEintragung(SudokuStruct sudoku) 
{
    if (fertig(sudoku) == true) {return true;}
    Situation sit = kombinierteFelderUndMoeglicheEintraege(sudoku);    
    if (falscherWeg(sit.moeg) == true) {return false;}
    
    for (int i = 1; i < 9; i++)
    {
        for (int m = 0; m < sit.moeg.size(); m++)
        {
            if (sit.moeg[m].size() == i)
            {
                for (int p = 0; p < i; p++)
                {
                    sudoku.sud[sit.frei[m].kon[0]][sit.frei[m].kon[1]] = sit.moeg[m][p];
                    if (recursionEintragung(sudoku) == true){return true;} 
                }
		sudoku.sud[sit.frei[m].kon[0]][sit.frei[m].kon[1]] = 0;	
            }
        }
    }
    printf(" fuck");
    return false;
}


// Initialfunktion
// Aufrufen der Rekursion
int main()
{    
    if (recursionEintragung(bekommeStartSudoku()) == true) {printf("Fin");} else {printf("Nope");}
    return 0;
}
