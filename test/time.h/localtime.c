#include<time.h>
#include<stdio.h>

int main() {
    time_t timer;
    timer = time(NULL);

    printf("Current time is: %s", asctime(localtime(&timer)));
    return 0;
}