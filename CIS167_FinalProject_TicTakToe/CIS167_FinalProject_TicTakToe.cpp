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
struct BestMove {
    int x;
    int y;

};

struct aiBestMove {
    int x;
    int y;
};
aiBestMove aibm;
BestMove bm;
void showBoard(string b[3][3]);
void playerTurn(string b[3][3]);
int checkGameState(string b[3][3]);
void aiTurnRand(string b[3][3]);
void miniMaxStart(string b[3][3]);
void aiTurn(string b[3][3], int r, int c);
int miniMax(string b[3][3], int depth, bool maximizing);
void copyArray(string c[3][3], string b[3][3]);
string belowme;
bool gameOver;

int main()
{
    belowme = "-";
    pos.x = 0;
    pos.y = 0;
    

    string board[3][3] = { "-", "-", "-",
                            "-", "-", "-",
                            "-", "-", "-", };
   
    showBoard(board);

    while (checkGameState(board) == 999) {
        
        playerTurn(board);
        
       
        
        miniMaxStart(board);

        aiTurn(board, bm.y, bm.x);
        
       
        
    }
   showBoard(board);
   if (checkGameState(board) == -1) { cout << "You lost"; }
   if (checkGameState(board) == 0) { cout << "The game is tied"; }
   //This will never happen
   if (checkGameState(board) == 1) { cout << "you won"; }

    
    
}
void copyArray(string c[3][3], string b[3][3]) {

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            c[row][col] = b[row][col];
        }
    }

}

void aiTurn(string b[3][3],int r,int c) {
    b[r][c] = 'o';
}

void miniMaxStart(string b[3][3]) {
    int row, col;
    int bestscore = INT32_MIN;
    string copy[3][3];
    copyArray(copy, b);
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (copy[row][col] == "-") {

                int score = miniMax(copy, 0, false);
                
                cout << "optimal Move is: " << bm.y << bm.x << " for ai\n";
                cout << "optimal Move is: " << aibm.y << aibm.x << " for player\n";

            }
        }
    }
}

int miniMax(string b[3][3], int depth, bool maximizing) {
    cout << "Enter mini max depth" << depth << endl;
    //if game over stop the loop
    //showBoard(b);
    cout << "optimal Move is: " << bm.y << bm.x << " for player\n";
    cout << "optimal Move is: " << aibm.y << aibm.x << " for ai\n";
    cout << "\nThe game state is: " << checkGameState(b) << "\n" << "depth" << depth << endl;
    cout << "click anykey to continue\n";
    //char stop = _getch();
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
                    b[row][col] = "x";

                    string copy[3][3];
                    copyArray(copy, b);

                    int score = miniMax(copy, depth + 1, false);

                    if (score > bestscore) {
                        bestscore = score;
                        bm.y = row;
                        bm.x = col;
                        cout << "optimal for Player move changed to " << bm.y << bm.x << " at depth " << depth << endl;
                        cout << "bestscore: " << bestscore << endl;
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
                    b[row][col] = "o";

                    string copy[3][3];
                    copyArray(copy, b);

                    int score = miniMax(copy, depth + 1, true);

                    if (score < bestscore) {
                        bestscore = score;
                        aibm.y = row;
                        aibm.x = col;
                        cout << "optimal for AI move changed to " << aibm.y << aibm.x << " at depth " << depth << endl;
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
            return 1;
        }
        if (b[0][i] == "o" && b[1][i] == "o" && b[2][i] == "o") {
            //cout << "\nThe AI has won!";
            return -1;
        }

        //checks for all horizontal winstates
        if (b[i][0] == "x" && b[i][1] == "x" && b[i][2] == "x") {
            //cout << "\nPlayer Wins!\n";
            return 1;
        }
        if (b[i][0] == "o" && b[i][1] == "o" && b[i][2] == "o") {
            //cout << "\nThe AI has won!";
            return -1;
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
        return 0;
    }

    return 999;
}

void aiTurnRand(string b[3][3]) {
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    uniform_int_distribution<> distr(0, 2); // define the range

    int x = distr(gen);
    int y = distr(gen);

    if (b[y][x] != "-") {
        aiTurnRand(b);
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
