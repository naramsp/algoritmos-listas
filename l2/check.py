# checar ser tá sortado

n1 = int(input())
for index in range(99):
    n2 = int(input())
    if n2 < n1:
        print(f"NAO: {n1}, {n2} tem erro")
        quit()
    
    n1 = n2
    
print("SIM")