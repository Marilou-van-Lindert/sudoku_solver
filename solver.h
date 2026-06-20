#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

const int sHeight = 9;
const int sWidth = 9;

class Sudoku {
    private:
        int grid[sHeight][sWidth]={-1};
        char number;
        ifstream SudokuFile;
    public:
        bool FileAllowed();
        void FillGrid();
        void PrintSudoku();
        bool NumberAllowed();
        Sudoku()
        {
            SudokuFile.open("sudoku.txt");
        }
};