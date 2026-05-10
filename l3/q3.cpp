// a formatação dessa questao ta tao chatgpt que chega ta dificil de ler

# include <iostream>

long long pow (int base, int exp){
    long long r = base;
    while(exp-- > 1)r *= base;
    return r;
}

long long factorial (int n){
    long long r = 1;
    while (n-- > 1) r*= n;
    return r;
}

struct no{
    int indice = -999;
    no * prox = nullptr;
};

void PushNo(no * head, int insert){
    no * novo = new no;
    if (head->prox){
        no * JeffPesos;
        novo->indice = insert;
        
        JeffPesos = head->prox;
        head->prox = novo;
        novo->prox = JeffPesos;
    }

    else {
        novo->indice = insert;
        head->prox = novo;
    };
};

void TakeNo(no * head){ 
    no * die = head->prox;
    head->prox = die->prox;
    delete die; 
};

void DFS(int node, bool v[], no * list[], long long s[], long long tam){
    no * stack = new no;
    no * cur;
    PushNo(stack, node); 

    while (true){
        // == visitando o nó ==
    
        TakeNo(stack);
        if (!v[node]){
            v[node] = true;
        
            // == cojo geralmente viria aq mas dessa vez nao pq precisa das arestas ==

            // == empurrando vizinhos ==
            cur = list[node]->prox; // lembrar q heads sao sempre nao-usaveis
            while(cur){
                if (!v[cur->indice]) {
                    PushNo(stack, cur->indice);

                    // cojo q nao é de DFS
                    for (int i=0; i<tam; i++){
                        if ((1<<node & i) && (1<<cur->indice & i)){
                            s[i] = 0;
                        };
                    };
                };
                cur = cur->prox;
            }
        }

        // == passando pro proximo no ==
        if (!stack->prox) break;
        node = stack->prox->indice;
    }

};

int main(){
    int n, in, in2;
    std::cin >> n;
    int JeffPesos [n];
    bool * visitou = new bool [n];

    no ** AdjList = new no * [n];

    for (int i=0; i<n; i++) {
        std::cin>>in;
        JeffPesos[i] = in;
        
        AdjList[i] = new no;
    };

    for (long long i=0; i<n-1; i++){
        std::cin >> in >> in2;
        in--; in2--;
        PushNo(AdjList[in], in2);
        PushNo(AdjList[in2], in); 
    };

    // hihi, e se eu fizer os calculos Antes de considerar o grafo?
    long long bitmask = pow(2, n);
    long long somas [bitmask];
    somas[0] = 0;

    long long shf;
    int it;

    // ok programaçao dinamica it is
    for (long long i=1; i<bitmask; i++){
        shf = 1; it = 0;

                // a soma 0011 vai ser calculada antes da soma 1011
                // entao a soma 1011 pode ser considerada como a soma 0011 + 1000, ent... 
                // 1011 = 011 + 1000, ou
                //   11 = 3   + 8
                // ent é pegar o maior quadrado de um indice e tirar ele pra saber de onde a programaçao dinamica vai iniciar
                // importante frizar que, na conta acima, 11 e 3 seriam usados como índices de soma,
                // pq seus valores ja foram calculados,
                // mas 8 seria usado como bitmask, ou seja, representaria apenas o quarto nó sendo adicionado,
                // no lugar do número 8 em si.
                // ent por isso no codigo representei ele como um iterador, e nao como si mesmo


        while (shf < i){
            shf <<= 1;
            it++;
        };
        if (shf > i){
            shf >>= 1;
            somas[i] = somas[i - shf] + JeffPesos[--it]; // se for maior ent o iterador subiui 1 degrau a mais q nao era necessario
        } else { // i é quadrado perfeito
            somas[i] = JeffPesos[it];
        }
        
        // fazendo assim pq to tentando otimizar a qnt de chamadas por loop
    }

    /*
    eu sequer PRECISO do DFS????
    com certeza tem uma versao disso em que eu uso uma EdgeList e iterativamente bloqueio
    todas as opções com arestas bloqueadas

    se der TLE, dou um jeito de usar as contas ja feitas pra fazer uma conta futura
    */

    DFS(0, visitou, AdjList, somas, bitmask);

    long long max = 0;
    for (long long i=0; i<bitmask; i++){
        if (somas[i] > max) max = somas[i];
    };
    std::cout<<max<<std::endl;
    return 0;
}
