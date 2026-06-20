//main sudoku solver file
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "solver.h"

using namespace std;

//function checks if file doesn't contain an imideat unsolvable sudoku
bool Sudoku::FileAllowed(){
    return true;
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
    SudokuFile.close();
}


bool Sudoku::NumberAllowed(int num, int row, int col){
    //checks if number is allowed in row
    for (int i = 0, i<sWidth; i++){
        if (grid[row][i]==num){
            cout << "number not allowed"<< endl;
            return false;
        }
    }

    //checks if number is allowed in column

    for (int i = 0; i<sHeight; i++){
        if (grid[i][col]==num){
            cout << "number not allowed" << endl;
            return false;
        }
    }

    //checks is number is allowed in 3x3 square
    //steps get into the square
    //write code to read the square
    




    return true;
}


//prints the current sudoku
void Sudoku::PrintSudoku(){
    cout << "_________________________" << endl;
    for (int i=0; i<sHeight; i++){
        
        for (int j = 0; j<sWidth; j++){
            if (j % 3 == 0){
                cout << "| ";
            }
            cout << grid[i][j]<<" ";
        }
        cout << "|" <<endl;
        if((i - 2) % 3 == 0){
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