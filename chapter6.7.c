#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y)) // this macro can be used as function, but be careful with parenthese

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
    printf("%p\n", p1);
    // dereferencing do nothing here, the name of the function decay to the pointer to that function
    // so no matter how many * you use, it is still pointer to that function, just like array and &array[0]
    // printf("%p\n", *****p1); 
    parray[0] = adding;
    parray[1] = multiplying;
    parray[2] = subtracting;
    parray[0](a, b);
    parray[1](a, b);
    (*(parray+2))(a, b);

    printf("abc" "d"); // abcd WHY? It's defined by the ISO C standard, adjacent string literals are combined into a single one.

    return 0;
}

