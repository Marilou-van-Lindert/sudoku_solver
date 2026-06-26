#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

const int sHeight = 9;
const int sWidth = 9;
const int amount = 9;


class Sudoku {
    private:
        int NotLegal = -1;
        int grid[sHeight][sWidth]={NotLegal};
        int candits[sHeight][sWidth][amount]={NotLegal};
        char number;
        bool man = false;
        ifstream SudokuFile;
    public:
        int ChosenNumber = NotLegal;
        int ChosenRow = NotLegal;
        int ChosenCol = NotLegal;
        void menu ();
        bool FileAllowed ();
        void FillGrid ();
        void PrintSudoku ();
        bool NumberAllowed ();
        void AskNumber ();
        bool LegalNumber (int num);
        bool LegalRow (int num);
        bool LegalCol (int num);
        bool Solved ();
        void ManFillNumber ();

        void InitiateCadits ();
        void PrintCandits ();

        Sudoku()
        {
            SudokuFile.open("sudoku.txt");
        }
};