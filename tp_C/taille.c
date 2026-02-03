#include <stdio.h>



int main(void){
    printf("Taille des types de donnees en C (en octets) :\n\n");

    printf("char        : %zu octet(s)\n", sizeof(char));
    printf("short       : %zu octet(s)\n", sizeof(short));
    printf("int         : %zu octet(s)\n", sizeof(int));
    printf("long        : %zu octet(s)\n", sizeof(long));
    printf("long long   : %zu octet(s)\n", sizeof(long long));

    printf("float       : %zu octet(s)\n", sizeof(float));
    printf("double      : %zu octet(s)\n", sizeof(double));
    printf("long double : %zu octet(s)\n", sizeof(long double));

    printf("void*       : %zu octet(s)\n", sizeof(void*));
    return 0;
}