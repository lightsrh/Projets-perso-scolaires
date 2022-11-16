from tkinter import *
from Class import *
from Resolution import *

import random as rd
import math as m

def clic_Gauche(event):
    """Lorsque le clique gauche est utilise sur le tableau"""
    global xtableau_souris,ytableau_souris  #recuperation des coordonnees
    xtableau_souris=event.x
    xtableau_souris=xtableau_souris//25
    ytableau_souris=event.y
    ytableau_souris=ytableau_souris//25
    event_clic_gauche(xtableau_souris,ytableau_souris)      #appel a la fonction qui gere la case

def event_clic_gauche(x,y):
    """fonction pour afficher quelle case est selectionnee, et lui attribuer une valeur"""
    global xhaut,yhaut,xbas,ybas
    yhaut=y*25+25
    ybas=y*25
    xhaut=x*25
    xbas=x*25+25
    toile.create_rectangle(xhaut,yhaut,xbas,ybas,fill='red')        #changement de couleur la case

def clavier(event):
    try:
        touche=int(event.keysym)          #recuperer la valeur de la touche
        liste[xtableau_souris][ytableau_souris]=touche           #affecter la valeur au tableau
        toile.create_rectangle(xhaut,yhaut,xbas,ybas,fill='pink')
        toile.create_text(xhaut+12,yhaut-12,text=touche)         #afficher la valeur sur la grille
    except:
        print('Erreur : vous devez rentrer un entier compris entre 0 inclus et 10 exclus')
        toile.create_rectangle(xhaut,yhaut,xbas,ybas,fill='white')       #affichage des cases

def detruire():
    fenetre.destroy()
    sudoku = implementationSudoku(liste)
    resolutionRecursive(sudoku)
    resoudre(recuperationListe(sudoku))

def resoudre(sudokuResolu):
    """fonction de generation de la grille avec les reponses"""
    fenetre=Tk()
    fenetre.title("Resolution")
    toile=Canvas(fenetre, width=25*(n**2), height=25*(n**2), bg='#FFF')     #creer la fenetre (feuille, largeur, hauteur, couleur en rvb hexadecimale)
    toile.pack()            #toile se met au centre de la fenetre. gere dans l'ordre d'arrivee
    case=[[toile.create_rectangle(i*25,j*25,(i+1)*25,(j+1)*25) for i in range(n**2)] for j in range(n**2)]  #creation des cases
    for i in range(len(sudokuResolu)):         #on parcours la liste pour pouvoir l'afficher
        for j in range(len(sudokuResolu[i])):
            if sudokuResolu[i][j]!=0:
                yhaut=j*25+25
                ybas=j*25
                xhaut=i*25
                xbas=i*25+25
                toile.create_rectangle(xhaut,yhaut,xbas,ybas,fill='pink')       #affichage des cases
            toile.create_text(i*25+12,j*25+13,text=sudokuResolu[i][j])         #affichage des nombres dans les cases

def dessiner(n):
    """fonction pour dessiner le quadrillage de depart """
    global liste, toile, fenetre, xtableau_souris,ytableau_souris
    xtableau_souris,ytableau_souris=-2,-2
    liste=[]  #creation de la liste pour stocker les valeurs
    for a in range(n**2):       #creation de la liste (2 boucles)
        liste.append([])
    for a in range(n**2):
        for b in range(n**2):
            liste[a].append(0)
    n=n**2
    fenetre=Tk()
    fenetre.title("Sudoku")
    fenetre.resizable(width=False,height=False)
    toile = Canvas(fenetre, width=25*n, height=25*n, bg='#FFF')     #creer la fenetre (feuille, largeur, hauteur, couleur en rvb hexadecimale)
    [[toile.create_rectangle(i*25,j*25,(i+1)*25,(j+1)*25) for i in range(n)] for j in range(n)]    #creer les carreaux dont les coord sont en i pour x et j pour y
    toile.create_line(2,2,2,toile.cget("width"))
    toile.create_line(2,2,toile.cget("height"),2)
    for i in range(int(m.sqrt(n))) :
        toile.create_line(0,i*25*int(m.sqrt(n)),toile.cget("width"),i*25*int(m.sqrt(n)),width=3)
        toile.create_line(i*25*int(m.sqrt(n)),0,i*25*int(m.sqrt(n)),toile.cget("height"),width=3)
    exit=Button(fenetre,text="Resoudre",bg='light blue', command=detruire)     #bouton pour resoudre le sudoku
    exit.grid(column=1, row=1,padx=10)

    toile.bind('<Button-1>',clic_Gauche)        #appel a la fonction du clic gauche
    toile.grid(column=0, row=1,padx=5,pady=5)
    fenetre.bind('<KeyPress>', clavier)         #appel a la fonction qui traite les touches clavier

    fenetre.mainloop()              # a la toute fin de la fonction pour permettre l'interaction

n=3
dessiner(n)


