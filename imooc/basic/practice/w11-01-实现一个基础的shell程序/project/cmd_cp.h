//
// Created by SlybootsLion on 2022/10/12.
//

#ifndef PROJECT__CMD_CP_H_
#define PROJECT__CMD_CP_H_

#include "cmd_handle.h"

#define SZ_PATH 128
#define SZ_BUFFER 1024


enum file_type {
  FT_DIR = 0,
  FT_FILE,
  FT_ERROR,
  FT_UNKNOWN,
};

typedef struct cp_file_info {
  enum file_type src_ftype;
  char src_path[SZ_PATH];
  char dest_path[SZ_PATH];
} cp_file_info_t;

extern int cmd_cp_execute(cmd_t *pcmd);
extern int cmd_cp_parse_path(cp_file_info_t *pfileinfo, cmd_t *pcmd);
extern int cmd_cp_parse_type(cp_file_info_t *pfileinfo);

extern int cmd_cp_dispatch(cp_file_info_t *pfileinfo);
extern int cmd_cp_file(const char *src, const char *dest);
extern int cmd_cp_directory(const char *src, const char *dest);
extern void make_path(cp_file_info_t *pinfo,
                      const char *spath,
                      const char *dpath,
                      const char *filename);

enum file_type get_file_type(const char *path);

#endif //PROJECT__CMD_CP_H_
