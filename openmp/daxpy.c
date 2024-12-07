#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#pragma omp declare target
void daxpy(int n, double a, double *x, double *y) {
    #pragma omp parallel for
    for (int i = 0; i < n; ++i)
        y[i] = a * x[i] + y[i];
}
#pragma omp end declare target

void compute_daxpy(int n, double a, double *x, double *y) {
    #pragma omp target map(to: x[0:n]) map(tofrom: y[0:n])
    {
        daxpy(n, a, x, y);
    }
}

int main() {
    int n = 1000000;  // Number of elements
    double a = 2.0;

    // Allocate and initialize arrays
    double *x = (double *)malloc(n * sizeof(double));
    double *y = (double *)malloc(n * sizeof(double));

    // Initialize x and y arrays
    for (int i = 0; i < n; ++i) {
        x[i] = i; //
        y[i] = i +1; //
    }

    // Compute daxpy
    compute_daxpy(n, a, x, y);
    printf("Result: %f\n", y[0]);
    printf("Result: %f\n", y[1]);
    printf("Result: %f\n", y[3]);

    // Free memory
    free(x);
    free(y);

    return 0;
}

