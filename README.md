Hey Gökce 
This is a short readme about how the program runs and execute.

This program simulates the Knight’s Tour problem on an N × N chessboard using a greedy algorithm.
A knight starts on a given square and repeatedly moves to the first available unvisited square (based on a fixed move order).
The tour ends when no further moves are possible.
The program calculates how many squares are visited for each possible starting square, displaying the results in a matrix.

# Features:
-----------
- Uses the greedy version of the Knight’s Tour.

- Uses modular structure with header and source files:

- knights_tour.h – constants, typedefs, and function prototypes

- knights_tour.c – function implementations

- main.c – entry point of the program

- Doxygen-style comments.

- #define SIZE.

# Example Output:
-----------------
For an 8×8 board:

Greedy:
|-------------------------|
| 36 37 43 49 36 35 48 42 |
| 54 43 35 36 42 48 35 34 |
| 36 29 54 42 34 35 41 47 |
| 42 28 35 28 54 41 33 34 |
| 45 35 41 27 26 27 46 40 |
| 40  8 44 44 40 26 33 32 |
| 10 54 46 54 55 31 39 54 |
| 42 37 35 55 36 32 35 32 | 
|-------------------------|
Each number shows how many squares were visited when the knight started from that square.

# How It Works:
---------------
- The knight starts from a chosen square.
- It marks the square as visited.
- It tries the 8 possible moves in a fixed order.
- If a move is valid and unvisited, the knight moves there.
- It repeats this process until no valid moves remain.
- The total number of visited squares is recorded.
- The algorithm does not backtrack, so it may not visit all squares.
