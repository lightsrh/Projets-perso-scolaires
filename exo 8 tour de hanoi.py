import exo3_pile_chainée as plc
import exo4_file_chainée as flc
from tkinter import *
from sys import *
#ameliorer les coord des batonnets

def initialisation(n):
    """situation de départ, dessin du fond, des rectangles a deplacer"""
    baton1=toile.create_rectangle(140,200,165,600,fill="white")         #creation des batons de support
    baton2=toile.create_rectangle(375,200,400,600,fill="white")
    baton3=toile.create_rectangle(625,200,650,600,fill="white")
    anneaux =[]                                                         #liste des anneaux
    color=['red','orange','yellow','green','blue','purple','magenta','pink','white']
    x=0
    y=250.5
    for i in range (n):                                                 #dessin de tous les anneaux et affectation a la liste d'anneaux
        coord=(x+20*i,560-40*i,y-12.5*i,600-40*i)
        a=toile.create_rectangle(coord[0],coord[1],coord[2],coord[3],fill=color[i%9])
        anneaux.append((coord,a,color[i%9]))

    return anneaux


def raffraichissement(anneaux):
    """actualisation de la fenetre"""
    toile.delete("all")
    baton1=toile.create_rectangle(140,200,165,600,fill="white")         #creation des batons de support
    baton2=toile.create_rectangle(375,200,400,600,fill="white")
    baton3=toile.create_rectangle(625,200,650,600,fill="white")
    for i in anneaux:                                                   #dessins des anneaux
        coord=i[0]
        a=toile.create_rectangle(coord[0],coord [1],coord[2],coord[3],fill=i[2])



def hanoi(n,pd,pi,pa,d,i,a):
    """fonction recursive qui resout le probleme en gardant en mémoire le parcours a suivre dans une file"""
    global nbm
    if n==1:        #condition d'arret
        h=pa.hauteur()          #hauteur de la pile d'arrivée
        l=pd.depiler()          #depiler le dernier elem de depart
        pa.empiler(l)           #l'empiler sur la pile d'arrivée
        mouvement.enfiler((l,h,a))      #ajouter ce mouvement a la file
        nbm +=1                         #compte le nombre de mouvements
    else:                               #recursif
        hanoi(n-1,pd,pa,pi,d,a,i)
        hanoi(1,pd,pi,pa,d,i,a)
        hanoi(n-1,pi,pd,pa,i,d,a)



def deplacer_anneau(event):
    """fonction appelé par clic sur touche 'up' et qui va faire bouger les pieces en deplacant les anneaux"""
    global mouvement, anneaux
    touche = event.keysym
    if touche=="Up":
        if mouvement.file_vide():
            return IndexError ("fin du programme")
        else:
            Nanneau,hauteur,arrivee=mouvement.defiler()     #on recupere toutes les données des anneaux
            x=Nanneau[1]            #recuperer le numero d'anneau
            Nanneau=x-4

            couleur=anneaux[Nanneau]    #recuperer le tuple qui contient la couleur de l'anneau
            couleur=couleur[2]          #recuperer la couleur de l'anneau

            if arrivee==1:              #recalculer les coordonnées de l'anneau en fonction de sa place d'arrivée
                x=0
                y=250.5
            elif arrivee==2:
                x=245
                y=495.5
            elif arrivee==3:
                x=500
                y=750.5
            coord=(x+20*Nanneau,560-40*hauteur,y-12.5*Nanneau,600-40*hauteur)       #calculer les nouvelles coordonnées de l'anneau
            anneaux[Nanneau]=(coord,Nanneau,couleur)                  #affecter ces coord a la liste d'anneau
            toile.create_rectangle(x+20*Nanneau,560-40*hauteur,y-12.5*Nanneau,600-40*hauteur,fill="gray")       #creer le nouvel anneau
            raffraichissement(anneaux)              #redessiner tous les anneaux


def deplacer_anneau_auto():
    """fonction appelé par clic sur le bouton de deplacement et qui va faire bouger les pieces en deplacant les anneaux automatiquement"""
    global mouvement, anneaux
    if mouvement.file_vide():
            return IndexError ("fin du programme")
    else:
            Nanneau,hauteur,arrivee=mouvement.defiler()     #on recupere toutes les données des anneaux
            x=Nanneau[1]            #recuperer le n d'anneau
            Nanneau=x-4

            couleur=anneaux[Nanneau]
            couleur=couleur[2]

            if arrivee==1:
                x=0
                y=250.5
            elif arrivee==2:
                x=245
                y=495.5
            elif arrivee==3:
                x=500
                y=750.5
            coord=(x+20*Nanneau,560-40*hauteur,y-12.5*Nanneau,600-40*hauteur)       #calculer les nouvelles coordonnées de l'anneau
            anneaux[Nanneau]=(coord,Nanneau,couleur)                  #affecter ces coord a la liste d'anneau
            toile.create_rectangle(x+20*Nanneau,560-40*hauteur,y-12.5*Nanneau,600-40*hauteur,fill="gray")       #creer le nouvel anneau
            raffraichissement(anneaux)              #redessiner tous les anneaux
    fenetre.after(500,deplacer_anneau_auto)


def tourDeHanoi (n,source,intermediaire, destination):
    if n==1:
        Label(fenetre2, text=str("Bouger le disque 1 du baton "+str(source)+' vers le baton'+str(destination))).pack(side=TOP)
        return
    tourDeHanoi(n-1,source,destination,intermediaire)
    Label(fenetre2, text=str("Bouger le disque "+str(n)+'du baton'+str(source)+' vers le baton'+str(destination))).pack(side=TOP)
    tourDeHanoi(n-1,intermediaire,destination,source)

#-----------------------------------------------------------
fenetre = Tk()
texte =Label(fenetre,text="Tour de Hanoi, appuyer sur la fleche du haut pour faire bouger les anneaux", fg = "black")
texte.pack()
toile = Canvas(fenetre, width=800, height = 600, bg='black')        #creation de la fenetre
toile.pack()
fenetre.bind('<Key>',deplacer_anneau)                                   #deplacement

setrecursionlimit(50000)

n=int(input("combiens d'anneaux ? (entre 3 et 6)"))     #choix du nombre d'anneaux

anneaux=initialisation(n)           #dessin d'initialisation

pd=plc.Pile()                   #creation de la pile de depart
for i in range(len(anneaux)):           #empiler les anneaux dans la pile de départ
    pd.empiler(anneaux[i])
pi=plc.Pile()                   #creation de la pile intermédiaire
pa=plc.Pile()                   #creation de la pile d'arrivée
mouvement=flc.File()            #creation de la file qui retient les mouvement

nbm=0                           #initialisation du compteur de mouvements
hanoi(n,pd,pi,pa,1,2,3)            #fonction de récurrence

texte =Label(fenetre,text=str(nbm)+" mouvements a effectuer", fg = "black")
texte.pack()
bouton2=Button(fenetre, text="depart auto", command = deplacer_anneau_auto)     #bouton de depart auto
bouton2.pack()
bouton = Button(fenetre, text="quitter", command = fenetre.destroy)     #bouton de destruction
bouton.pack()

print(mouvement)                    #affichage des mouvement





#-----------------------------
fenetre2 = Tk()
Label(fenetre2,text="Mouvements a effectuer", fg = "black").pack()
tourDeHanoi(n,1,2,3)
bouton = Button(fenetre2, text="quitter", command = fenetre2.destroy)     #bouton de destruction
bouton.pack()

fenetre2.mainloop()
fenetre.mainloop()          #recuperer ce qu'il se passe dans la fenetre