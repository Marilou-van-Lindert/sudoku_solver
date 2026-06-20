//main sudoku solver file
#include <iostream>
#include <stdio.h>
#include "solver.h"

using namespace std;


void MakeSudoku (){
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            sudoku[i][j]=j+1;
        };
    };
};

void PrintSudoku(){
    cout << "_________________________" << endl;
    for (int i=0; i<9; i++){
        
        for (int j=0; j<9; j++){
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
    return 0;
};