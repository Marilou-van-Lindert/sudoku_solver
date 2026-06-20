#include <stdio.h>
#include <fstream>
using namespace std;

int Sheight = 9;
int sWidth = 9;
string FilePath = "sudoku.txt";
ifstream SudokuFile(FilePath);

int sudoku[9][9];
char number;
