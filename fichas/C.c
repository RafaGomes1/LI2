#include <stdio.h>
#include <assert.h>

int maior (int a, int b, int c) {
    if (a>b && a>c) 
         return a;
    else if (b>a && b>c) 
        return b;  
    else
        return c;
}

void imprime (int v[]) {
    
    printf("%d %d %d\n", v[0], v[1], v[2]);
}

void swap (int v[], int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

void ordena (int v[], int n) {
    for (int i = 0; i < n ; i++) {
        for (int k = i ; k<n ; k++){
            if (v[k] < v[i]) swap (v,i,k);
        }
    }
}

int fatorial (int x) {
    int r=1;

    while (x>0) {
        r = r*x;
        x--;
    }

    return r;
}

int verificaF (int x) {
    int r = 1;
    int t = 0;

    while (x >= fatorial (r)) {
        if (x == fatorial (r)) t = 1;
        r++;
    }

    return t;
}

int main() {
    int a, b, c, r;

    assert (scanf ("%d %d %d", &a, &b, &c) == 3);

    int v[3] = {a,b,c};

    r = maior(a,b,c);
    
    if (verificaF (r) == 1) printf ("FATORIAL\n");
    else {
            ordena (v, 3);

            imprime (v);
    }

    return 0;
}
