# Escalonador de Tarefas Críticas
Uma empresa de engenharia possui um sistema de tarefas onde cada tarefa tem um identificador, uma prioridade e um tempo de execução em minutos. O sistema opera da seguinte forma:

A cada ciclo, o sistema executa a tarefa de maior prioridade disponível. Se duas tarefas tiverem a mesma prioridade, executa aquela com menor tempo de execução. Se ainda houver empate, executa a de menor identificador (lexicograficamente).

O sistema recebe eventos em ordem cronológica. Cada evento é um dos seguintes:

ADD id prioridade tempo — adiciona uma tarefa à fila.
RUN — executa a próxima tarefa segundo as regras acima e imprime seu id. Se não houver tarefas, imprime IDLE.
BOOST k — aumenta em k a prioridade de todas as tarefas atualmente na fila (mas não da que está em execução, pois nenhuma está).

Dado a sequência de eventos, simule o escalonador.

## Input Specification
A primeira linha contém um inteiro Q (1 ≤ Q ≤ 100.000), o número de eventos.
As próximas Q linhas contêm cada evento conforme descrito. Prioridades e tempos são inteiros positivos (1 ≤ prioridade, tempo ≤ 10⁹). Identificadores são strings de até 20 caracteres alfanuméricos.

## Output Specification
Para cada evento RUN, imprima em uma linha o identificador da tarefa executada ou IDLE.

## Notes
O BOOST ingênuo (atualizar cada elemento) pode ser O(N) por operação — reflita se é possível evitar isso com uma variável de offset global acumulada. A estrutura de heap precisará comparar tuplas com múltiplos critérios.

## Specs
Time Limit: 2 seconds  
Memory Limit: 768 MB  
Output Limit: 4 MB  

---
#### Sample Input #1
    5
    ADD t1 7 100
    ADD t2 7 30
    ADD t3 7 60
    RUN
    RUN

#### Sample Output #1
    t2
    t3

---
#### Sample Input #2
    5
    ADD baixa 1 5
    ADD alta 10 5
    ADD media 5 5
    RUN
    RUN

#### Sample Output #2
    alta
    media

