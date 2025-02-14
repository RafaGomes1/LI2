#include <stdio.h>
#include <string.h>

int main() {
    char c[1000][52];
    int aux[1000];
    int freq;
    int lf = 0;
    int valor;

    if (scanf("%d\n",&freq) == 1)

    for (int i = 0; fgets(c[i],52,stdin) != 0; i++,lf++);
    //stdin - apontador para um FILE que está associado ao arquivo de onde a string será lida

    for (int letra1 = 65; letra1 < 91; letra1++){
        valor = 0;
        for (int l = 0 ; l < lf; l++) {
            aux [l] = 1;
            for (int coluna = 0 ; coluna < 52; coluna ++)
                if (c[l][coluna] == letra1) {
                    valor ++;
                    aux [l] = 0;
                    coluna = 52;
                }
        }
        if (valor >= freq)
            printf("%c = %d\n",letra1, valor);

        if (valor > 0) 
            for (int letra2 = letra1 + 1; letra2 < 91; letra2++){
                valor = 0;
                for (int l = 0 ; l < lf; l++)
                    if (aux[l] == 0)
                        for (int coluna = 0 ; coluna < 52; coluna ++)
                            if (c[l][coluna] == letra2) {
                                valor++;
                                coluna = 52;
                            }
                if (valor >= freq)
                    printf ("%c%c = %d\n",letra1,letra2, valor);
            }
    }
    return 0;
}
