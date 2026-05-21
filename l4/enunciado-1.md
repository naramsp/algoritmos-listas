# Sirene nas Ruas  

  Um caminhão de bombeiros precisa ir da delegacia (cidade S) até o local da emergência (cidade T) o mais rápido possível. As cidades são conectadas por ruas bidirecionais, cada uma com um tempo de travessia em segundos.

Alguns cruzamentos possuem semáforos: ao sair de um cruzamento com semáforo, o caminhão deve aguardar o tempo indicado antes de prosseguir. O semáforo da cidade de partida também é respeitado ao sair dela. O semáforo da cidade de destino não precisa ser aguardado, pois o caminhão já chegou.
Determine o tempo mínimo para chegar à emergência.

---
## Input Specification
A primeira linha contém quatro inteiros N, M, S e T.   
A segunda linha contém N inteiros d[1], d[2], ..., d[N], onde d[i] é o tempo de espera no semáforo da cidade i (zero se não houver semáforo).   
Cada uma das próximas M linhas contêm três inteiros u, v e w, indicando uma rua bidirecional entre u e v com tempo de travessia w.

---
## Restrições: 
* 2 ≤ N ≤ 100.000 
* 1 ≤ M ≤ 200.000 
* 1 ≤ S, T ≤ N, com S ≠ T
* 0 ≤ d[i] ≤ 1.000 
* 1 ≤ w ≤ 10.000

---
## Output Specification
Imprima um único inteiro com o tempo mínimo em segundos para ir de S até T. Caso não haja caminho, imprima IMPOSSIVEL.