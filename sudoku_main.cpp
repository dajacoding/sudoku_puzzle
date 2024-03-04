# include <stdio.h>
# include <stdbool.h>
# include "sudoku_kontrolle.cpp"

using namespace sk;

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

bool recursionEintragung(SudokuStruct sudoku) 
{
    SudokuStruct temp = kopieren(sudoku);
    sudoku.sud[0][0] = 5;
    printf("%d", sudoku.sud[0][0]);
    sudoku = temp;
    printf("%d", sudoku.sud[0][0]);
    return true;
}

int main()
{         
    SudokuStruct sudokuStart = bekommeStartSudoku();
    if (recursionEintragung(sudokuStart) == true) {printf("Fin");}
    return 0;
}

// def zeichneSudoku(sudoku):
//     if len(freieFelderErmitteln(sudoku)) == 0: 
//         for r, reihe in enumerate(sudoku):
//             print(str(reihe[0])+' '+str(reihe[1])+' '+str(reihe[2])+' | '+str(reihe[3])+' '+str(reihe[4])+' '+str(reihe[5])+' | '+str(reihe[6])+' '+str(reihe[7])+' '+str(reihe[8]))
//             if (r + 1) % 3 == 0 and (r + 1) != 9:
//                 print('------ ------- ------')
//         print()
//         return True  
//     return False  