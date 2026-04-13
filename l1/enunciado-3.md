# É uma AVL?
Dada uma Árvore de Busca Binária (BST) representada como estrutura implícita
em um array, determine se ela é uma Árvore AVL válida ou não.
 
REPRESENTAÇÃO IMPLÍCITA EM ARRAY
---------------------------------
Na representação implícita (também chamada de heap-like), os nós da árvore
são armazenados em um array indexado a partir de 0, seguindo esta regra:
 
  - O nó de índice i possui:
      - filho esquerdo no índice  2*i + 1
      - filho direito  no índice  2*i + 2
      - pai no índice  floor((i - 1) / 2)   (exceto para a raiz, índice 0)
 
  - Nós nulos (ausentes) são representados pelo valor -1.

Referência: http://en.wikipedia.org/wiki/Binary_tree#Arrays

DEFINIÇÃO DE ÁRVORE AVL
------------------------
Uma Árvore AVL é uma BST auto-balanceada. Uma BST é considerada AVL se e
somente se, para todo nó da árvore, o fator de balanceamento desse nó está
entre -1 e +1 (inclusive).
 
O fator de balanceamento de um nó é definido como:
 
    fator_balanceamento = altura(subárvore esquerda) - altura(subárvore direita)
 
onde a altura de uma subárvore vazia (nula) é definida como -1, e a altura
de uma folha é 0.
 
Se o fator de balanceamento de qualquer nó for menor que -1 ou maior que +1,
a árvore NÃO é uma AVL.

## Input Specification
A entrada começa com um inteiro t na primeira linha, indicando o número de
casos de teste (1 ≤ t ≤ 100).
 
Cada caso de teste começa em uma nova linha com um inteiro não-negativo n,
seguido de n inteiros separados por espaços (0 ≤ n ≤ 100), onde n é o número
de posições do array usado para armazenar a BST.
 
Os valores dos nós satisfazem 0 ≤ valor_do_nó ≤ 10000.
Nós nulos são representados por -1.

## Output Specification
Para cada caso de teste, imprima 'T' se a BST fornecida for uma Árvore AVL
válida, ou 'F' caso contrário. Cada resposta deve estar em uma linha separada.

---
#### Sample Input #1
    4
    1 5
    3 4 2 6
    7 4 2 6 1 3 5 7
    5 4 2 6 1 -1

#### Sample Output #1
    T
    T
    T
    T

