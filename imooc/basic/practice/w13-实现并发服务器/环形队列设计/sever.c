#include <string.h>
#include "shm.h"
#include "shmfifo.h"

typedef struct person {
  int age;
  char name[32];
} person_t;

int main() {
  person_t person;
  shm_fifo_t *fifo = shmfifo_init(3, sizeof(person));
  for (;;) {
    shmfifo_get(fifo, &person);
    printf("name = %s, age = %d\n", person.name, person.age);
  }
  return 0;
}
