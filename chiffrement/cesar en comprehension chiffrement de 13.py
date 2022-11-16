# Créé par satheoulle, le 23/02/2021 en Python 3.7
d={chr(65+i):chr(65+(13+i)%26) for i in range (26)}

print(d)
phrase=input("donne la phrase a coder")
texte=""                    #texte qui sera codé
for lettre in phrase:
    if lettre in d:             #si le caractere examiné est dans le dictionnaire de chiffrage
        texte+=d[lettre]        #on le code avec une clé de 13
    else:
        texte+=lettre           #on remplace le caractere tel quel
print(texte)