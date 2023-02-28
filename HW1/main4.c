// main4.c
//

#include <stdio.h>

void remove_char(char ch[], int size) {
    int reg = 0;
    int sign = 1;

    for (int i = 0; i < size; i++) {
        if (ch[i] == 45)
            sign = -1;
        if ((ch[i] >= 48 && ch[i] <= 57)) {
            reg = reg * 10 + ch[i] - 48;
        }
    }
    printf("%d\n", sign * reg);
}

int main()
{
    char a[] = "-99acbc";
    char b[] = "99acbc";
    char c[] = "ac-99bc";

    remove_char(a, sizeof(a) - 1);
    remove_char(b, sizeof(b) - 1);
    remove_char(c, sizeof(c) - 1);

    printf("\n");
    system("PAUSE");
    return 0;
}
