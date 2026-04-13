# Fila de Times
A entrada contém um ou mais casos de teste. Cada caso de teste começa com o
número de times t (1 ≤ t ≤ 1000).
 
Em seguida, seguem t descrições de times. Cada descrição consiste em um
inteiro indicando a quantidade de elementos do time, seguido dos próprios
elementos. Os elementos são inteiros no intervalo 0..999999. Um time pode
ter até 1000 elementos.
 
Por fim, segue uma lista de comandos. Há três tipos de comandos:
 
  ENQUEUE x  —  insere o elemento x na fila de times
  DEQUEUE    —  processa e remove o primeiro elemento da fila
  STOP       —  fim do caso de teste
 
A entrada é encerrada quando t = 0.


## Input Specification
A entrada contém um ou mais casos de teste. Cada caso de teste começa com o
número de times t (1 ≤ t ≤ 1000).
 
Em seguida, seguem t descrições de times. Cada descrição consiste em um
inteiro indicando a quantidade de elementos do time, seguido dos próprios
elementos. Os elementos são inteiros no intervalo 0..999999. Um time pode
ter até 1000 elementos.
 
Por fim, segue uma lista de comandos. Há três tipos de comandos:

- ENQUEUE x  —  insere o elemento x na fila de times

- DEQUEUE    —  processa e remove o primeiro elemento da fila

- STOP       —  fim do caso de teste
 
A entrada é encerrada quando t = 0.

## Output Specification
Para cada caso de teste, imprima primeiro uma linha com 'Scenario #k', onde k
é o número do caso de teste (começando em 1).
 
Em seguida, para cada comando DEQUEUE, imprima o elemento removido em uma
linha separada.
 
Imprima uma linha em branco após cada caso de teste, inclusive após o último.

---
#### Sample Input #1
    3
    1 5
    1 10
    1 15
    ENQUEUE 5
    ENQUEUE 10
    ENQUEUE 15
    DEQUEUE
    DEQUEUE
    DEQUEUE
    STOP
    2
    2 1 2
    2 3 4
    ENQUEUE 1
    DEQUEUE
    ENQUEUE 3
    ENQUEUE 2
    ENQUEUE 4
    DEQUEUE
    DEQUEUE
    DEQUEUE
    STOP
    0
#### Sample Output #1
    Scenario #1
    5
    10
    15

    Scenario #2
    1
    3
    4
    2
