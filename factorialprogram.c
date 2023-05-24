#include <stdio.h>
#include <gmp.h>

void factorial(mpz_t result, unsigned int n);

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    mpz_t fact;
    mpz_init(fact);
    factorial(fact, num);

    gmp_printf("Factorial of %u = %Zd\n", num, fact);

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

