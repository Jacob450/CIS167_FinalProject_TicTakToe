# Unbeatable Tic-Tac-Toe

A console-based Tic-Tac-Toe game written in **C++** featuring an unbeatable computer opponent powered by the **Minimax algorithm**.

## Overview

This project is a command-line implementation of Tic-Tac-Toe where the player competes against a computer-controlled opponent.

The computer uses the **Minimax algorithm** to evaluate possible moves and select the optimal move for every position. Because Tic-Tac-Toe is a solved game, the algorithm allows the computer to play perfectly, meaning the player cannot defeat it when it plays optimally.

The project was built to strengthen my understanding of **C++ programming, recursion, game-state evaluation, and decision-making algorithms**.

## Features

* 🎮 Player vs. computer gameplay
* 🤖 Unbeatable AI opponent
* 🧠 Minimax algorithm for optimal move selection
* 💻 Runs entirely in the console
* 🔄 Dynamic board and game-state evaluation
* 🏆 Detects wins, losses, and draws
* ⌨️ User-controlled move selection

## Technologies

* **C++**
* Standard C++ libraries
* Minimax algorithm
* Recursion

## How It Works

The computer determines its move using the **Minimax algorithm**.

For each available move, the AI:

1. Simulates the possible move.
2. Checks whether the resulting game state is a win, loss, or draw.
3. Recursively evaluates the possible moves that could follow.
4. Assigns a score to each possible outcome.
5. Selects the move that produces the best possible outcome.

The AI attempts to **maximize** its score while assuming that the player will make decisions that **minimize** the AI's score.

This allows the computer to anticipate the player's possible responses and select an optimal move.

## Example

```text
   1   2   3
1  X | O | X
  ---+---+---
2  O | X | 
  ---+---+---
3    |   | O

Computer's move: 3,1
```

The game evaluates the available moves and chooses the move that leads to the strongest possible outcome.

## What I Learned

This project helped me develop a deeper understanding of:

* Recursion
* Algorithm design
* Game-state evaluation
* Decision trees
* C++ control flow and data structures
* Breaking a larger problem into smaller states
* Evaluating multiple possible outcomes
* Implementing an AI decision-making system

## Purpose

This project was created as a learning exercise to explore **algorithmic decision-making and AI concepts in C++** while building a complete playable application.

## Author

Jacob Perez

