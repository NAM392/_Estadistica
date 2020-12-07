#include <stdio.h>

void pasoPorValor(int i) {
    i = 50;
}
void pasoPorReferencia(int *i) {
    (*i) = -10;
}
int main() {
    int i = 10;
    pasoPorValor(i);
    printf("%d\n", i);
    /*&i significa que se pasa la referencia de la variable i  */
    pasoPorReferencia(&i);
    printf("%d\n", i);
    return 0;
}
