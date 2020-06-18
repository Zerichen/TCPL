#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // accessing the last element of an array
    printf("accessing the last element of an array\n\n");

    char a[5] = "abcde";
    printf("a[-1]: %c\n", a[-1]); // it is accessing the element before the array, UB, unlike python
    printf("*(*(&a + 1) - 1): %p\n", &a);
    // (&a + 1) is the address right after the last element of the array
    // (char *)(&a + 1) converts (&a + 1) to a pointer to a character
    // (char *)(&a + 1)[-1] access the element before it
    // same for *((char *)(&a + 1) - 1)
    printf("*(*(&a + 1) - 1): %c\n", *(*(&a + 1) - 1)); 
    printf("*(*(&a + 1) - 1): %c\n", *(((char *)(&a + 1)) - 1)); 
    printf("*(*(&a + 1) - 1): %c\n", ((char *)(&a + 1))[-1]); 

    // pointer base in middle
    printf("pointer base in middle\n\n");
    
    char b[21] = "abcdefghijklmnopqrst";
    char *mid = &b[10]; // mid points to k, middle of the array
    for (int i = -10; i < 10; i++) {
        printf("%c", mid[i]); // same for *(mid + i)
    }
    printf("\n");

    // pointer subtraction
    printf("pointer subtraction\n\n");

    int c[6] = {0, 1, 2, 3, 4, 5};
    int *p = &c[5];
    int *q = &c[4]; 
    printf("p - q: %d\n", p - q); // automatically divided by data type size

    char d[] = "hello world";
    char *high = d+5;
    char *low = d;
    printf("high - low: %d\n", high - low);

    return 0;
}