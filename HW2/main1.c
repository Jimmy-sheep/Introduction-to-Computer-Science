// main1.c
//

#include <stdio.h>
#include <time.h>
#pragma warning(disable : 4996)

inline int RandI(int N) {
    return  rand() % N + 1;
}

void bubble_sort(int list[], int n) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = n - 1; j > i; j--) {
            if (list[j] < list[j - 1]) {
                int tmp;
                tmp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = tmp;

                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

void summon_lotto(int lotto[]) {
    for (int i = 0; i < 7; i++) {
        int num = 0;
        int flag = 1;

        if (i == 6)
            num = RandI(10);
        else
            num = RandI(69);

        for (int j = 0; j <= i; j++) {
            if (num == lotto[j]) {
                flag = 0;
                i--;
                break;
            }
        }
        if (flag == 1)
            lotto[i] = num;
    }
}

int main()
{
    int n;
    int lotto[7] = { 0 };
    srand(time(0));
    time_t now = time(NULL);

    printf("歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組樂透彩：");
    scanf("%d", &n);

    FILE* pFile = fopen("lotto.txt", "w+");

    fprintf(pFile, "======== lotto649 =========\n");
    fprintf(pFile, "= %s", ctime(&now));

    for (int i = 0; i < n; i++) {
        summon_lotto(lotto);
        bubble_sort(lotto, 6);

        fprintf(pFile, "[%d]: ", i + 1);
        for (int j = 0; j < 7; j++)
            fprintf(pFile, "%02d ", lotto[j]);
        fprintf(pFile, "\n");
    }

    for (int i = n; i < 5; i++) {
        summon_lotto(lotto);
        bubble_sort(lotto, 6);

        fprintf(pFile, "[%d]: ", i + 1);
        for (int j = 0; j < 7; j++)
            fprintf(pFile, "-- ");
        fprintf(pFile, "\n");
    }

    fprintf(pFile, "======== csie@CGU =========\n");

    fclose(pFile);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    printf("\n");
    system("PAUSE");
    return 0;
}
