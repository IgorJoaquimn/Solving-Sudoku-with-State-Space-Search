import numpy as np
string = "Mississipi."
m = 1

get_size = lambda x: np.unique(np.array(list(x))).size

# Comeco com o primeiro
start = 0

for quero_colocar in range(1,len(string)):
    # Tento colocar o i-esimo no vetor
    while(get_size(string[start:quero_colocar]) > m): # enquanto eu tiver mais de m distintos
        start +=1 # aumento 1 
    print(string[start:quero_colocar],get_size(string[start:quero_colocar]),quero_colocar-start)