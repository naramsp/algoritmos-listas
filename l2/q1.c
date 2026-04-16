/*
    RUNTIME ERROR??????????
*/
#include <stdio.h>
#include <string.h>

int main(){
    int qnt;
    scanf("%i", &qnt);

    char nomes [qnt] [30];
    int tempos [qnt];

    char n_banco[30];
    int t_banco;

    for (int c=0; c<qnt; c++) {
        scanf("%s", nomes[c]);
        scanf("%i", &t_banco);
        tempos[c] = t_banco;
        
        // insort
        for (int i=c; i>0; i--){
            if (tempos[i] < tempos[i-1]){
                t_banco = tempos[i-1];
                strcpy(n_banco, nomes[i-1]);

                tempos[i-1] = tempos[i];
                strcpy(nomes[i-1], nomes[i]);

                tempos[i] = t_banco;
                strcpy(nomes[i], n_banco);
            } else break; 
        }


    }

    for (int c = 0; c<qnt; c++){
        printf("%s %i\n", nomes[c], tempos[c]);
    }

    return 0;
}