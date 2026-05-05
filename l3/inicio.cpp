// ok, primeiro criar o grafo,
// depois faço as questoes sla

# include <iostream>

# include <vector>

// matriz é melhor pra grafos densos
// lista é melhor pra grafos esparsos
int procura(std::string string, std::vector<std::string> v){
    for (int i = 0; i<v.size(); i++){
        if (v[i] == string) return i;
    }
    return -1;
}

int main(){
    std::vector<std::vector<int>> matadj;
    std::vector<int> dummy;
    std::vector<std::string> convert;
    
    int n, m, k;
    std::string in;
    std::cin>>n >> m;
    dummy.assign(n, 0);
    matadj.assign(n, dummy);
    

    while (m--){
        std::cin >> in;
        int a = procura (in, convert);
        if (a < 0) convert.push_back(in), a = convert.size()-1;

        std::cin >> in;
        int b = procura (in, convert);
        if (b < 0) convert.push_back(in), b = convert.size()-1;

        matadj[a][b] = 1;
        matadj[b][a] = -1;
        // conexao pai-filho, diferente da filho-pai

/*
4
3
marc andre
jose rosa
andre jose
*/

        for (int c = 0; c<matadj.size(); c++){
            if (c == a || c == b) continue;

            if (matadj[a][c] > 0 && matadj[b][c] != matadj[a][c] + 1){ // significa que achou algum pai adicional do pai a
                matadj[b][c] = matadj[a][c] + 1; // coloca b como sucessor
                matadj[c][b] = matadj[c][a] - 1;
                c = 0;
            } 
            else if (matadj[a][c] < 0 && matadj[b][c] != matadj[a][c]-1){
                matadj[b][c] = matadj[a][c]-1;
                matadj[c][b] = matadj[c][a]+1;
                c = 0;
            }

            /*
            if (matadj[b][c] > 0 && matadj[a][c] != matadj[b][c] + 1){ // significa que achou algum pai adicional do pai a
                matadj[a][c] = matadj[b][c] + 1; // coloca b como sucessor
                matadj[c][a] = matadj[c][b] - 1;
                c = 0;
            } 
            else if (matadj[b][c] < 0 && matadj[b][c] != matadj[b][c]-1){
                matadj[a][c] = matadj[b][c]-1;
                matadj[c][a] = matadj[c][b]+1;
                c = 0;
            }*/
        }
        // pra cada a, vc tem os parentes possiveis 
        // a-b
        //so q c-a
        // ent temos a conexao c-a-b
        // ent eu tenho q alterar [c][b] pra ser [c][a]+1
    };

    //////////////////////////////// test ///////////////////////////
    std::string parentesco;
    for (int i = 0; i < matadj.size(); i++){
        for (int j = 0; j < matadj.size(); j++){
            std::cout << convert[i] << " é ";
            
            switch (matadj[i][j])
            {
            case -1:
                parentesco = "filho";
                break;
            
            case -2:
                parentesco = "neto";
                break;
            
            case -3:
                parentesco = "bisneto";

            case 1:
                parentesco = "pai";
                break;
            
            case 2:
                parentesco = "avô";
                break;

            case 3:
                parentesco = "bisavô";
                break;

            default:
                parentesco = "brug";
                break;
            }

            std::cout << parentesco << " de " << convert[j] << std::endl;
        }
    }

    return 0;
}