#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    time_t start, end;

    time(&start);
    Sleep(5000);
    printf("The difference is: %f seconds", difftime(end, start));
    return 0;
}