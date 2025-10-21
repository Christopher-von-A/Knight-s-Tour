/**
 * @file main.c
 * @brief Entry point for the Greedy Knight’s Tour program.
 *
 * Calls the function that runs tours from every square on the board.
 */

#include "knights_tour.h"

/**
 * @brief Main program entry point.
 *
 * Runs the greedy knight’s tour visualization for the board.
 *
 * @return 0 on successful execution
 */
int main(void) {
  greedy_tour_from_each_square();
  return 0;
}
