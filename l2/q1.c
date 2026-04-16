/*
            PROBLEMA ESQUISITO:
        quando eu uso unsigned short pras pontuações, o eliud fica sobreposto com \0 na hora de escanear o vanderlei
        quando eu NAO uso, e troco pra int, laura e sofia ficam sobrepostas!! muito antes do vanderlei!!! é o que??

        amo c
*/

#include <stdio.h>
#include <string.h>

int main(){
    int qnt;

    // empates sao por ordem lexicografica, mas os inputs tmb sao lexicograficos

    // insertion sort funciona pra receber -> imediatamente saber onde vai, maaaas tempo de 1 segundo

    // o maximo é 100000, q é 10⁵, ent em tese da pra fazer com insertion, mas NAO SEEI a complexidade de strcpy

    scanf("%i", &qnt);

    char nomes [qnt] [30];
    unsigned short tempos [qnt];

    char n_banco[30];
    unsigned short t_banco;

    for (int c=0; c<qnt; c++) {
        scanf("%s", nomes[c]);
        scanf("%ud", &tempos[c]);
        
        // insort
        if (c>0) for (int i=c; i>-1; i--){
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