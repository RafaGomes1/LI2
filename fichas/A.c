#include <stdio.h>
#include <assert.h>

int quadrado(int a, int b) {
    int r;
    r = b*b;

    if (a>b) r = a*a;

    return r;
}

int main() {
    int a, b, r;

    assert (scanf ("%d %d", &a, &b) == 2);

    if (a==b) printf ("IGUAIS\n");
    else {
        r = quadrado (a,b);
        printf ("%d\n", r);
    }

    return 0;
}
