// a formatação dessa questao ta tao chatgpt que chega ta dificil de ler
// n é bom usar ia pra criar questao nao vei aprendam.
# include <iostream>


// vou submeter, seja oq Deus quiser
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

void DFS(int node, bool v[], no * list[], int p[], long long s[], long long tam){
    no * stack = new no;
    no * cur;
    PushNo(stack, node); 

    while (true){
        // == visitando o nó ==
    
        TakeNo(stack);
        if (!v[node]){
            v[node] = true;

            // == empurrando vizinhos ==
            cur = list[node]->prox; // lembrar q heads sao sempre nao-usaveis
            while(cur){
                if (!v[cur->indice]) {
                    PushNo(stack, cur->indice);

                    // cojo q nao é de DFS
                    for (int i=0; i<tam; i++){
                        if ((1<<node & i) && (1<<cur->indice & i)){
                            s[i] = -999;
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

    for (int i=0; i<n-1; i++){
        std::cin >> in >> in2;
        in--; in2--;
        PushNo(AdjList[in], in2);
        PushNo(AdjList[in2], in); 
    };

    // hihi, e se eu fizer os calculos Antes de considerar o grafo?
    long long bitmask = pow(2, n);
    long long somas [bitmask];
    for (int i=0; i< bitmask; i++) somas[i] = 0;

    long long shf;
    int it;

    for (long long i=1; i<bitmask; i++){
        shf = 1; it = 0;
        while (shf <= i){
            if (shf & i){
                somas[i] += JeffPesos[it];
            };
            shf <<= 1;
            it++;
        }
    }

    /*
    eu sequer PRECISO do DFS????
    com certeza tem uma versao disso em que eu uso uma EdgeList e iterativamente bloqueio
    todas as opções com arestas bloqueadas

    se der TLE, dou um jeito de usar as contas ja feitas pra fazer uma conta futura
    */

    DFS(0, visitou, AdjList, JeffPesos, somas, bitmask);

    long long max = 0;
    for (int i=0; i<bitmask; i++){
        if (somas[i] > max) max = somas[i];
    };
    std::cout<<max<<std::endl;
    return 0;
}
