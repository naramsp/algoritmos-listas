#include <iostream>

struct pessoa{
    int v; //alor
    int p; //ai afasta de mim esse calice
    pessoa*prox = nullptr; //ima na fila

};

class ListaLigada{ //queue-style
    // essa fila fica facil de administrar como uma LL
    private:
        pessoa* sentinela = new pessoa{-1, -1};
        size_t tam = 0;

    public:
        void entra(int val, int time){ // função usada na fila
            pessoa*procura = sentinela;

            while (procura->prox != nullptr){
                procura = procura->prox;

                if (procura->p == time && (procura->prox == nullptr || procura->prox->p != time)) {  // eles tem q entrar ATRAS do time, nao na frente/no meio euachone
                    pessoa*add = new pessoa{val, time, procura->prox};
                    procura->prox = add;
                    return;    
                }
            }

            procura->prox = new pessoa{val, time};
            return;
        }


        int sai(){ // função usada na fila
            pessoa*saindo = sentinela->prox;
            int r = saindo->v;

            sentinela->prox = saindo->prox;
            delete saindo;
            return r;

        }

        int procura(int val){ // função usada na despensa
            pessoa*proc = sentinela->prox;

            while(proc->v != val) proc = proc->prox;
            
            return proc->p;
        }


        void limpa(){ // pra nao ter que lidar com destrutorkk; função usada na despensa
            if (sentinela->prox == nullptr) return;

            pessoa*morte = sentinela->prox;
            pessoa*cova;

            while(morte->prox != nullptr){
                cova = morte->prox;
                delete morte;
                morte = cova;
            }
            return;
        }

};

int main(){
    int t, qnt, p, scenario = 0;

    while (std::cin >> t, t>0){
        scenario ++; 
        // testcases
        

        ListaLigada despensa; // pq estamos literalmente guardando as pessoas para uso futuro
        
        while (t--){
            /// times
            std::cin>>qnt;

            while (qnt--){
                // pessoas por time
                std::cin>>p;
                despensa.entra(p, t);
            }

        }

        ListaLigada fila;

        std::cout << "Scenario #" << scenario << std::endl;
        std::string in;

        while (std::cin >> in, in != "STOP"){
            if (in == "ENQUEUE"){
                std::cin >> p; fila.entra(p, despensa.procura(p));
            }
            else {
                std::cout << fila.sai() << std::endl;
            }
        }
        
        despensa.limpa();
        std::cout << std::endl;
    }


    return 0;
}