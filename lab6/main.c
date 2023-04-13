#include <stdio.h>

int multiplacation(int i, int j) {
	if (i == 9 && j == 9) {
		printf("%d*%d=%d\n", i, j, i * j);
	}
	else if (j == 9) {
		printf("%d*%d=%d\n", i, j, i * j);
		multiplacation(i + 1, 1);
	}
	else {
		printf("%d*%d=%d ", i, j, i * j);
		multiplacation(i, j + 1);
	}
}

int main() {
	multiplacation(1, 1);

	return 0;
}
