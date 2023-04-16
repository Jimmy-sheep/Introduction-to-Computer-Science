// main.c
//

#include <stdio.h>
#include <time.h>
#pragma warning(disable : 4996)

void honai(FILE* pFile, int* pStep, int n, char peg1, char peg2, char peg3) { // n: disc      A B C: peg
    time_t p;
    struct tm* tp;
    char time_buffer[20];

    if (n == 1) {
        time(&p);
        tp = localtime(&p);
        strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
        fprintf(pFile, "%7d (%s): %dP move from %c to %c\n", *pStep, time_buffer, 1, peg1, peg3);
        (*pStep)++;
    }
    else {
        honai(pFile, pStep, n - 1, peg1, peg3, peg2);

        time(&p);
        tp = localtime(&p);
        strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
        fprintf(pFile, "%7d (%s): %dP move from %c to %c\n", *pStep, time_buffer, n, peg1, peg3);
        (*pStep)++;
        honai(pFile, pStep, n - 1, peg2, peg1, peg3);
    }
}

int main() {
    int disc = 20;
    int step = 1;

    time_t p;
    struct tm* tp;
    char time_buffer[20];

    FILE* pFile = fopen("hanoi.txt", "w+");

    time(&p);
    tp = localtime(&p);
    strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
    fprintf(pFile, "%s\n", time_buffer);

    honai(pFile, &step, disc, 'A', 'B', 'C');

    time(&p);
    tp = localtime(&p);
    strftime(time_buffer, 20, "%Y %m%d %H:%M:%S", tp);
    fprintf(pFile, "%s\n", time_buffer);

    fclose(pFile);

    system("PAUSE");
    return 0;
}
