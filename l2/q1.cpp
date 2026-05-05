# include <iostream>
using namespace std;

// quicksort version !

int t_banco;
string n_banco;

void quick (int sort[], string extra [], int inicio, int fim){
    int pivo = sort[inicio];

    int esq = inicio+1;
    int dir = fim;
   
    if (esq > dir) return;

    while(1){
        while (sort[esq] <= pivo && esq < dir) {
            if ((sort[esq] == pivo && extra[esq] < extra[inicio]) || sort[esq] < pivo) esq++;
            else break;
        };
        while (sort[dir] >= pivo && dir >= esq) {
            if ((sort[dir] == pivo && extra[dir] > extra[inicio]) || sort[dir] > pivo) dir--;       
            else break;
        };

        if (esq >= dir) break; // cruzaram

        else{
            t_banco = sort[esq];
            n_banco = extra[esq];

            sort[esq] = sort[dir];
            extra[esq] = extra[dir];

            sort[dir] = t_banco;
            extra[dir] = n_banco;
        };

    }

    // breakou:
    t_banco = sort[dir];
    n_banco = extra[dir];

    sort[dir] = sort[inicio];
    extra[dir] = extra[inicio];

    sort[inicio] = t_banco;
    extra[inicio] = n_banco;

    quick(sort, extra, inicio, dir-1); // particao da esquerda
    // dir é a posiçao do pivo
    quick(sort, extra, dir+1, fim); // particao da direita


}

int main(){
    int qnt;
    cin >> qnt;

    string nomes [qnt];
    int tempos [qnt];

    for (int c=0; c<qnt; c++) {
        cin >> nomes[c] >> tempos[c];
    }

    quick(tempos, nomes, 0, qnt-1);
    
    for (int i=0; i<qnt; i++){
        cout << nomes[i] << ' '<< tempos[i] << endl;
    }

    return 0;
}