#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

void printTable1() {
    float fahr, celsius;
    int lower, upper, step;

    lower = LOWER;
    upper = UPPER;
    step = STEP;

    fahr = lower;
    while (fahr<=upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void printTable2() {
    int fahr;
    for (fahr=LOWER; fahr <= UPPER; fahr = fahr + STEP) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}

/* print fahrenheit celsius table */

int main() {
    printf("\nPrint 1st table");
    printf("\n");
    printTable1();
    printf("\n");
    printf("\nPrint 2nd table");
    printf("\n");
    printTable2();
    return 0;
}