#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int c;
    // argv is the pointer array where each pointer points to its own string constant
    // ++argv moves it from file name to the first argument
    // *++argv gets the value of the whole argument
    // (*++argv)[0] gets the first character of the whole argument 
    while((--argc > 0) && ((*++argv)[0] == '-')) {
        // pointer gap is 8 bytes since the computer is 64-bit, hence need 8 bytes to represent address
        // argv is a pointer to a character pointer array
        printf("&argv: %p\n", &argv); // address of the pointer argv, different from argv[0]
        printf("argv: %p, *argv: %s\n", argv, *argv);  // address of the first element of array
        printf("&(argv[0]): %p\n", &(argv[0])); // address of the first element of array, gap is pointer size: 8 bytes
        printf("&(argv[1]): %p\n", &(argv[1]));
        printf("&(argv[0][0]): %p, %c\n", &(argv[0][0]), argv[0][0]); // gap is char size, 1 byte
        printf("&(argv[0][1]): %p, %c\n", &(argv[0][1]), argv[0][1]);
        printf("argv[0]: %p, *argv[0]: %c\n", argv[0], (*argv)[0]); // pointer to the first character of the first element in argc vector
        printf("argv[1]: %p, *argv[1]: %c\n", argv[1], (*argv)[1]);
        // argv[0] is the first pointer that points to the first character of the first element in the argv vector
        // ++argv[0] moves the pointer to the second character of the first element in the argv vector
        // *++argv[0] gets the value of the second character
        while (c = *++argv[0]) {
            switch(c) {
                case 'x': {
                    printf("inner x\n");
                    break;
                }
                case 'n': {
                    printf("inner n\n");  
                    break;
                }
            }
        }
        // printf("%s%s", *(++argv), (argc >= 1) ? " " : "\n");
    }
    return 0;
}