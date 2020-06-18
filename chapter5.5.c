#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringcopy_array(char *s, char *t);
void stringcopy_pointer(char *s, char *t);
char *month_name(int n);

int main(int argc, char *argv[]) {

    // declaration of pointers to char[10]
    // char (*x)[10];
    // see this for why:
    // char g[10];
    // char *o;
    // o = g;
    // declaration of an array of 10 pointers that point to char
    // char *y[10];

    // String literal and String constant are the same thing, which is considered as character array for c. It's many characters surrounded by quoats
    // using pointer declaration allows us to point to somewhere else(a = "new string"), but string cannot be modified(it creates a read-only string literal)
    // a is still accessible through a[0], but not a[0] = 'h'
    // pointer cannot point to integer/character literal, only string literal
    // https://stackoverflow.com/questions/29405410/whats-the-difference-between-these-4-itemcharacter-array-string-literal-in-c
    char *a = "Hello World Pointer";
    // using array declaration allows us to change the array character, but no assignment is allowed
    // b is initialized with a string literal and is a character array. String literal can be a object maps to character array in a program
    char b[] = "Hello World Array";

    char (*zptr)[3];
    char *zp;
    char *z[3];
    zp = z;
    zptr = &z;
    char *z0 = "z0v";
    char *z1 = "z1v3";
    char *z2 = "z2v32";
    char *z3 = "z3v3234";
    z[0] = z0;
    z[1] = z1;
    z[2] = z2;

    // This gives compile error
    // int sz = 4;
    // char name[sz] = "Eric";

    printf("address of zp, %p\n", &zp); // address of pointer zp, hence different from &zp[0], similar with argv
    printf("address of zp[0], %p\n", &zp[0]); // same with (&z[0], z, zp, &z)
    printf("address of zp[1], %p\n", &zp[1]); // same with (&z[0], z, zp, &z)
    printf("zp, %p\n", zp); // same with (&z[0], z, zp, &z)
    printf("++zp, %p\n", ++zp); // same with (&z[0], z, zp, &z)
    printf("address of zptr, %p, zptr: %p\n", &zptr, zptr); // address of pointer zptr, different from z, zptr = &z
    printf("z, %p\n", z); // same with (&z[0], z, zp, &z)
    printf("address of z[0], %p\n", &z[0]); // address gap is pointer size, 8 bytes
    printf("address of z[1], %p\n", &z[1]); 
    printf("z0 points to address %p, %s\n", z[0], z[0]); // address gap is string size
    printf("z1 points to address %p\n", z[1]);
    printf("z2 points to address %p\n", z[2]);
    z[0] = "new string";
    // z[0][0] = 'N'; // error, not modifiable
    printf("z0, %p, %c\n", z[0], z[0][0]);
    printf("\n");

    // Read this link:
    // https://stackoverflow.com/questions/37549594/crash-or-segmentation-fault-when-data-is-copied-scanned-read-to-an-uninitializ
    // why use malloc? https://stackoverflow.com/questions/51448301/why-use-malloc-when-i-can-just-define-a-variable-length-array/51451640#51451640
    char *e = malloc(20);
    char f[20];
    stringcopy_array(f, b);
    printf("COPY ARRAY: %s\n", f);
    // This is not working if we don't use malloc because otherwise the value a is pointing to is unmodifiable string literal, same for NULL = nowhere
    stringcopy_pointer(e, a); 
    printf("COPY POINTER: %s\n", e);

    // can't do int*c = &400 because int is not lvalue as string literal
    int d = 400;
    int *c;
    c = &d; // or int *c = &d

    printf("%lu\n", strlen(a));
    printf("%lu\n", sizeof(a)); // pointer size of 8 bytes, machine dependent
    printf("%lu\n", strlen(b));
    printf("%lu\n", sizeof(b));

    printf("\n");

    printf("Pointer declaration for a:\n");
    printf("%p, %c\n", a, *a); // address of H
    printf("%p, %c\n", a+1, *(a+1)); // address of e
    printf("%p\n", &a); // address of pointer a
    printf("%p\n", &a+1); 

    printf("\n");

    printf("Array declaration for b:\n");
    printf("%s\n", b);
    printf("%p\n", b); // address of the first element in the array
    printf("%p\n", &b[0]); // address of the first element in the array
    printf("%p\n", &b); // address of the array
    
    printf("\n");

    printf("%p\n", &b+1); // address plus 1 is the offset of the whole array (move the pointer one (array size * type size) further)
    printf("%p\n", b+1); // pointer + 1 is pointer to next element in array (move it one type size further)
    printf("%p\n", &b[1]); // pointer address of the second element in array 

    printf("Operations on a and b:\n");

    char temp[] = "temp string";
    a = temp + 5;
    b[0] = 'h';

    // if a is a pointer, then
    // *a is the value it points to
    // a is the address of its own
    // &a is the address of the value it points to

    printf("%p\n", &temp);
    printf("%p\n", a);

    printf("%s\n", a);
    printf("%s\n", b);

    return 0;
}

void stringcopy_array(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]))
        i++;
}

void stringcopy_pointer(char *s, char *t) {
    while ((*s++ = *t++));
}

char *month_name(int n) {
    static char *name[] = {
        "illegal",
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", 
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" 
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}  