#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
bool n[33554433];

void triangulares(int n1, int n2) {
    int i = 0;
    int s;
    int k = (-1 + sqrt(1-4*(-2*n1)))/2;

    while (n1<=n2) {
        s = (k*(k+1))/2;

        if (s>=n1 && s<=n2) i++;

        n1 = s;

        k++;
    }

    printf("%d ", i);
}

void primos(int n1, int n2) {
    long int r = 0;

    for (int i = 2; i <= n2; i++) n[i] = 1;

    for (int i = 2; i*i < n2; i++)
        if (n[i] != 0) 
            for (int k = 2; k*i <= n2; k++) n[k*i] = 0;
    
    for (int i = n1; i<=n2; i++)
        if (n[i] != 0) r++;

    printf ("%ld\n", r);
}

int main() {
    int a, b;

    assert (scanf ("%d %d", &a, &b) == 2);

    triangulares (a,b);
    primos (a,b);

    return 0;
}
