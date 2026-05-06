# include <iostream>

struct no{
    int val;
    no * next = nullptr;
};

no * fila = new no; // pra usar no BFS

void AdcNo(no * head, int v){
    no * atual = head;
    while (atual->next != nullptr) atual = atual->next;

    no * adc = new no; adc->val = v;
    atual->next = adc;
};

void RemNo(no * head){
    no * die = head; // die means the in deutsch
    head->next = die->next;
    delete die;
};


void BFS(int node, bool v[], int d[], no list[]){
    v[node] = true;
    AdcNo(fila, node);
    no * cur; // cur stands for cursor, not current
    // passeia pela lista de adjascencia

    while (true){ // enqnt tiver no
        cur = list[node].next; 
        
        while (cur != nullptr){ 
            if (!v[cur->val]){
                v[cur->val] = true;
                
                d[cur->val] = d[node] +1;
                AdcNo(fila, cur->val);
            };
            cur = cur->next;
        };
    
        if (fila->next == nullptr) break; // segfault aqui
        node = fila->next->val;
        RemNo(fila);
    }

};

int main(){

    int n, m, atual = 1;
    int MaxX = -1, MaxY = -1, MaxDist = -1; // vars do 2o output
    char in; // in stands for input

    std::cin >> n >> m;

    bool *visitou = new bool [(n*m)+1];
    int * distancias = new int[(n*m)+1];
    no * AdjList = new no [(n*m)+1];
    // +1 porque vou usar o 0 como source falso, pra fazer o multisource
    
    for (int i=0; i<(n*m)+1; i++){
        visitou[i]=false;
        distancias[i] = -1;
    };

    
    char ** InputMtrx = new char * [n];
    for (int i = 0; i<m; i++) InputMtrx[i] = new char [m];

    for (int i=1; i<n+1; i++) for (int j=1; j<m+1; j++){
        std::cin >> in;
        InputMtrx[i-1][j-1] = in;

        if (in != '#'){
            if (in == 'P') AdcNo(&(AdjList[0]), atual);
            if (j>1 && InputMtrx[i-1][j-2] != '#'){
                AdcNo(&(AdjList[atual-1]), atual);
                AdcNo(&(AdjList[atual]), atual-1);
            };
            if (atual>m && InputMtrx[i-2][j-1] != '#'){
                AdcNo(&(AdjList[atual]), atual-m);
                AdcNo(&(AdjList[atual-m]), atual);
            };
        }
        atual++; // da pra calcular atual iterativamente mas ai ia ficar ainda mais dificil de ler
    }
    
    BFS(0, visitou, distancias, AdjList);
    
    for (int i=1; i<(n*m)+1; i++){
        std::cout << distancias[i];
        if (distancias[i] > MaxDist){
            MaxDist = distancias[i];
            MaxX = i%m;
            MaxY = (i/m)+1;
        };
        
        if (!(i%m)) std::cout << std::endl;
        else std::cout << ' ';
    }
    
    return 0;
}
