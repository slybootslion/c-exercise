#include <stdio.h>
#include <signal.h>
#include <sys/time.h>

//
// Created by SlybootsLion on 2022/8/23.
//
int c = 0;

void sig_handler() {
    printf("rec signal\n");
    c++;
}

int main() {
    if (signal(SIGALRM, sig_handler) == SIG_ERR) {
        printf("signal call is error!\n");
        return -1;
    }

    struct itimerval val = {{1, 0},
                            {1, 0}};

    setitimer(ITIMER_REAL, &val, NULL);
    while (1) {
        if (c == 100)
            break;
    };
    return 0;
}
