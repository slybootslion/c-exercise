#include "client.h"

int main () {
  client_init();
  subscribe("hello");
  return 0;
}
