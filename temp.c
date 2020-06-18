#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef void (*funcptr) (int a, int b);

void (*p1)(void);

void f1(void) {
    printf("printing f1\n");
}

void adding(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
}

void multiplying(int a, int b) {
    printf("%d * %d = %d\n", a, b, a * b);
}

void subtracting(int a, int b) {
    printf("%d - %d = %d\n", a, b, a - b);
}

int main() {
    p1 = f1; // same for &f1
    funcptr parray[3]; // a list of function pointer of type funcptr
    int a, b;

    a = 1;
    b = 2;
    p1();
    parray[0] = adding;
    parray[1] = multiplying;
    parray[2] = subtracting;
    parray[0](a, b);
    parray[1](a, b);
    (*(parray+2))(a, b);

    return 0;
}

