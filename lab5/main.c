#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int mul(int x, int y) {
    return x * y;
}

int div(int x, int y) {
    return x / y;
}

int calc(int (*func_ptr)(int, int), int x, int y) {
    return func_ptr(x, y);
}

int main() {
    printf("sum = %d\n", calc(add, 4, 2));
    printf("dif = %d\n", calc(sub, 4, 2));
    printf("product = %d\n", calc(mul, 4, 2));
    printf("quotient = %d\n", calc(div, 4, 2));

    system("PAUSE");
    return 0;
}
