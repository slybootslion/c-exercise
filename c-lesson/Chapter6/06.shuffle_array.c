//
// Created by SlybootsLion on 2022/9/19.
//
#include "include/io_utils.h"
#include <stdlib.h>
#include <time.h>

#define PLAYER_COUNT 50

void SwapElements(int array[], int first, int second) {
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

void ShuffleArray(int array[], int length) {
  srand(time(NULL));
  for (int i = length - 1; i > 0; --i) {
    int random_num = rand() % i;
    SwapElements(array, i, random_num);
  }
}

int main() {
  int player[PLAYER_COUNT];
  for (int i = 0; i < PLAYER_COUNT; ++i) {
    player[i] = i;
  }
  PRINT_INT_ARRAY(player, PLAYER_COUNT);
  putchar('\n');
  ShuffleArray(player, PLAYER_COUNT);
  PRINT_INT_ARRAY(player, PLAYER_COUNT);
  putchar('\n');

  return 0;
}
