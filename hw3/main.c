// main.c
//

#include <stdio.h>
#include <string.h>
#include <time.h>
#pragma warning(disable : 4996)

typedef struct { // Size: 4 + 4 + 32 + 140 = 180
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
} lotto_record_t;

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
        int dup_flag = 0;

        if (i == 6)
            num = RandI(10);
        else
            num = RandI(69);

        for (int j = 0; j <= i; j++) {
            if (num == lotto[j]) {
                dup_flag = 1;
                i--;
                break;
            }
        }
        if (dup_flag == 0)
            lotto[i] = num;
    }

    bubble_sort(lotto, 6);
}

void check_record(int price[], int price_n) {
    int win_flag = 0;
    int lotto[7] = { 0 };
    lotto_record_t record;

    FILE* pRecFile = fopen("record.bin", "rb");

    if (pRecFile == NULL)
        printf("目前沒有彩券購買紀錄。\n");
    else {
        printf("以下為中獎彩券：\n");

        while (fread(&record, sizeof(lotto_record_t), 1, pRecFile)) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 7; j++) {
                    for (int p = 0; p < price_n; p++) {
                        if (record.lotto_set[i][j] == price[p]) {
                            win_flag = 1;
                            printf("彩券 No.%d\n", record.receipt_id);
                            printf("售出時間：%s", record.receipt_time);
                            printf("號碼：");
                            for (int k = 0; k < 7; k++)
                                printf("%02d ", record.lotto_set[i][k]);
                            printf("\n");
                            i++;
                        }
                    }
                }
            }
        }
        if(win_flag == 0)
            printf("本次無人中獎。\n");

        fclose(pRecFile);
    }
}

void write_record(char filename[], int lotto_n, int num) {
    int lotto[7] = { 0 };
    lotto_record_t new_record;    
    time_t now = time(NULL);
    char* nowtime = ctime(&now);

    FILE* pRecFile = fopen("record.bin", "ab+");
    FILE* pFile = fopen(filename, "w+");

    fprintf(pFile, "========= lotto649 =========\n");

    new_record.receipt_id = num + 1;
    fprintf(pFile, "========+ No.%05d +========\n", new_record.receipt_id);

    new_record.receipt_price = 100 * lotto_n;

    nowtime[strlen(nowtime) - 1] = '\0';
    strcpy(new_record.receipt_time, nowtime);
    fprintf(pFile, "= %s =\n", new_record.receipt_time);

    for (int i = 0; i < 5; i++) {
        fprintf(pFile, "[%d]: ", i + 1);

        if (i < lotto_n) {
            summon_lotto(lotto);
            for (int j = 0; j < 7; j++) {
                new_record.lotto_set[i][j] = lotto[j];
                fprintf(pFile, "%02d ", new_record.lotto_set[i][j]);
            }
            fprintf(pFile, "\n");
        }
        else {
            for (int j = 0; j < 7; j++)
                new_record.lotto_set[i][j] = 0;
            fprintf(pFile, "-- -- -- -- -- -- -- \n");
        }
    }
    fprintf(pFile, "========= csie@CGU =========\n");

    fclose(pFile);
    printf("已為您購買的 %d 組樂透組合輸出至 lotto[%05d].txt\n", lotto_n, new_record.receipt_id);

    fwrite(&new_record, sizeof(lotto_record_t), 1, pRecFile);
    fclose(pRecFile);
}

int main()
{
    int lotto_n, price_n, num = 0;
    int price[3] = { 0 };
    char filename[20] = { 0 };
    srand(time(0));

    printf("歡迎光臨長庚樂透彩購買機台\n請問您要購買幾組樂透彩：");
    scanf("%d", &lotto_n);

    if (lotto_n < 0 || lotto_n > 5) {
        printf("您輸入的數量有誤，請重新嘗試。\n");
        system("PAUSE");
        return 1;
    }
    else {
        lotto_record_t record;

        FILE* pRecFile = fopen("record.bin", "rb");
        if (pRecFile == NULL)
            num = 0;
        else {
            while (fread(&record, sizeof(lotto_record_t), 1, pRecFile))
                num = record.receipt_id;
            fclose(pRecFile);
        }

        sprintf(filename, "lotto[%05d].txt", num + 1);

        if (lotto_n == 0) {
            printf("請輸入中獎號碼（最多三個）：");
            for (int i = 0; i < 3; i++) {
                scanf("%d", &price[i]);
                price_n = i + 1;
                char ch = getchar();
                if (ch == '\n')
                    break;
            }

            printf("中獎號碼為：");
            for (int i = 0; i < price_n; i++)
                printf("%02d ", price[i]);
            printf("\n");

            check_record(price, price_n);
        }
        else
            write_record(filename, lotto_n, num);
    }

    system("PAUSE");
    return 0;
}
