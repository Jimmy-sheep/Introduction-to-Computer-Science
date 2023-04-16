#include <stdio.h>

typedef struct my_mm {
	unsigned allocated : 10;
	int* used[10];
} my_mm_t;

int g_mem[10];
my_mm_t mms;

int* my_calloc(int n, int size) {
	int* block;
	int total_size = n * size;

	if (total_size > sizeof(g_mem))		// 超出記憶體大小
		return NULL;

	for (int j = 0; j < sizeof(g_mem) / sizeof(g_mem[0]); j++) {
		if ((mms.allocated >> j) & 1 == 0) {
			block = &g_mem[j];
			int allocated_flag = 0;
			for (int k = 0; k < size; k++) {
				mms.used[j + k] = block;
				mms.allocated |= (1 << (j + k));
			}
			printf("%010u\n", mms.allocated);
			return block;
		}
	}
	return NULL;
}

void my_free(int* p) {
	int index;
	if (p != NULL) {
		index = (int)((char*)p - (char*)g_mem) / sizeof(g_mem[0]);
	}

	for (int i = 0; i < sizeof(g_mem) / sizeof(g_mem[0]); i++) {
		if (mms.used[index] == p) {
			mms.allocated &= ~(1 << i);
			mms.used[index] = NULL;
		}
	}
	printf("%010u\n", mms.allocated);
}

int main() {
	int* np1 = my_calloc(1, 1);
	int* np2 = my_calloc(1, 2);
	int* np3 = my_calloc(1, 3);
	int* np4 = my_calloc(1, 4);
	//my_free(np1);
	//my_free(np4);
	int* np5 = my_calloc(1, 3);

	return 0;
}