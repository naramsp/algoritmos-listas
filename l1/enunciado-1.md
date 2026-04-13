# Árvore de Busca Binária (Binary Search Tree)
Uma Árvore de Busca Binária (BST — Binary Search Tree) é uma árvore binária
que satisfaz a seguinte propriedade: para qualquer nó N da árvore, todos os
valores na subárvore esquerda de N são estritamente menores do que o valor de
N, e todos os valores na subárvore direita de N são estritamente maiores do
que o valor de N.
 
A inserção em uma BST é feita da seguinte forma: começa-se pela raiz e,
a cada nó visitado, desce-se para a subárvore esquerda se o valor a inserir
for menor do que o valor do nó atual, ou para a subárvore direita se for
maior. O novo elemento é inserido quando se chega a uma posição vazia (nula).
 
O percurso em pré-ordem (preorder) de uma árvore visita os nós na seguinte
ordem: raiz, subárvore esquerda, subárvore direita.
 
O percurso em pós-ordem (postorder) de uma árvore visita os nós na seguinte
ordem: subárvore esquerda, subárvore direita, raiz.
 
Dado o percurso em pré-ordem de uma BST, sua tarefa é determinar o percurso
em pós-ordem dessa mesma árvore.


## Input Specification
A entrada contém uma sequência de inteiros distintos separados por espaços e/ou quebras de linha, representando o percurso em pré-ordem de uma BST.
 
A entrada é encerrada pelo fim do arquivo (EOF).
 
Não há informação prévia sobre a quantidade de elementos. O número de
elementos pode variar, mas todos cabem em memória.

## Output Specification
Imprima o percurso em pós-ordem da BST, com um elemento por linha.

---
#### Sample Input #1
    5 3 7
#### Sample Output #1
    3
    7
    5
---
#### Sample Input #2
    1 2 3 4 5
#### Sample Output #2
    5
    4
    3
    2
    1
