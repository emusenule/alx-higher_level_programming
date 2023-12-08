#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void add_arguments(int argc, char* argv[]) {
    mpz_t total;
    mpz_init(total);

    for (int i = 1; i < argc; i++) {
        mpz_t arg;
        mpz_init_set_str(arg, argv[i], 10);
        mpz_add(total, total, arg);
        mpz_clear(arg);
    }

    gmp_printf("%Zd\n", total);

    mpz_clear(total);
}

int main(int argc, char* argv[]) {
    add_arguments(argc, argv);
    return 0;
}
