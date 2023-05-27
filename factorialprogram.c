#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void factorial(mpz_t result, unsigned int n);

int main(int argc, char *argv[]) {
    unsigned int num;

    if (argc == 2) {
        // Number provided as a command-line argument
        num = atoi(argv[1]);
    } else {
        // Number entered during runtime
        printf("Enter a number: ");
        scanf("%u", &num);
    }

    mpz_t fact;
    mpz_init(fact);
    factorial(fact, num);

    gmp_printf("%Zd\n", fact);

    mpz_clear(fact);
    return 0;
}

void factorial(mpz_t result, unsigned int n) {
    mpz_set_ui(result, 1);
    while (n > 1) {
        mpz_mul_ui(result, result, n);
        n--;
    }
}


