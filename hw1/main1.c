// main1.c
//

#include <stdio.h>

int main()
{
    char a[] = "AABBBCCCCddd";

    int size = sizeof(a) - 1;
    int flag = 0;
    int count = 1;

    for (int i = 0; i < size; i++) {
        if (a[i] != a[i + 1]) {
            printf("%c%d", a[i], count);
            count = 1;
        }
        else
            count++;
    }
    printf("\n");

    printf("\n");
    system("PAUSE");
    return 0;
}
