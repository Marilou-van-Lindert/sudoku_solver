//main sudoku solver file
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "solver.h"

using namespace std;

//function checks if file doesn't contain an imideat unsolvable sudoku
bool Sudoku::FileAllowed(){

}


//function fills the grind from sudoku.txt file
void Sudoku::FillGrid (){
    SudokuFile.get(number);
    for (int i=0; i<sHeight; i++){
        for (int j=0; j<sWidth; j++){
            grid[i][j]=number-'0';
            SudokuFile.get(number);
        }
    }
}


//prints the current sudoku
void Sudoku::PrintSudoku(){
    cout << "_________________________" << endl;
    for (int i=0; i<sHeight; i++){
        
        for (int j=0; j<sWidth; j++){
            if (j % 3 == 0){
                cout <<"| ";
            }
            cout << grid[i][j]<<" ";
        }
        cout << "|" <<endl;
        if((i-2)%3 ==0){
            cout << "_________________________" << endl;
        }
    }
}

int main (){
    Sudoku test;
    test.FillGrid();
    test.PrintSudoku();
    return 0;
}