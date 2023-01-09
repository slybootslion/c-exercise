#include "client.h"

int main() {
  client_init();
//  publish("hello", "ABCDEFG");
  subscribe("hello");
  while (1) {}
  return 0;
}
