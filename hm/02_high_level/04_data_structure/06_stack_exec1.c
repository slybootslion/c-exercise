#include "head.h"
#include "./lib_sequence_stack/lib_sequence_stack.h"

int is_left(char ch) {
  return ch == '(';
}

int is_right(char ch) {
  return ch == ')';
}

void print_error(char *str, char *error_msg, char *pos) {
  printf("[error]: %s\n", error_msg);
  printf("%s\n", str);
  long count = pos - str;
  for (int i = 0; i < count; ++i)
    putchar(' ');
  printf("↑\n");
}

void exec1() {
  //  char *str = "5+5*(6)+9/3*1)-(1+3(";
//  char *str = "5+5*(6)+9/3*1-(1+3(";
  char *str = "5+5*(6)+9/3*1-1+3";
  char *p = str;
  seq_stack *stack = init_sequence_stack();
  while (*p != '\0') {
    if (is_left(*p))
      push_sequence_stack(stack, p);
    if (is_right(*p)) {
      if (size_sequence_stack(stack) > 0) {
        pop_sequence_stack(stack);
      } else {
        print_error(str, "右括号没有匹配对应的左括号", p);
        exit(EXIT_FAILURE);
      }
    }
    p++;
  }

  while (size_sequence_stack(stack) > 0) {
    print_error(str, "左括号没有匹配到对应的右括号", top_sequence_stack(stack));
    pop_sequence_stack(stack);
  }

  destroy_sequence_stack(stack);
  stack = NULL;
}

void stack_exec() {
  exec1();
}
