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

  file_attr_t attr;

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

    memset(&attr, 0, sizeof(attr));
    make_path_ls(path, dirpath, pdirent->d_name);

    if (pdirent->d_type == DT_LNK)
      get_file_attr(&attr, path, pdirent->d_name, true);
    else
      get_file_attr(&attr, path, pdirent->d_name, false);

    show_file_attributes(&attr);
  }

  closedir(pdir);

  return 0;
}

int get_file_attr(file_attr_t *pattr, const char *path, const char *filename, bool islink) {
  int ret;

  if (islink)
    ret = lstat(path, &pattr->f_attr_stat_info);
  else
    ret = stat(path, &pattr->f_attr_stat_info);

  if (ret == -1) {
    perror("[ERROR] stat(): ");
    return -1;
  }

  get_file_type_ls(pattr);

  return 0;
}

void make_path_ls(char *path, const char *dirpath, const char *filename) {
  strcpy(path, dirpath);
  strcat(path, "/");
  strcat(path, filename);
}

void show_file_attributes(file_attr_t *pattr) {
  printf(" %c", pattr->f_attr_type);
  putchar('\n');
}

int get_file_type_ls(struct file_attribute *pattr) {
  mode_t mode = pattr->f_attr_stat_info.st_mode;
  switch (mode & S_IFMT) {
    case S_IFBLK:
      pattr->f_attr_type = 'b';
      break;
    case S_IFCHR :
      pattr->f_attr_type = 'c';
      break;
    case S_IFDIR :
      pattr->f_attr_type = 'd';
      break;
    case S_IFIFO :
      pattr->f_attr_type = 'p';
      break;
    case S_IFLNK :
      pattr->f_attr_type = 'l';
      break;
    case S_IFREG :
      pattr->f_attr_type = '-';
      break;
    case S_IFSOCK:
      pattr->f_attr_type = 's';
      break;
    default:
      break;
  }
  return 0;
}
