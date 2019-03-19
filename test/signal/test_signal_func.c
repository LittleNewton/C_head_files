#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigHandler(int sigNum) {
    printf("捕获到了信号 %d", sigNum);
    exit(1);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, sigHandler);

    while(1) {
        printf("睡眠一秒钟\n");
        sleep(1);
    }

    return 0;
}