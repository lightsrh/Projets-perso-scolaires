# Créé par satheoulle, le 25/02/2021 en Python 3.7
from math import sqrt
def qun(p,q):
    """calculer n et f, n produit de deux nombres premuiers q et p, f produit avec q et p"""
    f = (p-1)*(q-1)
    n=p*q
    return f,n

def trouverD(e,f,n):
    """permet de calculer d pour la clé privé avec e et f"""
    d=0
    while d<n:              #
        if (e*d)%f==1:      #si le reste de la division euclidienne de ed par f =1
            return d        #on a trouvé d
        else:
            d+=1

def rsa(charac,e,n):
    """prend charac, e et n et renvoie le message chiffré"""
    m=""
    for i in charac:        #on parcourt les differents caracteres
        m+=str(ord(i)-54)      #on recupere le copde ascii
    m=int(m)               #on le retrouve en forme str
    c=(m**e)%n              #le message chiffré est le reste dans la division euclidienne de m^^e par n
    return m,c

def dechiffrer(c,d,n):
    var=1
    for i in range(1,d+1):          #on fait une boucle à d passages
        var=(var*c)%n
    return var

def fonction_pour_decoupage():
    """ne fonctionne pas"""
    taille=len(charac)
    l=[]
    if taille>3:
        for i in range(0,taille-3,3):
            morceau=charac[i]+charac[i+1]+charac[i+2]
            l[i]=morceau
            print(l)

def recomposer(dechiffrage):
    """prends en parametre le nombre a dechiffrer et renvoie la phrase de départ"""
    dechiffrage=str(dechiffrage)
    liste=[]
    phrase=""
    for i in range(0,len(dechiffrage)-1,2):
        liste.append(dechiffrage[i]+dechiffrage[i+1])
    for i in liste:
        phrase=phrase+chr(int(i)+54)
    return liste,phrase

p=6991
q=7529
f,n=qun(p,q)
print("f et n:",f,n)             #affichage de f et n
e=23            #nombre premier inferieur a f
m,c=rsa("RSA",e,n)          #message a trois lettres en majuscules ou minuscules
print("m et c :",m,c)                #affichage de m et c
d=trouverD(e,f,n)
print("d :",d)                    #affichage de d
dechiffrage=dechiffrer(c,d,n)
print("dechiffrage :",dechiffrage)
print(recomposer(dechiffrage))
#rajouter 64 a m
