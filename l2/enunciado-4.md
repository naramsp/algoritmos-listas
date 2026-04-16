# Invetário de Laboratório
Um laboratório recebe e consome reagentes químicos diariamente. Cada reagente é identificado por um nome (string). O sistema precisa responder eficientemente a três tipos de operações:

ENTRADA nome quantidade — adiciona quantidade unidades do reagente ao estoque.
CONSUMO nome quantidade — remove quantidade unidades do estoque. Se o estoque do reagente ficar com zero ou menos, ele é removido completamente do inventário.
CONSULTA nome — imprime a quantidade atual do reagente, ou AUSENTE se ele não existir.
CRITICOS k — imprime em ordem crescente de quantidade os nomes de todos os reagentes cujo estoque é menor ou igual a k. Se dois reagentes tiverem a mesma quantidade, ordene pelos nomes em ordem lexicográfica. Se não houver nenhum, imprima NENHUM.

## Input Specification
A primeira linha contém N (1 ≤ N ≤ 200.000), o número de operações.
Cada uma das N linhas seguintes contém uma operação. Quantidades são inteiros positivos (1 ≤ quantidade ≤ 10⁶). Nomes têm até 30 caracteres (apenas letras e dígitos).

## Output Specification
Para cada operação CONSULTA ou CRITICOS, imprima a resposta conforme descrito.

## Notes
A operação CRITICOS exige varrer o inventário — reflita sobre a complexidade desta operação em função do número de reagentes distintos no estoque. A tabela hash resolve acesso em O(1), mas a filtragem e ordenação têm custo adicional. Como isso afeta o tempo total?

## Specs
Time Limit: 1 second  
Memory Limit: 768 MB  
Output Limit: 4 MB  

---
#### Sample Input #1
    4
    ENTRADA agua 100
    CONSULTA agua
    CONSULTA sal
    CONSULTA agua

#### Sample Output #1
    100
    AUSENTE
    100

---
#### Sample Input #2
    8
    ENTRADA acido 50
    CONSUMO acido 20
    CONSULTA acido
    CONSUMO acido 25
    CONSULTA acido
    CONSUMO acido 10
    CONSULTA acido
    CONSULTA acido

#### Sample Output #2
    30
    5
    AUSENTE
    AUSENTE

---
#### Sample Input #3
    7
    ENTRADA a 5
    ENTRADA b 10
    ENTRADA c 3
    ENTRADA d 8
    CRITICOS 6
    CRITICOS 3
    CRITICOS 0

#### Sample Output #1
    c 3
    a 5
    c 3
    NENHUM
