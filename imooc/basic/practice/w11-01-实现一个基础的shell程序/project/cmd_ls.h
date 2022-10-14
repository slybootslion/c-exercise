//
// Created by SlybootsLion on 2022/10/12.
//

#ifndef PROJECT__CMD_LS_H_
#define PROJECT__CMD_LS_H_

#include "cmd_handle.h"

#define SZ_LS_NAME 64
#define SZ_LS_PERMISSION 10
#define SZ_LS_TIME 32
#define SZ_LS_LINK_CONTENT 64

typedef struct file_attribute {
  struct stat f_attr_stat_info;

  char f_attr_type;     // 文件类型
  char f_attr_uname[SZ_LS_NAME];// user's name
  char f_attr_gname[SZ_LS_NAME];// group name
  char f_attr_mtime[SZ_LS_TIME]; // 最后一次修改时间
  char f_attr_permission[SZ_LS_PERMISSION];// 权限
  char f_attr_name[SZ_LS_NAME];
  char f_attr_link_content[SZ_LS_LINK_CONTENT];
} file_attr_t;

extern int cmd_ls_execute(cmd_t *pcmd);
extern int cmd_list_directory(const char *dirpath);
extern int get_file_attr(struct file_attribute *pattr, const char *path, const char *filename, bool islink);
extern void make_path_ls(char *path, const char *dirpath, const char *filename);
extern void show_file_attributes(struct file_attribute *pattr);

extern void get_file_type_ls(struct file_attribute *pattr);
extern void get_file_permission(struct file_attribute *pattr);
extern void get_file_uname(struct file_attribute *pattr);
extern void get_file_gname(struct file_attribute *pattr);
extern void get_file_last_modify_time(struct file_attribute *pattr);

#endif //PROJECT__CMD_LS_H_
