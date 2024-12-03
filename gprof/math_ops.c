// To run grpof on this program, compile it with -pg flag and run the executable.
// $ gcc -pg math_ops.c -o math_ops
// $ ./math_ops 5
// $ gprof math_ops gmon.out
// more info: 
// https://ftp.gnu.org/old-gnu/Manuals/gprof-2.9.1/html_mono/gprof.html
// https://www.thegeekstuff.com/2012/08/gprof-tutorial/

#include <stdio.h>
#include <stdlib.h>

void compute_sum(int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < n; i++) {
            for (int i = 0; i < n; i++) {
                sum += i;
            }
        }
    }
    printf("Sum: %lld\n", sum);
}

void compute_product(int n) {
    long long product = 1;
    for (int i = 1; i <= n; i++) {
        for (int i = 1; i <= n; i++) {
            product *= i;
        }
    }
    printf("Product: %lld\n", product);
}

void run_operations(int n) {
    compute_sum(n);
    compute_product(n);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        fprintf(stderr, "Please enter a positive number.\n");
        return EXIT_FAILURE;
    }

    if (n > 6) {
        fprintf(stderr, "Please enter a number less than or equal to 10.\n");
        return EXIT_FAILURE;
    }

    run_operations(n);
    return EXIT_SUCCESS;
}
