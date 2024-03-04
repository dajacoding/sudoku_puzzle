# include <stdio.h>
# include <stdbool.h>

struct SudokuStruct {
    int sud[9][9];
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

