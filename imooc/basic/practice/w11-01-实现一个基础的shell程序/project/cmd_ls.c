//
// Created by SlybootsLion on 2022/10/12.
//

#include "cmd_ls.h"

int cmd_ls_execute(cmd_t *pcmd) {
  if (pcmd == NULL)
    return -1;

#ifdef DEBUG
  print_command_struct(pcmd);
#endif

  if (pcmd->cmd_arg_count != 2) {
    fprintf(stderr, "Command argument Error.\n");
    return -1;
  }

  if (pcmd->cmd_arg_list[1] != NULL)
    return cmd_list_directory(pcmd->cmd_arg_list[1]);

  return -1;
}

int cmd_list_directory(const char *dirpath) {
  DIR *pdir = NULL;
  struct dirent *pdirent = NULL;
  char path[128] = {0};

  pdir = opendir(dirpath);
  if (pdir == NULL) {
    perror("opendir(): ");
    return -1;
  }

  while ((pdirent = readdir(pdir)) != NULL) {
    if (strcmp(pdirent->d_name, ".") == 0 || (strcmp(pdirent->d_name, "..")) == 0)
      continue;

#ifdef DEBUG
    printf("[DEBUG] filename < %s >\n", pdirent->d_name);
#endif
  }

  closedir(pdir);

  return 0;
}
