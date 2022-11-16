cle_chiffre=input("donner la clé de chiffrement")
if ord(str(cle_chiffre))>=48 and ord(str(cle_chiffre))<=57:
    chiffrement(int(cle_chiffre))
else :
    while ord(str(cle_chiffre))<48 or ord(str(cle_chiffre))>57:
        cle_chiffre=input("donner un nombre !")
    chiffrement(int(cle_chiffre))