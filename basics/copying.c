#include <stdio.h>

void version1() {
    int c;

    c= getchar();
    while (c!=EOF) {
        putchar(c);
        c=getchar();
    }
}

void version2 () {
    int c;
    while ((c = getchar()) != EOF){
        putchar(c);
    }
    printf("%i", c);
}

int main(){
    version2();
    return 0;
}