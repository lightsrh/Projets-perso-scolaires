def chiffrement(cle):
    """fonction pour chiffrer le texte """
    with open ("cesar_original.txt","r") as texte_non_chiffre:                  #ouvrir le fichier non crypté
        with open("ecrire.txt","w") as texte_chiffre:                           # ouvrir le fichier vide dans lequel ecrire
            for i in texte_non_chiffre:                                          #parcourir le texte non chiffré (ligne par ligne)
                for j in i:                                                      #parcourir le texte lettre par lettre (ligne par ligne)
                    index = ord(j)                                               #trouver le code ascii du caractère

                    if index <48 and index>32 or index ==10 or index ==32:       #si le caractère est un caractère spécial
                        lettre = chr(index)                                     #prend le code ascii du caractère
                        texte_chiffre.write(lettre)                             #ecrit ce caractère sans chiffrage dans le texte chiffrer

                    elif index <65 and index>57 :                               #si le caractère est un caractère spécial
                        lettre = chr(index)                                     #prend le code ascii du caractère
                        texte_chiffre.write(lettre)                             #ecrit ce caractère sans chiffrage dans le texte chiffrer

                    elif index <97 and index>90 :                                #si le caractère est un caractère spécial
                        lettre = chr(index)                                     #prend le code ascii du caractère
                        texte_chiffre.write(lettre)                             #ecrit ce caractère sans chiffrage dans le texte chiffrer

                    elif index>=97 and index<=122 :                             #si le caractère est une minuscule
                        index+=cle%26                                            #prend le code ascii de la lettre et lui ajoute la clé
                        if index <=122:
                            lettre = chr(index)                                 #retrouver la lettre qui correspond
                            texte_chiffre.write(lettre)                         #ecrire la lettre dans le fichier

                        else:                                                   #si le code ascii de la lettre + la clé n'est plus une minuscule
                            while index>122:                                    #recommence depuis le début de l'alphabet
                                index+=-26
                            lettre = chr(index)
                            texte_chiffre.write(lettre)

                    elif index>=65 and index<=90:                               #refait la même chose que pour les minuscule mais avec les majuscules
                        index+=cle%26
                        if index <=90:
                            lettre = chr(index)
                            texte_chiffre.write(lettre)
                        else:
                            while index>90:
                                index+=-26
                            lettre = chr(index)
                            texte_chiffre.write(lettre)

                    elif index>=48 and index<=57:                               #refait la même chose pour les nombres
                        index+=cle
                        if index<=57:
                            lettre = chr(index)
                            texte_chiffre.write(lettre)
                        else:
                            while index>57:
                                index+=-10
                            texte_chiffre.write(chr(index))
        temp=open("ecrire.txt","r")
    return temp.read()


def déchiffrement_Cesar(clé):
    """prend en entrée la clé, ouvre le document à déchiffrer et retourne dans la console le fichier décoder"""
    fichier=open("ecrire.txt","r")                                                #ouvre le fichier césar à décoder présent dans le même dossier que le programme
    TexteFinale=[]                                                                  #crée la variable dans laquelle sera retourné le fichier déchiffrer
    for i in fichier:                                                              #parcours les lignes du fichiers
        TexteFinale.append(chr(13))
        for j in i:                                                                 #parcours les caractères de la lignes
            a=ord(j)                                                                # variable dans laquelle le code ASCII du caractère est stocké
            index=a-clé
            if a <48 and a>32 or a==10 or a ==32:                    #si le caractère est un caractère spécial, reproduit ce caractère a l'identique
                TexteFinale.append(j)

            elif a <65 and a>57 :                                         #si le caractère est un caractère spécial, reproduit ce caractère a l'identique
                TexteFinale.append(j)

            elif a <97 and a>90 :                                       #si le caractère est un caractère spécial, reproduit ce caractère a l'identique
                TexteFinale.append(j)

            elif a>=97 and a<=122:                                                  #déchiffre les minuscules
                if (a-clé)>=97:
                    TexteFinale.append(chr(a-clé))
                else:
                    while index<97:
                        index+=26
                    TexteFinale.append(chr(index))
            elif a>=65 and a<=90:                                                  #déchiffre les majuscules
                if (a-clé)>=65:
                    TexteFinale.append(chr(a-clé))
                else:
                    while index<65:
                        index+=26
                    TexteFinale.append(chr(index))
            elif a>=48 and a<=57:                                               #déchiffre les nombres
                if (a-clé)>=48 :
                    TexteFinale.append(chr(a-clé))
                else:
                    while index<48:
                        index+=10
                    TexteFinale.append(chr(index))
    TexteFinale1="".join(TexteFinale)                                               #met le déchiffrage sous la forme d'une chaine de caractère
    return TexteFinale1





A=input("si vous voulez chiffrer entrez 'chiffrer' et si vous voulez déchiffrer entrez 'dechiffrer' ") #demande la volonté de l'utilisateur

def boucle_depart_chiffrement():
    cle_chiffre =input("donne la clé de chiffrement")
    somme = 0
    t=0
    for i in str(cle_chiffre):
        if ord(i) <=57 and ord(i) >=48:
            somme+=1
        t+=1
    if somme==t:
        return int(cle_chiffre)
    else :
        boucle_depart()
def boucle_depart_dechiffrement():
    cle_chiffre =input("donne la clé de déchiffrement(le même que juste avant c'est mieux :))")
    somme = 0
    t=0
    for i in str(cle_chiffre):
        if ord(i) <=57 and ord(i) >=48:
            somme+=1
        t+=1
    if somme==t:
        return int(cle_chiffre)
    else :
        boucle_depart()

if A=="chiffrer":                                                                   #chiffre dans un fichier et print son contenu
    print(chiffrement(boucle_depart_chiffrement()))
    print("Merci d'avoir utilisé notre programme pour chiffrer vos documents")


elif A=="déchiffrer" or A=="dechiffrer" :
    print(déchiffrement_Cesar(boucle_depart_dechiffrement()))                                  #déchiffre le contenu d'un fichier et le renvoie dans la console
    print("Merci d'avoir utilisé notre programme pour chiffrer vos document")


else:                                                                           #si l'utilisateur n'a pas dis si il souhaitait décoder ou coder
    print("merci d'entrer à nouveau ce que vous avez envie de faire")

