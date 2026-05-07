// a formatação dessa questao ta tao chatgpt que chega ta dificil de ler
// n é bom usar ia pra criar questao nao vei aprendam.
# include <iostream>
# define PAI 0
# define FILHO 1
# define PESO 2

struct no{
    int val = -999; // se der problema vai dar pra ver kk
    no * prox = nullptr;
};

void PushNo(no * head, int insert){
    no * novo = new no;
    no * temp;
    novo->val = insert;
    
    temp = head->prox;
    head->prox = novo;
    novo->prox = temp;
};

void TakeNo(no * head){ // se eu usar pop vou confundir
    no * die = head->prox;
    head->prox = die->prox;
    delete die; // se der segfault essa linha eh o problema
};

void DFS(int node, bool v[]){
    no * stack = new no;
    PushNo(stack, node);

    while ((stack->prox) != nullptr){
        
        if (!v[node]){
            v[node] = true;

            // == NÓ VISITADO ==

            no * cur = stack->prox;
            while(cur->prox != nullptr){
                if (!v[cur->val]) PushNo(stack, cur->val);
                cur = cur->prox;
            }


        }
    }

};

int main(){
    int n, in, in2;
    std::cin >> n;
    int * temp = new int [n];
    bool * visitou = new bool [n];

    int ** AdjList = new int * [n];

    for (int i=0; i<n; i++) {
        std::cin>>in;
        temp[i] = in;

        int AdjList[i][3] = {-1, -1, -1}; // sera q da pra inicializar sem colocar valor?
    };

    for (int i=0; i<n; i++){
        std::cin >> in >> in2;
        AdjList[i][PAI] = in;
        AdjList[i][FILHO] = in2;
        AdjList[i][PESO] = temp[i];  
    };



    return 0;
}
