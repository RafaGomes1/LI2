#include <stdio.h>
#include <assert.h>

int volume(int r, int h, int m) {
    int v;
    float pi;
    pi = 3.14;

    v = ((pi*h)/3) * ((r*r) + (r*m) + (m*m));

    return v;
}

int main() {
    int r, h, m, v;

    assert (scanf ("%d %d %d", &r, &h, &m) == 3);

    v = volume (r, h, m);
    printf ("%d\n", v);

    return 0;
}
