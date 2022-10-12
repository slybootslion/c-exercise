//
// Created by SlybootsLion on 2022/10/12.
//

#ifndef PROJECT__CMD_HANDLE_H_
#define PROJECT__CMD_HANDLE_H_

#include <stdio.h>
#include <string.h>

#define SZ_NAME 8
#define SZ_ARG 32
#define SZ_COUNT 2

typedef struct command {
  char cmd_name[SZ_NAME]; // 命令名称
  char cmd_arg_list[SZ_COUNT][SZ_ARG]; // 命令名称参数列表
  int cmd_arg_count; // 命令参数个数
} cmd_t;

void init_command_struct(cmd_t *pcmd);

void print_command_struct(cmd_t *pcmd);

int cmd_parse(char *cmd_str, cmd_t *pcmd);

int cmd_dispatch(cmd_t *pcmd);

extern int cmd_execute(char *cmd_str);

#endif //PROJECT__CMD_HANDLE_H_
