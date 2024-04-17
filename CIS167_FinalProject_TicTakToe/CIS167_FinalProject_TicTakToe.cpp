// CIS167_FinalProject_TicTakToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include <conio.h>
#include <cwchar>
#include <Windows.h>
#include <random>
#include <array>
using namespace std;
//hello
struct Position{
    int x;
    int y;
};
Position pos;


int getTurn();
void showBoard(string b[3][3]);
void playerTurn(string b[3][3]);
int checkGameState(string b[3][3]);
int aiTurnRand();
void miniMaxStart(string b[3][3]);
void aiTurn(string b[3][3], int r, int c);
int miniMax(string b[3][3], int depth, bool maximizing);

string belowme;
bool gameOver;

int main()
{
    belowme = "-";
    pos.x = 1;
    pos.y = 1;
    //1 is player turn
    //2 is ai turn
    //3 is random
    int turn;
    
    turn = getTurn();


    string board[3][3] = { "-", "-", "-",
                            "-", "-", "-",
                            "-", "-", "-", };
   


    showBoard(board);
    //Game loop if the players turn is first
    while (checkGameState(board) == 999 && turn == 1) {       
        playerTurn(board);             
        if (checkGameState(board) == 999) {
            miniMaxStart(board);
        }                         
    }

    //Game loop if ai goes first 
    while (checkGameState(board) == 999 && turn == 2) {

        
           miniMaxStart(board);
           if (checkGameState(board) == 999) {
               playerTurn(board);
           }
    }


   //End Game checks
   showBoard(board);
   if (checkGameState(board) == 1) { cout << "You lost"; }
   if (checkGameState(board) == 0) { cout << "The game is tied"; }
   //This should never happen
   if (checkGameState(board) == -1) { cout << "you won"; }

   //ask to play again
   cout << "\n Enter Y ot y to play again otherwise hit any key to continue\n";
   char playAgain = _getch();
   if (playAgain == 'Y' || playAgain == 'y') {
       system("cls");
       main();
   }
    
    
}
int getTurn() {
    cout << "Welome to Tic Tac Toe!\nWho should make the  first move?\n==============================\n";
    cout << "1 - player goes first\n2 - AI goes first\n3 - Random\n";
    int turn = 9;

    while (turn != 1 && turn != 2 && turn != 3) {

        cin >> turn;
        cout << "Invalid input try again\n";
    }
    if (turn == 3) {
        turn = aiTurnRand();
        return turn;
    }
    return turn;
}

void aiTurn(string b[3][3],int r,int c) {

    b[r][c] = 'o';
    showBoard(b);
    Sleep(250);
}

void miniMaxStart(string b[3][3]) {
    int row, col;
    int bestR;
    int bestC;
    int bestscore = INT32_MIN;
  
    
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (b[row][col] == "-") {
                b[row][col] = "o";
                int score = miniMax(b, 0, false);
                b[row][col] = "-";
               
                if (score > bestscore) {
                    bestscore = score;
                    bestR = row;
                    bestC = col;
                   
                }
            }
        }
    }
    
    aiTurn(b, bestR, bestC);
    
}

int miniMax(string b[3][3], int depth, bool maximizing) {
    
    if (checkGameState(b) != 999) {
        return checkGameState(b);
    }

    int row, col;


    //aiturn
    if (maximizing) {
        int bestscore = INT32_MIN;

        for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
                //determine if spot is open
                if (b[row][col] == "-") {
                    b[row][col] = "o";
                   
                    int score = miniMax(b, depth + 1, false);
                    b[row][col] = "-";
                    if (score > bestscore) {
                        bestscore = score;
                       
                        
                    }

                }

            }

        }
        return bestscore;


    }
    else {//player turn

        int bestscore = INT32_MAX;
        for (row = 0; row < 3; row++) {
            for (col = 0; col < 3; col++) {
                //determine if spot is open
                if (b[row][col] == "-") {
                    b[row][col] = "x";

                    int score = miniMax(b, depth + 1, true);
                    b[row][col] = "-";

                    if (score < bestscore) {
                        bestscore = score;
                                              
                    }

                }


            }

        }
        return bestscore;

    }
}


int checkGameState(string b[3][3]) {
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
        if (b[0][i] == "x" && b[1][i] == "x" && b[2][i] == "x") {
            //cout << "\nPlayer wins!\n";
            return -1;
        }
        if (b[0][i] == "o" && b[1][i] == "o" && b[2][i] == "o") {
            //cout << "\nThe AI has won!";
            return 1;
        }

        //checks for all horizontal winstates
        if (b[i][0] == "x" && b[i][1] == "x" && b[i][2] == "x") {
            //cout << "\nPlayer Wins!\n";
            return -1;
        }
        if (b[i][0] == "o" && b[i][1] == "o" && b[i][2] == "o") {
            //cout << "\nThe AI has won!";
            return 1;
        }
    }
    //checks for slanted winstates
    if (b[0][0] == "x" && b[1][1] == "x" && b[2][2] == "x") {  return -1; }
    if (b[0][0] == "o" && b[1][1] == "o" && b[2][2] == "o") {  return 1; }
    if (b[2][0] == "x" && b[1][1] == "x" && b[0][2] == "x") {  return -1; }
    if (b[2][0] == "o" && b[1][1] == "o" && b[0][2] == "o") {  return 1; }

    // If none of the the other win conditions have been met
    // and there are no empty spaces the game is tied
    if (!emptySpace) {
        
        return 0;
    }

    return 999;
}

int aiTurnRand() {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 2); // define the range

    int x = distr(gen);
   

    return x;
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
    cout << "\n=============\n";
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
