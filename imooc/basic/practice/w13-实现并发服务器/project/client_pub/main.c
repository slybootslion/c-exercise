#include "client.h"

int main() {
  client_init();
  publish("hello", "ABCDEFG");
//  subscribe("hello");
  return 0;
}
