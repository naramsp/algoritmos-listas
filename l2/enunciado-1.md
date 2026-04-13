# Maratona CIn
No último final de semana, ocorreu a Maratona Internacional do Centro de Informática. Considerando a quantidade surpreendente de concluintes, a organização pediu a sua ajuda para ordenar os resultados. Os participantes que concluíram a corrida devem ser listados daqueles com menor tempo para aqueles com maior tempo de prova; eventuais empates são resolvidos pela ordem alfabética (lexicográfica) do nome dos participantes.


## Input Specification
A primeira linha da entrada contém o número 0 < c <= 100.000 de concluintes. Em cada uma das próximas c linhas, tem-se o nome n do c-ésimo participante (0 < |n| <= 30 letras minúsculas, sem espaço) e o seu tempo t de prova em segundos (0 < t <= 21.600). Na entrada, os participantes são listados em ordem lexicográfica.

## Output Specification
Imprima os resultados ordenados corretamente.

## Notes
Em C/C++, declare a main retornando "int".

Em C/C++, considere usar a função char* strcpy(char* destination, const char* source); para copiar strings entre variáveis. Esta função é definida no arquivo string.h. Veja o exemplo abaixo. Ao executar este código, o valor “abc” é impresso na saída padrão.

#include <stdio.h> #include <string.h>

int main() { char nome1[30] = "abc"; char nome2[30]; strcpy(nome2, nome1); printf("%s\n", nome2); return 0; }

## Specs
Time Limit: 1 second  
Memory Limit: 768 MB  
Output Limit: 4 MB

---
#### Sample Input #1
    8
    alice 8044
    ana 20400
    daniel 7299
    eliud 7199 
    gustavo 20400
    laura 8044
    sophia 15000
    vanderlei 7399

#### Sample Output #1
    eliud 7199
    daniel 7299
    vanderlei 7399
    alice 8044
    laura 8044
    sophia 15000
    ana 20400
    gustavo 20400

