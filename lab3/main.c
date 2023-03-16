#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct person {
	int id;
	char first_name[32];
	char last_name[32];
} person_t;

int main() {
	FILE* wfp = fopen("person.bin", "w+");
	person_t p[5] = { {1, "IU", "LEE"},
					  {2, "IUU", "LEE"},
					  {3, "IUUU", "LEE"},
					  {4, "IUUUU", "LEE"},
					  {5, "IUUUUU", "LEE"},
	};

	for (int i = 0; i < 5; i++) {
		fwrite(p + i, sizeof(person_t), 1, wfp);
	}
	fclose(wfp);

	FILE* rfp = fopen("person.bin", "r");
	person_t tmp[1];
	int i = 0;
	while (fread(tmp, sizeof(person_t), 1, rfp)) {
		printf("[%d] %d: %s %s\n", i, tmp[0].id, tmp[0].first_name, tmp[0].last_name);
		i++;
	}
	fclose(rfp);

	system("PAUSE");
	return 0;
}
