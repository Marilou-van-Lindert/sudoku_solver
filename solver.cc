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

void Sudoku::menu(){
    int choice = 0;
    cout << "welcome to the sudoku solver, you can upload sudoku's and solve them yourself";
    cout << "\n Or you can let the program solve them"<< endl;
    cout << "press 1 for auto solve and 2 for manual solve" << endl;
    cin >> choice;
    switch (choice){
        case 1:
            man = false;
        break;
        case 2:
            man = true;
        break;
    }
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
void Sudoku::ManFillNumber(){
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




void Sudoku::InitiateCadits(){
    for (int i =0; i<sHeight; i++){
        for (int j = 0; j<sWidth; j++){
            for (int k = 0; k<nAmount; k++){
                if (grid[i][j]==0){
                    ChosenNumber = k+1;
                    ChosenRow = i;
                    ChosenCol = j;
                    if(NumberAllowed()){
                        candits[i][j][k]=k+1;
                    }else{
                        candits[i][j][k]=0;
                    }
                }else{
                    candits[i][j][k]=0;
                }
            }
        }
    }
}




//ask for number and checks if it is allowed
void Sudoku::AskNumber(){
    while (!LegalNumber(ChosenNumber)){
        cout << "what number do you want:  ";
        cin >> ChosenNumber; 
        cout << "you chose number: " << ChosenNumber << endl;
    }
    AskCell();
}




//checks if number is allowed in the cage of the sudoku
bool Sudoku::NumberAllowed(){
    //checks if number is allowed in row
    for (int i = 0; i<sWidth; i++){
        if (grid[ChosenRow][i]==ChosenNumber){   
            if (man){
                cout << "number not allowed in row"<< endl;
            }
            return false;
        }
    }

    //checks if number is allowed in column
    for (int i = 0; i<sHeight; i++){
        if (grid[i][ChosenCol]==ChosenNumber){
            if (man){
                cout << "number not allowed column" << endl;
            }
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
                if (man){
                    cout << "number not allowed box" << endl;
                }
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
            cout << grid[i][j] << " ";
        }
        cout << "|" << endl;
        if((i - 2) % 3 == 0){
            cout << "_________________________" << endl;
        }
    }
}

//prints the current sudoku
void Sudoku::PrintCandits(){
    for (int k =0; k<nAmount; k++){
        cout << "_________________________" << endl;
        for (int i=0; i<sHeight; i++){
            
            for (int j = 0; j<sWidth; j++){
                if (j % 3 == 0){
                    cout << "| ";
                }
                cout << candits[i][j][k] << " ";
            }
            cout << "|" << endl;
            if((i - 2) % 3 == 0){
                cout << "_________________________" << endl;
            }
        }
    }

}

void Sudoku::AskCell (){
    ChosenRow = NotLegal;
    ChosenCol = NotLegal;
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


void Sudoku::PrintCelCandits (){
    AskCell();
    for (int i =0; i<nAmount;i++){
        if (candits[ChosenRow][ChosenCol][i]!=0){
            cout << candits[ChosenRow][ChosenCol][i] << " ";
        }
    }
    cout << endl;
}


void Sudoku::TestNakedSingle (){
    int cAmount = 0;
    int lastCandit = 0;
    for (int i = 0; i<sHeight;i++){
        for (int j = 0; j<sWidth;j++){
            for (int k = 0; k<nAmount;k++){
                if(candits[i][j][k]!=0){
                    cAmount++;
                    lastCandit = candits[i][j][k];
                }
            }
            if (cAmount == 1 && lastCandit != 0){
                grid[i][j]=lastCandit;
            }
            cAmount = 0;
            lastCandit = 0;
        }
    }
    InitiateCadits ();
}


int main (){
    Sudoku test;
    test.menu ();
    test.FillGrid ();
    test.InitiateCadits ();
    test.PrintSudoku ();
    test.TestNakedSingle ();
    test.PrintSudoku ();
    // test.PrintCandits ();
    //test.PrintCelCandits ();
    while (!test.Solved ()){
        test.TestNakedSingle ();
        test.PrintSudoku ();
    }
    return 0;
}