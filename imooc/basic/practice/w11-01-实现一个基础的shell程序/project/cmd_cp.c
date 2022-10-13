//
// Created by SlybootsLion on 2022/10/12.
//
#include "cmd_cp.h"

int cmd_cp_execute(cmd_t *pcmd) {
  if (pcmd == NULL)
    return -1;

#ifdef DEBUG
  print_command_struct(pcmd);
#endif

  cp_file_info_t fileinfo;

  int ret = cmd_cp_parse_path(&fileinfo, pcmd);
  if (ret == -1)
    return -1;

  ret = cmd_cp_parse_type(&fileinfo);
  if (ret == -1)
    return -1;

  ret = cmd_cp_dispatch(&fileinfo);
  if (ret == -1)
    return -1;

  return 0;
}

int cmd_cp_parse_path(cp_file_info_t *pfileinfo, cmd_t *pcmd) {
  if (pfileinfo == NULL || pcmd == NULL)
    return -1;

  strcpy(pfileinfo->src_path, pcmd->cmd_arg_list[0]);
  strcpy(pfileinfo->dest_path, pcmd->cmd_arg_list[1]);

#ifdef DEBUG
  printf("[DEBUG] src path < %s >\n", pfileinfo->src_path);
  printf("[DEBUG] dest path < %s >\n", pfileinfo->dest_path);
#endif

  return 0;
}

int cmd_cp_parse_type(cp_file_info_t *pfileinfo) {
  enum file_type ftype = get_file_type(pfileinfo->src_path);

  if (ftype == FT_ERROR || ftype == FT_UNKNOWN)
    return -1;

  pfileinfo->src_ftype = ftype;
#ifdef DEBUG
  if (pfileinfo->src_ftype == FT_FILE)
    printf("File.\n");
  if (pfileinfo->src_ftype == FT_DIR)
    printf("Dir.\n");
#endif

  return 0;
}

int cmd_cp_dispatch(cp_file_info_t *pfileinfo) {
  if (pfileinfo->src_ftype == FT_FILE)
    return cmd_cp_file(pfileinfo->src_path, pfileinfo->dest_path);

  if (pfileinfo->src_ftype == FT_DIR)
    return cmd_cp_directory(pfileinfo->src_path, pfileinfo->dest_path);

  return 0;
}

int cmd_cp_file(const char *src, const char *dest) {
  if (src == NULL || dest == NULL)
    return -1;

  FILE *fp_src = NULL, *fp_dest = NULL;
  size_t rbytes = 0, wbytes = 0;
  char buffer[SZ_BUFFER] = {0};

#ifdef DEBUG
  printf("[DEBUG] %s --> %s\n", src, dest);
#endif

  fp_src = fopen(src, "r");
  if (fp_src == NULL) {
    perror("[ERROR] src fopen(): ");
    return -1;
  }

  fp_dest = fopen(dest, "w+");
  if (fp_dest == NULL) {
    perror("[ERROR] dest fopen(): ");
    return -1;
  }

  for (;;) {
    rbytes = fread(buffer, sizeof(char), SZ_BUFFER, fp_src);
    if (rbytes > 0) {
      wbytes = fwrite(buffer, sizeof(char), rbytes, fp_dest);
      if (wbytes != rbytes) {
        perror("[ERROR] fwite(): ");
        return -1;
      }
    } else
      break;
  }

  fclose(fp_src);
  fclose(fp_dest);

  return 0;
}

void make_path(cp_file_info_t *pinfo,
               const char *spath,
               const char *dpath,
               const char *filename) {
  memset(pinfo->src_path, 0, sizeof(pinfo->src_path));
  memset(pinfo->dest_path, 0, sizeof(pinfo->dest_path));

  strcpy(pinfo->src_path, spath);
  strcat(pinfo->src_path, "/");
  strcat(pinfo->src_path, filename);

  strcpy(pinfo->dest_path, dpath);
  strcat(pinfo->dest_path, "/");
  strcat(pinfo->dest_path, filename);
}

int cmd_cp_directory(const char *src, const char *dest) {
  DIR *pdir = NULL;
  struct dirent *pdirent = NULL;

  cp_file_info_t info;

  int ret = mkdir(dest, 0777);
  if (ret == -1) {
    perror("[ERROR] mkdir(): ");
    return -1;
  }

  pdir = opendir(src);
  if (pdir == NULL) {
    perror("[ERROR] opendir(): ");
    return -1;
  }

  for (;;) {
    pdirent = readdir(pdir);

    if (pdirent == NULL)
      break;

    if (strcmp(pdirent->d_name, ".") == 0 || strcmp(pdirent->d_name, "..") == 0)
      continue;

#ifdef DEBUG
    printf("[DEBUG] : filename < %s >\n", pdirent->d_name);
#endif

    make_path(&info, src, dest, pdirent->d_name);

#ifdef DEBUG
    printf("[DEBUG] : src path < %s >\n", info.src_path);
    printf("[DEBUG] : dest path < %s >\n", info.dest_path);
#endif

    info.src_ftype = get_file_type(info.src_path);

    if (info.src_ftype == FT_DIR)
      cmd_cp_directory(info.src_path, info.dest_path);
    else if(info.src_ftype == FT_FILE)
      cmd_cp_file(info.src_path, info.dest_path);
  }

  closedir(pdir);

  return 0;
}

enum file_type get_file_type(const char *path) {
  struct stat statbuf;
  int ret = stat(path, &statbuf);
  if (ret == -1) {
    perror("stat(): ");
    return FT_ERROR;
  }

  if (S_ISDIR(statbuf.st_mode))
    return FT_DIR;
  if (S_ISREG(statbuf.st_mode))
    return FT_FILE;

  return FT_UNKNOWN;
}
