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

//checks if sudoku is solved
bool Sudoku::Solved(){
    for (int i=0; i<sHeight; i++){
        for (int j=0; j<sWidth; j++){
            if(grid[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

//checks if number is legal
bool Sudoku::LegalNumber(int num){
    if (num < 1 || num > 9){
        return false;
    }
    return true;
}


//checks if row is legal
bool Sudoku::LegalRow(int num){
    if (num < 0 || num > sWidth){
        return false;
    }
    return true;
}

//checks if column is legal
bool Sudoku::LegalCol(int num){
    if (num < 0 || num > sHeight){
        return false;
    }
    return true;
}

//fills number into sudoku
void Sudoku::FillNumber(){
    AskNumber();
    if(NumberAllowed()){
        grid[ChosenRow][ChosenCol]=ChosenNumber;
        //sets value's back to NotLegal
        ChosenNumber = NotLegal;
        ChosenCol = NotLegal;
        ChosenRow = NotLegal;
    }

}


//function fills the grind from sudoku.txt file
void Sudoku::FillGrid (){
    //gets first character from document
    SudokuFile.get(number);
    //for each square fill it with a number
    for (int i=0; i<sHeight; i++){
        for (int j=0; j<sWidth; j++){
            //checks if number is a number
            if(number >= '0' && number <= '9'){
                grid[i][j]=number-'0';
            }
            //get the next character
            SudokuFile.get(number);
        }
    }
    //close the file
    SudokuFile.close();
}

//ask for number and checks if it is allowed
void Sudoku::AskNumber(){
    while (!LegalNumber(ChosenNumber)){
        cout << "what number do you want:  ";
        cin >> ChosenNumber; 
        cout << "you chose number: " << ChosenNumber << endl;
    }
    while (!LegalRow(ChosenRow)){
        cout << "what row do you want:  ";
        cin >> ChosenRow; 
        cout << "you chose row: " << ChosenRow << endl;
        ChosenRow--;
    }
    while (!LegalCol(ChosenCol)){
        cout << "what column do you want:  ";
        cin >> ChosenCol; 
        cout << "you chose column: " << ChosenCol << endl;
        ChosenCol--;
    }
}


//checks if number is allowed in the cage of the sudoku
bool Sudoku::NumberAllowed(){
    //checks if number is allowed in row
    for (int i = 0; i<sWidth; i++){
        if (grid[ChosenRow][i]==ChosenNumber){   
            cout << "number not allowed in row"<< endl;
            return false;
        }
    }

    //checks if number is allowed in column
    for (int i = 0; i<sHeight; i++){
        if (grid[i][ChosenCol]==ChosenNumber){
            cout << "number not allowed column" << endl;
            return false;
        }
    }

    //checks is number is allowed in 3x3 square
    //steps get into the square
    //write code to read the square
    
    int colStart = ChosenCol - ChosenCol%3;
    int rowStart = ChosenRow - ChosenRow%3;

    for (int i = 0; i<3;i++){
        for (int j= 0; j<3; j++){
            if(grid[rowStart+i][colStart+j]==ChosenNumber){
                cout << "number not allowed box" << endl;
                return false;
            }
        }
    }
    

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
    while (!test.Solved()){
        test.FillNumber();
        test.PrintSudoku();
    }
    return 0;
}