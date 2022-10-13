//
// Created by SlybootsLion on 2022/10/12.
//

#include "cmd_handle.h"
#include "cmd_cp.h"
#include "cmd_ls.h"

#define DEBUG

int cmd_execute(char *cmd_str) {
  cmd_t command;
  int ret;

  if (cmd_str == NULL)
    return -1;

#ifdef DEBUG
  printf("[DEBUG] : cmd string : < %s >\n", cmd_str);
#endif

  init_command_struct(&command);

#ifdef DEBUG
  print_command_struct(&command);
#endif

  ret = cmd_parse(cmd_str, &command);
  if (ret == -1)
    return -1;

#ifdef DEBUG
  print_command_struct(&command);
#endif

  ret = cmd_dispatch(&command);
  if (ret == -1)
    return -1;

  return 0;
}

void init_command_struct(cmd_t *pcmd) {
  memset(pcmd->cmd_name, 0, SZ_NAME);
  for (int i = 0; i < SZ_COUNT; ++i) {
    memset(pcmd->cmd_arg_list[i], 0, SZ_ARG);
  }
  pcmd->cmd_arg_count = 0;
}

void print_command_struct(cmd_t *pcmd) {
  printf("----\n");

  printf("[DEBUG] cmd name: < %s >\n", pcmd->cmd_name);
  printf("[DEBUG] cmd arg count: < %d >\n", pcmd->cmd_arg_count);
  printf("[DEBUG] cmd arg list: ");

  for (int i = 0; i < pcmd->cmd_arg_count; ++i)
    printf("%s ", pcmd->cmd_arg_list[i]);

  printf("\n----\n");
}

int cmd_parse(char *cmd_str, cmd_t *pcmd) {
  if (cmd_str == NULL || pcmd == NULL)
    return -1;

  char *p_cmd_name = strtok(cmd_str, " ");

#ifdef DEBUG
  printf("[DEBUG] cmd name : < %s >\n", p_cmd_name);
#endif

  strcpy(pcmd->cmd_name, p_cmd_name);

  int index = 0;
  while (1) {
    char *p_cmd_arg = strtok(NULL, " ");
    if (p_cmd_arg == NULL)
      break;
    strcpy(pcmd->cmd_arg_list[index++], p_cmd_arg);
  }

  pcmd->cmd_arg_count = index;

  return 0;
}

int cmd_dispatch(cmd_t *pcmd) {
  if (pcmd == NULL)
    return -1;

  if (strcmp(pcmd->cmd_name, "ls") == 0) {
#ifdef DEBUG
    printf("ls command handle.\n");
#endif
    cmd_ls_execute(pcmd);
  }

  if (strcmp(pcmd->cmd_name, "cp") == 0) {
#ifdef DEBUG
    printf("cp command handle.\n");
#endif
    cmd_cp_execute(pcmd);
  }

  return 0;
}
