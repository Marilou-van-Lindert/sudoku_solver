//main sudoku solver file
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "solver.h"

using namespace std;


void MakeSudoku (){
    for (int i=0; i<Sheight; i++){
        for (int j=0; j<sWidth; j++){
            sudoku[i][j]=j+1;
        };
    };
};


void FillSudoku (){
    SudokuFile.get(number);
    for (int i=0; i<Sheight; i++){
        for (int j=0; j<sWidth; j++){
            sudoku[i][j]=number-'0';
            SudokuFile.get(number);
        };
    };
};




void PrintSudoku(){
    cout << "_________________________" << endl;
    for (int i=0; i<Sheight; i++){
        
        for (int j=0; j<sWidth; j++){
            if (j % 3 == 0){
                cout <<"| ";
            }
            cout << sudoku[i][j]<<" ";
        };
        cout << "|" <<endl;
        if((i-2)%3 ==0){
            cout << "_________________________" << endl;
        }
    };
};

int main (){
    MakeSudoku();
    PrintSudoku();
    FillSudoku();
    PrintSudoku();
    return 0;
};