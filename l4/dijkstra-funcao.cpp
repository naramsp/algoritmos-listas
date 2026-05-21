// adendos sobre dijkstra:
# include <iostream>
/*/
/* guloso, mas sempre encontra a melhor resposta para uma travessia simples (que não necessita de PD)
/* não permite arestas negativas
/* vetores auxiliares: vetor de antecessores e vetor de pesos
/* antecessores são iniciados como -1 e pesos são iniciados como infinito (ambos mudam muito no decorrer do código)
/* peso do nó raiz (zero) é zero
/*/

void heapficar (int * heap [], int tam){
    // 0 = vertice, 1 = peso
    int hldr [2];
    for (int i = tam; i>-1; i--) {
        if ((i<<1)+1 < tam){ // elimina checks de quem nao tem antecessor
            for (int p=0; p<tam; p++) std::cout << p << " : " << heap[p][0] << " : " << heap[p][1] << std::endl;

            if (heap[(i<<i)+1][1] > heap[i][1]){ // se o peso do primerio filho de i for maior q o pai
                hldr[0] = heap[i][0]; hldr[1] = heap[i][1]; // aff

                heap[i] = heap[(i<<1)+1];
                heap[(i<<1)+1] = hldr;

            } else if ((i<<1)+2 < tam && heap[(i<<1)+2][1] > heap[i][1]){ // se o segundo filho for maior
                hldr[0] = heap[i][0]; hldr[1] = heap[i][1];

                heap[i] = heap[(i<<1)+2];
                heap[(i<<1)+2] = hldr;
            };
        }

            std::cout << "ITERACAO " << i << std::endl;
            std::cout << "comparaçoes: " << (i<<1)+1 << ' ' << (i<<1)+2 << std::endl;
        
    }
}

// implementado usando matriz de adjascencia
// em que grafo[vertice de partida][vertice de chegada] = peso
// e lugares impassaveis possuem peso de MAX INT
// min_heap seria apenas uma lista de pesos e vertices
# define PARTIDA 0
# define CHEGADA 1
# define PESO 2
void dij (int tam, int * grafo [], int * min_heap []){
    int * p = new int [tam];
    int * a = new int [tam];
    int * solucao = new int [tam]; int tam_solucao = 0;

    min_heap[0];

    int c; // contador

    for (c = 0; c<tam; c++){
        p[c] = __INT_MAX__;
        a[c] = -1;
    }
    p[0] = 0;
    heapficar(min_heap, tam);
    
    for (c = 0; c < tam; c++){
        // para remover da heap, eu posso só colocar o peso da casa removida como max int toda vez
        int vertice = min_heap[0][0];

        solucao[c] = vertice;
    
        for (int j = 0; j<tam; j++){
            // para cada vertice adjascente ao vertice considerado
            if (grafo[vertice][j]< __INT_MAX__){

                // *** RELAXAMENTO ***
                if (p[vertice] + grafo[vertice][j] < p[j] ){ //s se o peso de ir por v direto for maior doq o peso de passar por U e DEPOIs ir por V
                    a[j] = vertice;
                    p[j] = p[vertice] + grafo[vertice][j];
                }
            }

        }
    }

}

// teste do algoritmo
int main(){ 
    return 0;
}