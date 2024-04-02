// CIS167_FinalProject_TicTakToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include <conio.h>
#include <cwchar>
#include <Windows.h>
#include <random>
using namespace std;
//hello
struct Position{
    int x;
    int y;
};
Position pos;
void showBoard(string b[3][3]);
void playerTurn(string b[3][3]);
bool checkGameState(string b[3][3]);
void aiTurn(string b[3][3]);
string belowme;

int main()
{
    belowme = "-";
    pos.x = 0;
    pos.y = 0;
    bool gameOver = false;

    string board[3][3] = { "-", "-", "-",
                            "-", "-", "-",
                            "-", "-", "-", };
   
    showBoard(board);

    while (!gameOver) {
        if (!gameOver) { playerTurn(board); }
        gameOver = checkGameState(board);
        if (!gameOver) { aiTurn(board); }
        gameOver = checkGameState(board);
        
    }
   showBoard(board);
   checkGameState(board);
    
    
}

bool checkGameState(string b[3][3]) {
    bool emptySpace = false;

      //checks for any empty spaces on the board
    for (int i = 0; i < 9 && !emptySpace; i++) {
        if (b[0][i] == "-") {
            emptySpace = true;
        }
        else {
            emptySpace = false;
        }

    }


    for (int i = 0; i < 3; i++) {
        //Checks for all vertical winstates
        if (b[0][i] == "x" && b[1][i] == "x" && b[2][i] == "x")  {
            cout << "\nYou won!\n";
            return true;          
        }
        if (b[0][i] == "o" && b[1][i] == "o" && b[2][i] == "o") {
            cout << "\nThe AI has won!";
            return true;
        }
          
        //checks for all horizontal winstates
        if (b[i][0] == "x" && b[i][1] == "x" && b[i][2] == "x") {
            cout << "\nYou won!\n";
            return true;          
        }
        if (b[i][0] == "o" && b[i][1] == "o" && b[i][2] == "o") {
            cout << "\nThe AI has won!";
            return true;
        }
    }
    //checks for slanted winstates
    if (b[0][0] == "x" && b[1][1] == "x" && b[2][2] == "x") { cout << "\nYou won!\n"; return true; }
    if (b[0][0] == "o" && b[1][1] == "o" && b[2][2] == "o") { cout << "\nThe AI has won!\n"; return true; }
    if (b[2][0] == "x" && b[1][1] == "x" && b[0][2] == "x") { cout << "\nYou won!\n"; return true; }
    if (b[2][0] == "o" && b[1][1] == "o" && b[0][2] == "o") { cout << "\nThe AI has won!\n"; return true; }

    // If none of the the other win conditions have been met
    // and there are no empty spaces the game is tied
    if (!emptySpace) {
        cout << "\nThe game is tied\n";
        return true;
    }

    return false;
}

void aiTurn(string b[3][3]) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(0, 2); // define the range

    int x = distr(gen);
    int y = distr(gen);

    if (b[y][x] != "-") {
        aiTurn(b);
    }
    else {
        b[y][x] = 'o';
    }
}

void playerTurn(string b[3][3]) {
    showBoard(b);
    cout << "\nx: "<< pos.x << "\nY: " << pos.y ;
    cout << "\nENTER YOUR MOVE!\n";
    
    
    char input = _getch();
    //If the user enters 'wasd' and the movement is not out of bounds
    if (input == 's' && (pos.y+1) < 3) {
        b[pos.y][pos.x] = belowme;
        pos.y++;
        belowme = b[pos.y][pos.x];
        b[pos.y][pos.x] = '*';
    }
    if (input == 'w' && (pos.y - 1) > -1) {
        b[pos.y][pos.x] = belowme;
        pos.y--;
        belowme = b[pos.y][pos.x];
        b[pos.y][pos.x] = '*';
    }
    if (input == 'd' && (pos.x + 1) < 3) {
        b[pos.y][pos.x] = belowme;
        pos.x++;
        belowme = b[pos.y][pos.x];
        b[pos.y][pos.x] = '*';
    }
    if (input == 'a' && (pos.x - 1) > -1) {
        b[pos.y][pos.x] = belowme;
        pos.x--;
        belowme = b[pos.y][pos.x];
        b[pos.y][pos.x] = '*';
    }
    if (int(input) == 13 && belowme == "-") {
        b[pos.y][pos.x] = 'x';
        belowme = 'x';
    }
    else {
        playerTurn(b);
    }
  

    
    
}
void showBoard(string b[3][3]){
    system("cls");
    
    cout << "=============\n";
    for (int i = 0; i != 9; i++) {
        cout << b[0][i] <<  setw(2);
        if (i == 2 || i == 5){
            cout << "\n";
        }

    }
    cout << "\n=============";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
