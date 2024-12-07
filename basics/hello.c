#include <stdio.h>

int main(void) {
    printf("Hello, World!");
    printf("char size: %lu bytes\n", sizeof(char));
    printf("int size: %lu bytes\n", sizeof(int));
    printf("short size: %lu bytes\n", sizeof(short));
    printf("long size: %lu bytes\n", sizeof(long));
    printf("float size: %lu bytes\n", sizeof(float));
    printf("double size: %lu bytes\n", 
        sizeof(double));
    printf("long double size: %lu bytes\n", 
        sizeof(long double));
    int age = 27;
    printf("%p", &age);
}
