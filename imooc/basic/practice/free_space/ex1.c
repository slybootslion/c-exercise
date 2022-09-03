#include "head.h"

#define ELETYPE int
#define MAX 5

struct sqList {
    ELETYPE data[MAX];
    int i;
};

int main() {
    struct sqList sql = {{0}, 0};
    for (; sql.i <= MAX; sql.i++) {
        printf("sql.i = %d\n", sql.i);
        sql.data[sql.i] = 2;
//        printf("%d\t\n", sql.data[sql.i]);
    }
    return 0;
}
