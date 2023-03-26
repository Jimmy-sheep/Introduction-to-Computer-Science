// main7.c
//

#include <stdio.h>

void bin2hex(char* ch, int size) {
    for (int i = 0; i < size; i = i + 4) {
        char dec = ((ch[i] - 48) ?
            ((ch[i + 1] - 48) ?
                ((ch[i + 2] - 48) ?
                    ((ch[i + 3] - 48) ?
                        'F' : 'E') :
                    ((ch[i + 3] - 48) ?
                        'D' : 'C')) :
                ((ch[i + 2] - 48) ?
                    ((ch[i + 3] - 48) ?
                        'B' : 'A') :
                    ((ch[i + 3] - 48) ?
                        '9' : '8'))) :
            ((ch[i + 1] - 48) ?
                ((ch[i + 2] - 48) ?
                    ((ch[i + 3] - 48) ?
                        '7' : '6') :
                    ((ch[i + 3] - 48) ?
                        '5' : '4')) :
                ((ch[i + 2] - 48 ?
                    ((ch[i + 3] - 48) ?
                        '3' : '2') :
                    ((ch[i + 3] - 48) ?
                        '1' : '0')))));

        printf("%c", dec);
    }
    printf("\n");
}

int main()
{
    char a[] = "10001111";
    char b[] = "10011110";

    bin2hex(a, sizeof(a) - 1);
    bin2hex(b, sizeof(b) - 1);

    printf("\n");
    system("PAUSE");
    return 0;
}
