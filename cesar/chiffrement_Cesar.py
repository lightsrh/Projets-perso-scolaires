def chiffrement(cle):
    """fonction pour chiffrer le texte """
    with open ("cesar_original.txt","r") as texte_non_chiffre:          #ouvrir le fichier non crypté
        with open("ecrire.txt","w") as texte_chiffre:                       # ouvrir le fichir vide dans lequel ecrire
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
cle_chiffre=int(input("donne la clé"))
print(chiffrement(cle_chiffre))
