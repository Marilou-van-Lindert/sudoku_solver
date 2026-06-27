#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

const int sHeight = 9;
const int sWidth = 9;
const int nAmount = 9;


class Sudoku {
    private:
        int NotLegal = -1;
        int grid[sHeight][sWidth]={NotLegal};
        int candits[sHeight][sWidth][nAmount]={NotLegal};
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
        void PrintCelCandits ();
        void AskCell ();
        void TestNakedSingle ();

        Sudoku()
        {
            SudokuFile.open("sudoku.txt");
        }
};