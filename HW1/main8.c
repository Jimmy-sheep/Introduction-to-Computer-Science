// main8.c
//

#include <stdio.h>

void reverse(char* ch, int size) {
    int j = 0;
    for (int i = size - 1; i >= 0; i--) {
        if ((ch[i] >= 97 && ch[i] <= 122) && (ch[j] >= 41 && ch[j] <= 90))
            printf("%c", ch[i] - 32);
        else if ((ch[i] >= 65 && ch[i] <= 90) && (ch[j] >= 97 && ch[j] <= 122))
            printf("%c", ch[i] + 32);
        else
            printf("%c", ch[i]);
        j++;
    }
    printf("\n");
}

int main()
{
    char a[] = "Hello";

    printf("a = %s\n", a);
    printf("a = ");
    reverse(a, sizeof(a) - 1);

    printf("\n");
    system("PAUSE");
    return 0;
}
