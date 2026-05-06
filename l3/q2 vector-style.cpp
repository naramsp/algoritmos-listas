// ok, passou nos testes 

# include <iostream>
# include <vector>

std::vector<bool> visitou; // NO FINAL, trocar por bitmask
std::vector<std::vector<int>> AdjList; // NO FINAL trocar por array com listas encadeadas
std::vector<std::vector<char>> InputMtrx; // facilita as coisas, trocar por array estatico msm

std::vector<int> queueimprov;
std::vector<int> distancias;
// cinco mil vetores
// quando for submeter, nao sei como fazer queueimprov, mas distancias vai ser um array estatico tmb

void BFS(int no){ 
    visitou[no] = true;

    queueimprov.push_back(no);

        while (!queueimprov.empty()){

            for (int i = 0; i < AdjList[no].size(); i++) // pra cada outro nó adjascente ao atual
                if (!visitou[AdjList[no][i]]){
                    visitou[AdjList[no][i]] = true;

                    distancias[AdjList[no][i]] = distancias[no] +1;

                    queueimprov.push_back(AdjList[no][i]);
                };

            // pop imporvisado
            for (int i=1; i<queueimprov.size(); i++){
                queueimprov[i-1] = queueimprov[i];
            };
            queueimprov.pop_back();
            no = queueimprov[0];
        }
}

int main(){
    int n, m, atual = 1, MaxX =-1, MaxY = -1, MaxDist = -1;
    char in; // 'in' stands for 'input'
    std::cin >> n >> m;
    visitou.assign((n*m)+1, false);
    AdjList.assign((n*m)+1, std::vector<int>{});
    distancias.assign((n*m)+1, -1);
    // vou usar o 0 como source falso, pra fazer o multisource

    std::vector<char> dummy; dummy.assign(m, ' ');
    InputMtrx.assign(n, dummy);

    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            std::cin>>in;
            InputMtrx[i-1][j-1] = in;

            if (in != '#'){
                if (in == 'P') AdjList[0].push_back(atual);

                if (j > 1 && InputMtrx[i-1][j-2] != '#'){
                    AdjList[atual].push_back(atual - 1);
                    AdjList[atual - 1].push_back(atual);
                };

                if (atual > m && InputMtrx[i-2][j-1] !='#'){
                    AdjList[atual].push_back(atual - m);
                    AdjList[atual-m].push_back(atual);
                };
            };
            atual++; // da pra calcular isso iterativamente mas isso deixa melhor de ler
        };
    };

    BFS(0);


    for (int i=1; i<distancias.size(); i++){
        std::cout << distancias[i] << ' ';
        if (distancias[i] > MaxDist){
            MaxDist = distancias[i];
            MaxY = (i%m);
            MaxX = (i/m)+1;
        }

        if (!(i%m)) std::cout << std::endl;
    }
    

    std::cout << MaxX << ' ' << MaxY << ' ' << MaxDist;
    return 0;
};