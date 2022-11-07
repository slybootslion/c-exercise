#include "head.h"

int main() {
  char *filepath = "./config.txt";
  int line = get_file_line(filepath);
  if (line < 0) {
    perror("file error");
    exit(EXIT_FAILURE);
  }

  printf("number of valid lines in the file = %d\n", line);

  cf_t *config_info = NULL;
  parse_file(filepath, line, &config_info);

  printf("hero id = %s\n", get_info_by_key("heroId", line, config_info));
  printf("hero name = %s\n", get_info_by_key("heroName", line, config_info));
  printf("hero atk = %s\n", get_info_by_key("heroAtk", line, config_info));
  printf("hero def = %s\n", get_info_by_key("heroDef", line, config_info));
  printf("hero info = %s\n", get_info_by_key("heroInfo", line, config_info));

  free_space(config_info);
  config_info = NULL;

  code_file("./config.txt", "./加密文件.txt");
  decode_file("./加密文件.txt", "./解密文件.txt");
  return 0;
}
