#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)

int main() {
	int a[] = { 1, 2, 3 };
	char b[] = "ABC";
	float c[] = { 1.1, 1.2, 1.3 };
	FILE* pFile;
	int arr_read[3];

	pFile = fopen("a.bin", "wb+");
	fwrite(a, sizeof(int), 1, pFile);
	fseek(pFile, 0, SEEK_SET);
	fread(arr_read, sizeof(arr_read), 1, pFile);

	fclose("a.bin");
	for (int i = 0; i < 3; i++)
		printf("%d", arr_read[i]);

	system("PAUSE");
	return 0;
}
