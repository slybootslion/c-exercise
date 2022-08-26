//
// Created by SlybootsLion on 2022/8/23.
//

#include <stdio.h>
#include <sys/types.h>
#include <string.h>

#define ELETYPE int
#define MAX 5

struct sqList
{
    ELETYPE data[MAX];
    int i;
};

int main(int argc, const char *argv[])
{
    struct sqList sql = {{0}, 0};
    for( ; sql.i <= MAX; sql.i++){
        sql.data[sql.i] = 2;
        printf("%d\t\n", sql.data[sql.i]);
    }
}

