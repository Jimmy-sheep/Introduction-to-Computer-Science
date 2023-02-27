// main3.c
//

#include <stdio.h>

int main()
{
    char a[10] = "ABCabcABC";
    int shift = 4;

    char b[10] = { 0 };
    int size = sizeof(a) - 1;
    for (int i = 0; i < size; i++)
        b[i] = a[i];

    for (int i = 0; i < size; i++)
        if (i + shift < size)
            b[i] = a[i + shift];
        else
            b[i] = a[i + shift - size];

    printf("%s\n", a);
    printf("%d\n", shift);
    printf("%s\n", b);

    printf("\n");

    system("PAUSE");
    return 0;
}
