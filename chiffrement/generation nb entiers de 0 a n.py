# Créé par satheoulle, le 25/02/2021 en Python 3.7
lE=[]
for n in range(0,100):
   if n > 1:
       for i in range(2,n):
           if (n % i) == 0:
               break
       else:
           lE.append(n)
for i in lE:
    if i<f:
        e=i
        break
print(lE)
