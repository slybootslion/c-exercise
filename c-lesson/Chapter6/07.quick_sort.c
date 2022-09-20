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

int Partition(int array[], int low, int high) {
  int pivot = array[high];
  int partition = low;
  for (int i = low; i < high; ++i) {
    if (array[i] < pivot)
      SwapElements(array, i, partition++);
  }
  SwapElements(array, partition, high);
  return partition;
}

void QuickSort(int array[], int low, int high) {
  if (low >= high) return;
  int partition = Partition(array, low, high);
  QuickSort(array, low, partition - 1);
  QuickSort(array, partition + 1, high);
}

int main() {
  int player[PLAYER_COUNT];
  for (int i = 0; i < PLAYER_COUNT; ++i)
    player[i] = i;

  PRINT_INT_ARRAY(player, PLAYER_COUNT);
  ShuffleArray(player, PLAYER_COUNT);
  PRINT_INT_ARRAY(player, PLAYER_COUNT);

  QuickSort(player, 0, PLAYER_COUNT - 1);
  PRINT_INT_ARRAY(player, PLAYER_COUNT);

  return 0;
}
