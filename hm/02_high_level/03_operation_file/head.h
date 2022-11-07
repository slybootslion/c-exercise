//
// Created by SlybootsLion on 2022/11/2.
//

#ifndef INC_03_OPERATION_FILE__HEAD_H_
#define INC_03_OPERATION_FILE__HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct config_info {
  char key[64];
  char value[64];
} cf_t;

extern int get_file_line(char *filepath);
extern void parse_file(char *filepath, int lines, cf_t **config_info);
extern char *get_info_by_key(char *key, int line, cf_t *config_info);
extern void free_space(cf_t *config_info);
extern void code_file(char *source_file, char *dest_file);
extern void decode_file(char *source_file, char *dest_file);
#endif //INC_03_OPERATION_FILE__HEAD_H_
