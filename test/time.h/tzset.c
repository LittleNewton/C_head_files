#include<time.h>
#include<stdlib.h>
#include<stdio.h>
int main() {
    time_t td;
    putenv("TZ=PST8PDT");
    tzset();
    time(&td);
    printf("Current time = %s", asctime(localtime(&td)));
    return 0;
}