#include <iostream>

int main(){

    short t;
    std::cin>>t;

    while (t--){
        
        short tam=1, nos, in, fatbal, e, d;
        bool balanceada = true;
        std::cin >> nos;

        while (tam <= nos) tam <<= 1;

        short*array = new short [--tam];

        ///////////////////////////////

        for (short c = 0; c < nos; c++){
            std::cin >> in;
            array[c] = in;
        }

        for (short c = nos; c<tam; c++) array[c] = -1;


        ////////////////////////////////

        for (short c = tam; c >= (tam>>1); c--) if (array[c] > -1) array[c] = 0;
        tam>>=1; tam--; // todas as folhas que existem tem tamanho zero

        for (short c = tam; c>=0; c--) {
            if (array[c] == -1) continue; // subarvore nao existe

            e = array[(c<<1)+1];
            d = array[(c<<1) + 2];

            fatbal = e - d;

            if (fatbal > 1 || fatbal < -1) {
                balanceada = false; break;
            } else {
                if (e > d) array[c] = e+1;
                else array[c] = d+1;
            }
        }
       
        ////////////////////////////////

        if (balanceada) std::cout <<  'T' << std::endl;
        else std::cout << 'F' << std::endl;

        delete[] array;
    }

    return 0;
}
// ô mds eu tava confundindo fator de balanceamento com alturakk