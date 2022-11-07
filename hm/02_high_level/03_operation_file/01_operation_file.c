#include "head.h"

int isValidLine(char *str) {
  if (str[0] == ' ' || str[0] == '\0' || strchr(str, ':') == NULL)
    return 0;
  return -1;
}

int get_file_line(char *filepath) {
  FILE *file = fopen(filepath, "r");
  if (file == NULL)
    return -1;

  char buf[1024] = {0};
  int line = 0;
  while (fgets(buf, 1024, file) != NULL)
    if (isValidLine(buf)) line++;

  fclose(file);

  return line;
}

void parse_file(char *filepath, int lines, cf_t **config_info) {
  cf_t *temp = malloc(sizeof(cf_t) * lines);
  FILE *file = fopen(filepath, "r");
  char buf[1024] = {0};
  int idx = 0;
  while (fgets(buf, 1024, file) != NULL) {
    if (isValidLine(buf)) {
      memset(temp[idx].key, 0, 64);
      memset(temp[idx].value, 0, 64);

      char *pos = strchr(buf, ':'); //冒号所在位置

      strncpy(temp[idx].key, buf, pos - buf);
      strncpy(temp[idx].value, pos + 1, strlen(pos + 1) - 1);
      idx++;
    }
    memset(buf, 0, 1024);
  }
  fclose(file);
  *config_info = temp;
}

char *get_info_by_key(char *key, int line, cf_t *config_info) {
  for (int i = 0; i < line; ++i) {
    if (strcmp(key, config_info[i].key) == 0)
      return config_info[i].value;
  }
  return NULL;
}

void free_space(cf_t *config_info) {
  if (config_info != NULL) {
    free(config_info);
    config_info = NULL;
  }
}
