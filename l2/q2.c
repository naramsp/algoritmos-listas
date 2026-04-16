#include <stdio.h>
int banco;

void heapfy(int heap[], int sz){	
	short tam=1; while ((tam<<1) < sz) tam<<=1; // exclusao de folhas

	for(int i=tam; i>-1;  i--){
		if ((i<<1)+2 < sz+1) {
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
			} else if ((i<<1)+1 < sz+1){
				if (heap[i] < heap[(i<<1)+1]){
					banco = heap[(i<<1)+1];
					heap[(i<<1)+1] = heap[i];
					heap[i] = banco;
				};
			};
	}
	// nao da pra cancelar os +1 e +2 nos checks com size sem usar <=, por causa da indexaçao com zero
}

int main(){
	// afffffff TLE
	
	/* heap sort eh mais legal. */

	int in, n; scanf("%i", &in);

	int sort[in];

	for (int c =0; c<in; c++){
		scanf("%i", &n);
		sort[c] = n;
	}
	
	int inclone = in;

	while (--in){
		heapfy(sort, in);
		banco = sort[in];
		sort[in] = sort[0];
		sort[0] = banco;
	}

	for(int i=0; i<inclone; i++) printf("%i\n", sort[i]);
	
	return 0;
}
