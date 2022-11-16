# Créé par satheoulle, le 23/02/2021 en Python 3.7
def lettres(phrase):
    """fonction qui permet de retirer les espaces de la clé de cryptage"""
    phrase2=""
    for i in phrase:
        if ord(i)>=65 and ord(i)<=90:
            phrase2+=i
    return phrase2
l=[chr(65+i) for i in range (26)]           #construction d'une liste qui contient toutes les lettres en majuscule
message=input("donne la phrase a coder")
clé=input("donne la clé de chiffrement")

clé=lettres(clé)            #retire les espaces

taillem=len(message)        #taille de la phrase a coder
taillec=len(clé)               #taille de la phrase clé
texte=""

for i in range(0,taillem):          #on parcours la liste sur toute sa longueur
    if message[i] in l:             #si la lettre est en majuscule
        if i>taillec-1:             #on verifie que la taille de la clé soit inferieure au i de la taille de la liste (modulo)
            h=i-taillec
        else:
            h=i
        saut=ord(clé[h])-65         #on recupere la taille du saut
        m=chr(ord(message[i])+saut)         #on calcul la nouvelle lettre cryptée
        if ord(m)>90:                   #si la lettre cryptée n'est pas dans les majuscules (modulo)
            texte+=chr(ord(m)-26)
        else:
            texte+=m
    else:
        texte+=message[i]           #si ce n'est pas une majuscule, on incrémente sans changer le caractère


print(texte)



