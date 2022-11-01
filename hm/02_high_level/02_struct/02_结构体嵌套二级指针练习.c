#include "head.h"

typedef struct Teacher {
  char name[64];
  char **students;
} teacher_t;

void create_teacher(teacher_t **teacher, int n, int m) {
  teacher_t *teacher_arr = (teacher_t *) malloc(sizeof(teacher_t) * n);
  for (int i = 0; i < n; ++i) {
    sprintf(teacher_arr[i].name, "老师_%d", i + 1);
    teacher_arr[i].students = (char **) malloc(sizeof(char *) * m);
    for (int j = 0; j < m; ++j) {
      teacher_arr[i].students[j] = malloc(64);
      sprintf(teacher_arr[i].students[j], "%s_学生_%d", teacher_arr[i].name, j + 1);
    }
  }
  *teacher = teacher_arr;
}

void print_teacher(teacher_t *teacher, int n, int m) {
  for (int i = 0; i < n; ++i) {
    printf("%s: \n", teacher->name);
    for (int j = 0; j < m; ++j) {
      printf("  %s\n", teacher->students[j]);
    }
  }
}

void free_space_2(teacher_t **teacher, int n, int m) {
  teacher_t *temp = *teacher;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      free(temp[i].students[j]);
      temp[i].students[j] = NULL;
    }
    free(temp[i].students);
    temp[i].students = NULL;
  }
  free(temp);
  temp = NULL;
}

void exec02() {
  teacher_t *teacher = NULL;
  int n = 2, m = 3;
  create_teacher(&teacher, n, m);
  print_teacher(teacher, n, m);
  free_space_2(&teacher, n, m);
}
