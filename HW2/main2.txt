#include <stdio.h>
#pragma warning(disable : 4996)

int main() {
    char text;

    FILE* pCFile = fopen(__FILE__, "r");
    FILE* pFile = fopen("main2.txt", "w+");

    while ((text = fgetc(pCFile)) != EOF) {
        fputc(text, pFile);
    }

    fclose(pFile);
    fclose(pCFile);

    return 0;
}