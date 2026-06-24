#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

const int sHeight = 9;
const int sWidth = 9;


class Sudoku {
    private:
        int NotLegal = -1;
        int grid[sHeight][sWidth]={NotLegal};
        char number;
        ifstream SudokuFile;
    public:
        int ChosenNumber = NotLegal;
        int ChosenRow = NotLegal;
        int ChosenCol = NotLegal;   
        bool FileAllowed();
        void FillGrid();
        void PrintSudoku();
        bool NumberAllowed();
        void AskNumber();
        bool LegalNumber(int num);
        bool LegalRow(int num);
        bool LegalCol(int num);
        bool Solved();
        void FillNumber();

        Sudoku()
        {
            SudokuFile.open("sudoku.txt");
        }
};