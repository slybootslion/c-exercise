#include "head.h"

int get_file_lines(FILE *f) {
  if (f == NULL) return -1;
  char buf[1024];
  int c = 0;
  while (fgets(buf, 1024, f) != NULL)
    c++;
  fseek(f, 0, SEEK_SET);
  return c;
}

void read_file_data(FILE *f, char **p_array, int len) {
  if (f == NULL || p_array == NULL || len <= 0) {
    printf("参数有误");
    return;
  }

  char buf[1024] = {0};
  int idx = 0;
  while (fgets(buf, 1024, f) != NULL) {
    const unsigned long str_len = strlen(buf) + 1;
    buf[strlen(buf) - 1] = '\0';
//    printf("str len: %ld", str_len);
    char *str_cur = (char *) malloc(sizeof(char) * str_len);
    strcpy(str_cur, buf);
    p_array[idx++] = str_cur;
    memset(buf, 0, 1024);
  }
}

void show_file_data(char **p_array, int len) {
  for (int i = 0; i < len; ++i)
    printf("%d行的数据为：%s\n", i + 1, p_array[i]);
}

void free_space_malloc(char **p_array, int len) {
  for (int i = 0; i < len; ++i) {
    free(p_array[i]);
    p_array[i] = NULL;
  }

  free(p_array);
  p_array = NULL;
}

void high_point_file() {
  FILE *file = fopen("./file.txt", "r");
  if (file == NULL) {
    perror("[ERROR] file open failed.\n");
    return;
  }

  //  获取文件有效行数
  int line = get_file_lines(file);
  char **p_array = malloc(sizeof(char *) * line);
  read_file_data(file, p_array, line);
  show_file_data(p_array, line);
  free_space_malloc(p_array, line);
  p_array = NULL;
  fclose(file);
  file = NULL;
}
