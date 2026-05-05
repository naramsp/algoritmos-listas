#include <iostream>
using namespace std;
int banco;

void quick (int sort[], int inicio, int fim){
    int pivo = sort[inicio];

    int esq = inicio+1;
    int dir = fim;
   
    if (esq > dir) return;

    while(1){
        while (sort[esq] < pivo && esq < dir) { esq++;};
        while (sort[dir] >= pivo && dir >= esq) {dir--;};

        if (esq >= dir) break; // cruzaram

        else{
            banco = sort[esq];
            sort[esq] = sort[dir];
            sort[dir] = banco;
        };

    }


     // breakou:
     // sim eu reusei o codigo. meio q o problema Ã© o mesmo
    banco = sort[dir];
    sort[dir] = sort[inicio];
    sort[inicio] = banco;

    quick(sort, inicio, dir-1); // particao da esquerda
    // dir Ã© a posiÃ§ao do pivo
    quick(sort, dir+1, fim); // particao da direita
}

int main(){
	// WRONG ANSERW OQ

	int in;
    cin >> in;

	int sort[in];

	for (int c =0; c<in; c++){
        cin >> sort[c];
	}
	
	quick(sort, 0, in);

	for(int i=0; i<in; i++) cout << sort[i] << endl;
    // OQ É PRESENTATION ERROR
	return 0;
}
