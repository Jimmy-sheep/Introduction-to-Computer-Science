// main5.c
//

#include <stdio.h>

void swap(int a, int b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void decode(char* ch, int size, int* list) {
    int j = 0;

    for (int i = 0; i < size; i++) {
        if (ch[i] == 45) {                      // 負數
            list[j++] = ~(ch[i + 1] - 49);
            i++;
        }
        else if (ch[i] >= 48 && ch[i] <= 57)    // 正數
            list[j++] = ch[i] - 48;
    }
}

void quick_sort(int* list, int left, int right) {
    if (left < right) {
        int i = left, j = right + 1, pivot = list[left];
        do {
            do i++; while (list[i] <= pivot);
            do j--; while (list[j] > pivot);
            if (i < j)swap(list[i], list[j]);
        } while (i < j);
        swap(list[left], list[j]);
        quick_sort(list, left, j - 1);
        quick_sort(list, j + 1, right);
    }
}

int main()
{
    char a[] = "-9 8 7 6 5 -4 3 -2 1";
    int i = 4;

    int tmp;
    int size = sizeof(a) - 1;
    int list[9] = { 0 };

    decode(a, sizeof(a) - 1, list);
    quick_sort(list, 0, sizeof(list) / sizeof(list[0]));

    printf("%d\n", list[i]);

    printf("\n");
    system("PAUSE");
    return 0;
}
