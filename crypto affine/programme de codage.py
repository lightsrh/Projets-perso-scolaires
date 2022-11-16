def chiffrement(clea,cleb):
    """fonction pour chiffrer le texte """
    with open ("crypto_affine_original.txt","r") as texte_non_chiffre:          #ouvrir le fichier non crypté
        with open("crypto_affine_vierge.txt","w") as texte_chiffre:                       # ouvrir le fichir vide dans lequel ecrire
            for i in texte_non_chiffre:                                 # parcourir le texte non chiffré (ligne par ligne)
                for j in i:                                             #parcourir le texte lettre par lettre (ligne par ligne)
                    index = ord(j)                                          #trouver le code ascii
                    #print(index)
                    index = ((index-68)*clea+cleb)%26                                          #ajouter à ce code la clé
                    #print(index)
                    index=index+68
                    print(index)
                    lettre = chr(index)                                     #retrouver la lettre qui correspod
                    texte_chiffre.write(lettre)                             #ecrire la lettre dans le fichier
cle_chiffrea=int(input("donne la clé de chiffrement de a"))
cle_chiffreb=int(input("donne la clé de chiffrement de b"))
chiffrement(cle_chiffrea,cle_chiffreb)


