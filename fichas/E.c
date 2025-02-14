#include <stdio.h>
#include <assert.h>
#include <string.h>

int tamanho(char c[], int N) {
    int r = 0;
    int m = 1;
    int x1, x2;

    for (int i = 0; i<N-1; i++) {
        for (int j = N-1; j>i; j--) {
            x1 = i;
            x2 = j;
            while ((c[i] == c[j]) && (i!=j) && (j>i)) {
                r = r + 2;
                i++;
                j--;
            }
            if (i==j) r++;
            else if (i<j) r = 0;

            if (r>m) m = r;

            i = x1;
            j = x2;
            r = 0;
        }
    }

    return m;
}

int main() {
    char c[10000];
    int x, y;

    assert (scanf("%s",c) != 0);

    x = strlen(c);

    y = tamanho(c,x);

    printf("%d\n",y);

    return 0;
}
