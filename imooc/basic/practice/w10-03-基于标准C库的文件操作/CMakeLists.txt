cmake_minimum_required(VERSION 3.24)
project(w10_03_C C)

set(CMAKE_C_STANDARD 11)

add_executable(w10_03_C 02fopen_fclose.c 03fopoen_fclose.c 01fprintf.c
        04fgetc_fputc.c 05fgetc_fputc.c 06fgets_fputs.c 07fgets_fputs.c 08fprintf_sprintf.c 09fscanf_sscanf.c 10.time.c 11fread_fwrite.c 12copy_picture.c)
