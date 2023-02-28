// main4.c
//

#include <stdio.h>

void remove_char(char ch[], int size) {
    int j = 0;
    char result[20] = { 0 };

    for (int i = 0; i < size; i++)
        if ((ch[i] >= 48 && ch[i] <= 57) || ch[i] == 45) {
            result[j++] = ch[i];
        }
    printf("%s\n", result);
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
