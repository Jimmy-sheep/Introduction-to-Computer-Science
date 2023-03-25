#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

int main() {
    char buffer[128];
    int line = 1;

    FILE* pCFile = fopen(__FILE__, "r");
    FILE* pFile = fopen("main2.txt", "w+");

    while (fgets(buffer, sizeof(buffer), pCFile) != NULL) {
        fprintf(pFile, "%02d %s", line++, buffer);
    }

    fclose(pFile);
    fclose(pCFile);

    return 0;
}