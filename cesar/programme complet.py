def chiffrement(cle):
    """fonction pour chiffrer le texte """
    with open ("cesar_original.txt","r") as texte_non_chiffre:          #ouvrir le fichier non crypté
        with open("cesar_a_decoder.txt","w") as texte_chiffre:                       # ouvrir le fichir vide dans lequel ecrire
            for i in texte_non_chiffre:                                 # parcourir le texte non chiffré (ligne par ligne)
                for j in i:                                             #parcourir le texte lettre par lettre (ligne par ligne)
                    index = ord(j)                                          #trouver le code ascii
                    if index == 10:                                             #si c'est un retour à la ligne
                        lettre = chr(index)                                     #retrouver la lettre qui correspod
                        texte_chiffre.write(lettre)                             #ecrire la lettre dans le fichier
                    else :
                        index += cle                                           #ajouter à ce code la clé
                        lettre = chr(index)                                     #retrouver la lettre qui correspod
                        texte_chiffre.write(lettre)                             #ecrire la lettre dans le fichier
cle_chiffre=input("donner la clé de chiffrement")
if ord(str(cle_chiffre))>=48 and ord(str(cle_chiffre))<=57:
    chiffrement(int(cle_chiffre))
else :
    while ord(str(cle_chiffre))<48 or ord(str(cle_chiffre))>57:
        cle_chiffre=input("donner un nombre !")
    chiffrement(int(cle_chiffre))




def déchiffrement_Cesar(clé):
    """prend en entrée la clé, ouvre le document à déchiffrer et retourne dans la console le fichier décoder"""
    fichier=open("cesar_a_decoder.txt","r")                                         #ouvre le fichier césar à décoder présent dans le même dossier que le programme
    TexteFinale=[]                                                                  #crée la variable dans laquelle sera retourné le fichier déchiffrer
    for i in fichier:                                                              #parcours les lignes du fichiers
        TexteFinale.append(chr(10))
        for j in i:                                                                 #parcours les caractères de la lignes
            a=ord(j)                                                                # variable dans laquelle le code ASCII du caractère est stocké
            if a==32 or a==33 or a==46 or a==45 or (a>=48 and a<=57):               #si le caractère est un espace ou une ponctuation, reproduit ce caractère a l'identique
                TexteFinale.append(j)
            elif a==10:
                TexteFinale.append(j)
            elif a>=97 and a<=122:                                                  #déchiffre les minuscules
                TexteFinale.append(chr(a-clé))
            elif a>=65 and a<=90:                                                   #déchiffre les majuscules
                TexteFinale.append(chr(a-clé))
    TexteFinale1="".join(TexteFinale)                                               #met le déchiffrage sous la forme d'une chaine de caractère
    return TexteFinale1



#a=déchiffrement_Cesar(cle_chiffre)
#print(a)