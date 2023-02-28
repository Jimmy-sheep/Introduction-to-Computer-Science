// main6.c
//

#include <stdio.h>

void roman_numeral(char* ch, int size) {
    for (int i = 0; i < size; i++) {
        switch (ch[i]) {
        case '1':
            printf("I ");
            break;
        case '2':
            printf("II ");
            break;
        case '3':
            printf("III ");
            break;
        case '4':
            printf("IV ");
            break;
        case '5':
            printf("V ");
            break;
        case '6':
            printf("VI ");
            break;
        case '7':
            printf("VII ");
            break;
        case '8':
            printf("VIII ");
            break;
        case '9':
            printf("IX ");
            break;
        default:
            printf("%c ", ch[i]);
            break;
        }
    }
    printf("\n");
}

int main()
{
    char a[] = "81c8g8u168";

    roman_numeral(a, sizeof(a) - 1);
 
    printf("\n");
    system("PAUSE");
    return 0;
}
