#include <iostream>

struct no{
    int v; //alor
	no * e = nullptr; // squerda
    no * d = nullptr; // ireita

};

class BST{
	private:
		no* head = new no;

        void printsubtree(no* cur){ // print em pós-ordem
            
            if (cur->e) printsubtree(cur->e);
            if (cur->d) printsubtree(cur->d);
            std::cout << cur->v << std::endl;
            
            //  nao gosto de recursao mas a versao iterativa dessa função usa stack 😩

        }

    public:
    	BST(int ini){
            head->d = nullptr;
            head->e=nullptr;
            head->v = ini;
        }	

        /*~BST(){
            
            // TOP 10 ALGORITMOS MAIS INEFICIENTES JÁ INVENTADOS PELAS MENTES HUMANAS:
            while (head->e != nullptr || head->d != nullptr){
                no*cur = head->e;

                while (cur->e->e != nullptr){
                    cur = cur->e;
                }
                // para quando chega no penultimo elemento mais a esquerda da arvore
                delete cur->e;

                while (cur->d != nullptr) cur = cur->d;
                delete cur;
            }

            // ta dando segfault e eu nao sei qual éé o problema, desisto !
        }*/

    	void adicionar(int adc){
            no*novo = new no;
            novo->v = adc;
			no * cur = head;

            while(true){
				if (cur->v > adc){
                    if (cur->e) cur = cur->e;
                    else {
						cur->e = novo;
						break;
                    }
                }

                else {
                    if (cur->d) cur = cur->d;
                    else {
                        cur->d = novo; 
                        break;
                    };
                }
            }
        };
        

        void printree(){
            printsubtree(head);
        }


};

int main(){

    int in; std::cin >> in;

	BST tre(in);

    while (std::cin>>in) tre.adicionar(in);

    tre.printree();
    
    return 0;
} 

