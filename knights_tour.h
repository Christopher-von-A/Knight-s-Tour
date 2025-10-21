/**
 * @file knights_tour.h
 * @brief Header file for the greedy Knight's Tour implementation.
 *
 * This module defines constants, type aliases, and function prototypes
 * used to perform a greedy Knight’s Tour on an N×N chessboard.
 *
 * The greedy approach moves the knight to the *first available*
 * unvisited square (in a fixed order of moves) until no further moves
 * are possible.
 */

#ifndef KNIGHTS_TOUR_H
#define KNIGHTS_TOUR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/**
 * @def SIZE
 * @brief Board size (modifiable compile-time constant).
 *
 * The board is SIZE × SIZE. Default is 8 (standard chessboard),
 * but other values are also supported.
 */
#define SIZE 8

/**
 * @def MOVE_COUNT
 * @brief Number of possible knight moves.
 */
#define MOVE_COUNT 8

/**
 * @brief Knight move offsets in X and Y directions.
 *
 * Each pair (MOVES_X[i], MOVES_Y[i]) represents one legal knight move.
 * For example, using move 0:
 * `x += MOVES_X[0]; y += MOVES_Y[0];`
 */
extern const int MOVES_X[MOVE_COUNT];
extern const int MOVES_Y[MOVE_COUNT];

/**
 * @typedef board_t
 * @brief Type alias for a 2D integer array representing the chessboard.
 *
 * - A value of 0 means unvisited.
 * - A positive value means the square was visited and stores the step number.
 */
typedef int board_t[SIZE][SIZE];

/**
 * @brief Checks whether a move is possible from the given position.
 *
 * @param move_id Index of the move (0–7)
 * @param x Current X position
 * @param y Current Y position
 * @param visited The chessboard array marking visited squares
 * @return `true` if the move is inside bounds and unvisited, otherwise `false`
 */
bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited);

/**
 * @brief Performs a greedy knight’s tour starting from a given square.
 *
 * The knight always moves to the first available square (in MOVES_X/Y order)
 * and stops when no valid move remains.
 *
 * @param start_x Starting horizontal coordinate
 * @param start_y Starting vertical coordinate
 * @return Number of squares visited during the tour
 */
unsigned int tour_greedy(size_t start_x, size_t start_y);

/**
 * @brief Executes greedy tours starting from all squares on the board.
 *
 * Prints a matrix of the number of visited squares per starting square:
 *
 * ```
 * Greedy:
 * 36 37 43 49 36 35 48 42
 * ...
 * ```
 */
void greedy_tour_from_each_square(void);

#endif // KNIGHTS_TOUR_H
