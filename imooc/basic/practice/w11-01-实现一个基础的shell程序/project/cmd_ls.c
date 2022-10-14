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
  get_file_permission(pattr);
  get_file_uname(pattr);
  get_file_gname(pattr);
  get_file_last_modify_time(pattr);

  if (pattr->f_attr_type == 'l') {
    ret = (int) readlink(path, pattr->f_attr_link_content, sizeof(pattr->f_attr_link_content));
    if (ret == -1) {
      perror("[ERROR] readlink(): ");
      return -1;
    }
  }

  strcpy(pattr->f_attr_name, filename);

  return 0;
}

void make_path_ls(char *path, const char *dirpath, const char *filename) {
  strcpy(path, dirpath);
  strcat(path, "/");
  strcat(path, filename);
}

void show_file_attributes(file_attr_t *pattr) {
  printf(" %c ", pattr->f_attr_type);
  printf(" %s ", pattr->f_attr_permission);
  printf(" %ld ", pattr->f_attr_stat_info.st_nlink);
  printf(" %s ", pattr->f_attr_uname);
  printf(" %s ", pattr->f_attr_gname);
  printf(" %ld ", pattr->f_attr_stat_info.st_size);
  printf(" %s ", pattr->f_attr_mtime);

  if (pattr->f_attr_type == 'l')
    printf(" %s -> %s ", pattr->f_attr_name, pattr->f_attr_link_content);
  else
    printf(" %s ", pattr->f_attr_name);

  putchar('\n');
}

void get_file_type_ls(struct file_attribute *pattr) {
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
}

void get_file_permission(struct file_attribute *pattr) {
  mode_t mode = pattr->f_attr_stat_info.st_mode;
  char perm[] = "rwx";

  int index = 0;
  for (int i = 8; i >= 0; i--) {
    if (mode >> i & 0x1)
      pattr->f_attr_permission[index] = perm[index % 3];
    else
      pattr->f_attr_permission[index] = '-';

    index++;
  }
}

void get_file_uname(struct file_attribute *pattr) {
  struct passwd *pwd = getpwuid(pattr->f_attr_stat_info.st_uid);
  strcpy(pattr->f_attr_uname, pwd->pw_name);
}

void get_file_gname(struct file_attribute *pattr) {
  struct group *grp = getgrgid(pattr->f_attr_stat_info.st_gid);
  strcpy(pattr->f_attr_gname, grp->gr_name);
}

void get_file_last_modify_time(struct file_attribute *pattr) {
  char *timestr = ctime(&pattr->f_attr_stat_info.st_mtime);
  strcpy(pattr->f_attr_mtime, timestr);
  pattr->f_attr_mtime[strlen(timestr) - 1] = '\0';
}
