# input feito pra testar os limites da Q3:
'''
print("100000")

for i in range(100000):
    print("10000", end=" ")

print()

for i in range (100000-1):
    print (i+1, i+2 )




VERSAO ALTERNATIVA
esse input é tao grande q mts vezes nem vai normalment, ent eu tenho q colocar no meio do codigo e desabilitar o std::cin
pra sequer rodar

depois eu vou e apago manualmente a última vírgula
'''
print("int input[100000] = {")

for i in range(100000):
    print(i+1, ", ", i+2, ",")

print('}')

