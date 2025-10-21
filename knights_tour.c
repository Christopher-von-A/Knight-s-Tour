/**
 * @file knights_tour.c
 * @brief Implementation of the greedy Knight's Tour.
 */

#include "knights_tour.h"

/* --- CONSTANTS ---------------------------------------------------------- */

/** @brief Knight’s possible X offsets for each move. */
const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};

/** @brief Knight’s possible Y offsets for each move. */
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

/* --- FUNCTION IMPLEMENTATIONS ------------------------------------------- */

bool move_is_possible(size_t move_id, size_t x, size_t y, board_t visited) {
  int nx = (int)x + MOVES_X[move_id];
  int ny = (int)y + MOVES_Y[move_id];

  // Check within board boundaries and if the square is unvisited
  return (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && visited[ny][nx] == 0);
}

/**
 * @brief Attempts a greedy tour from the given starting position.
 *
 * The algorithm:
 * 1. Marks the start square as visited.
 * 2. Tries moves in order (0–7) and picks the first available.
 * 3. Continues until no legal move exists.
 *
 * This method is greedy — it doesn’t backtrack or search for optimal tours.
 */
unsigned int tour_greedy(size_t start_x, size_t start_y) {
  board_t visited = {0};
  size_t x = start_x;
  size_t y = start_y;
  unsigned int moves = 1;

  visited[y][x] = moves; // Mark start square as visited

  bool moved;
  do {
    moved = false;

    // Try all possible knight moves
    for (size_t i = 0; i < MOVE_COUNT; i++) {
      if (move_is_possible(i, x, y, visited)) {
        // Move to the new square
        x += MOVES_X[i];
        y += MOVES_Y[i];
        visited[y][x] = ++moves;
        moved = true;
        break; // Stop after first valid move (greedy)
      }
    }
  } while (moved);

  return moves;
}

/**
 * @brief Runs greedy tours starting from every board square.
 *
 * The result is printed as an N×N grid of numbers,
 * where each cell shows how many squares the knight visited
 * when starting from that square.
 */
void greedy_tour_from_each_square(void) {
  unsigned int result[SIZE][SIZE];

  // Perform a tour starting from each square
  for (size_t y = 0; y < SIZE; y++) {
    for (size_t x = 0; x < SIZE; x++) {
      result[y][x] = tour_greedy(x, y);
    }
  }

  // Print the matrix
  printf("Greedy:\n");
  for (size_t y = 0; y < SIZE; y++) {
    for (size_t x = 0; x < SIZE; x++) {
      printf("%2u ", result[y][x]);
    }
    printf("\n");
  }
}
