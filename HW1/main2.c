// main2.c
//

#include <stdio.h>

int main()
{
    char a[] = "A3B2C4A9";

    for (int i = 0; i < sizeof(a) - 1; i = i + 2)
        for (int j = 0; j < a[i + 1] - 48; j++)
            printf("%c", a[i]);
    printf("\n");

    printf("\n");
    system("PAUSE");
    return 0;
}
