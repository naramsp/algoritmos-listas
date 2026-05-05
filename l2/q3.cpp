// FOI!!!!!
# include <iostream>
using namespace std;

struct tarefa {
    string nome;
    int prioridade;
    int tempo; 
};

tarefa banco;

bool checkBig (tarefa folha, tarefa raiz){
    if (folha.prioridade > raiz.prioridade) return true;

    else if (folha.prioridade == raiz.prioridade){
        if (folha.tempo < raiz.tempo) return true;

        else if (folha.tempo == raiz.tempo){
            if (folha.nome < raiz.nome) return true;
        }
    }

    return false;
}

void heapfy(tarefa heap [], int sz){
	for (int i=sz; i>-1; i--){  

        if ((i<<1)+1 < sz+1){
            if (checkBig(heap[(i<<1)+1], heap[i])) {

                banco = heap[(i<<1)+1];
                        heap[(i<<1)+1] = heap[i];
                        heap[i] = banco;
            }
        
            else if ((i<<1)+2 < sz+1){
                if (checkBig(heap[(i<<1)+2], heap[i])) {
                    banco = heap[(i<<1)+2];
                            heap[(i<<1)+2] = heap[i];
                            heap[i] = banco;
                }
            }
        };
	}
}

void add(tarefa heap[], string nome, int p, int t, int & sz){
    heap[sz] = tarefa{nome, p, t};
    heapfy(heap, sz);
    sz++;
}

void remove (tarefa heap[], int & sz){
    if (sz){
        cout << heap[0].nome << endl;
        
        banco = heap[0];
        heap[0] = heap[--sz];
        heap[sz] = banco;

        heapfy(heap, sz-1);
    }
    else cout << "IDLE" << endl;
}

int main(){

    // termos: prioridade < tempo < nome
    // parecido com a q2

    // a questao diz pra usar heap ne. faz sentido..?

    int q, ocupado = 0, desvio =0; 
    cin >> q;
    string in;

    string n;
    int pri, tmp;

    tarefa escal [q];
    
    while(q--){
    	cin >> in;

    	if (in == "ADD"){
            cin >> n >> pri >> tmp;
    		add(escal, n, pri - desvio, tmp, ocupado);

    	} else if (in == "RUN") remove(escal, ocupado);

        else if (in == "BOOST"){
            cin >> pri;
            desvio += pri; // se as na fila recebem boost, todas as que virem estao "desboostadas" pelo msm valor
        }
    }



    return 0;
}