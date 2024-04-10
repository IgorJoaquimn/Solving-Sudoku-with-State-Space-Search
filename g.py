import numpy as np
a = "This_can3t_be_solved_by_brute_force."
m = 5


get_size = lambda x: np.unique(np.array(list(x))).size

lenn = 1
start = 0

for i in range(len(a)):
    s = "".join(a[start:i])
    size = get_size(s)
    if(size >= m):
        if(i+1 == len(a)):
            break
        if(a[start] != a[i+1]):
            while(get_size(s) != m):
                start +=1
                s = "".join(a[start:i+1])
    print(s,size,len(s))
    
    # print("".join(c[1:] + [i]),np.unique(np.array(c[1:] + [i])).size)
    # c = c[1:] + [i]
    # print()