#include <iostream>
#include <vector>
using namespace std; 
int banco;

void heapfy(vector<int> & heap, int sz){	
	for(int i=sz; i>-1;  i--){
		if ((i<<1)+2<sz+1) {
				if (heap[i]<heap[(i<<1)+2] || heap[i]<heap[(i<<1)+1]) {
					if (heap[(i<<1)+1]>heap[(i<<1)+2]) {
						banco = heap[(i<<1)+1];
						heap[(i<<1)+1] = heap[i];
					} else {
						banco = heap[(i<<1)+2];
						heap[(i<<1)+2] = heap[i];
					};
					heap[i] = banco;
				};
			} else if ((i<<1)+1<sz+1){
				if (heap[i] < heap[(i<<1)+1]){
					banco = heap[(i<<1)+1];
					heap[(i<<1)+1] = heap[i];
					heap[i] = banco;
				};
			};
	}
	// nao dá pra cancelar os +2 com +1 pq o indice base é zero, nao um
}

int main(){
	// com TL em 5 segundos e vetor maximo 10^6, em teeese isso passa ate com O(n) = n²
	// em teeeeeeese
	// ent da pra fazer sla insert sort
	
	
	/* contra-argumento: heap sort é mais legal.*/
	
	vector<int> sort;
	int in, n; cin >> in;
	
	for (int c =0; c<in; c++){
		cin >> n;
		sort.push_back(n);
	}
	
	while(in--){
		heapfy(sort, in);
		cout << sort[0] << endl;
		banco = sort[in];
		sort[in] = sort[0];
		sort[0] = banco;
	}

	// FUNCIONA, mas o array fica ao contrario

	
	return 0;
}
