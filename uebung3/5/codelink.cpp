/**
 * Code linker
 *
 * Author: Richard Fussenegger
 * Author: Markus Deutschl
 * See: prakt-inf-4.pdf, page 19
 */
#include <cstdio>
#include <cstdlib>

// Use simple C style identifiers, not the complicated C++ ones.
extern "C" unsigned calc_expr();

int main() {
    printf("architecture %s\n", sizeof (void *) == 8 ? "64bit" : "32bit");
    printf("expr(compiled) = %d\n", calc_expr());

    return EXIT_SUCCESS;
}