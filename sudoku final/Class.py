"""Contient :
- Graphes :
    - listeS
    - listeADJ
- Sommets :
    - cle
    - couleur
    - name
"""
import tkinter as t
import random as rd
import math as m

class Sommets :
    def __init__(self,name,value,color) :
        self.cle = name
        self.couleur = color
        self.number = value

class Graphes :
    def __init__(self) :
        self.listeS = []
        self.listeAdj = {}

    def __str__(self) :
        return(str(self.listeAdj))

    def addSommets(self,s) :
        """Permet d'ajouter un sommet au graphe """
        self.listeS.append(s)
        self.listeAdj[s.cle]=[]

    def getSommets(self,cle) :
        """Retourne la liste d'adj d'un sommet"""
        for i in range(len(self.listeS)) :
        	if self.listeS[i].cle==cle :
        		return(self.listeS[i])

    def chercheArrete(self,x,y) :
    	"""Retourne True si il y a une arrete qui va de x vers y"""
    	if y in self.listeAdj[x] :
    		return(True)
    	return(False)

    def addArrete(self,cle1,cle2) :
        """Permet d'ajouter un arc de sommet1 et sommet2"""
        self.listeAdj[str(cle1)].append(str(cle2))

    def afficher(self) :
        distancePoints = lambda xa,ya,xb,yb :m.sqrt((xb-xa)**2+(yb-ya)**2)
        def coordonnes(dP) :
            x,y = rd.randint(20,int(interface.cget("width"))-20),rd.randint(20,int(interface.cget("height"))-20)
            for x1,y1 in dP.values() :
                if distancePoints(x,y,x1,y1)<50 :
                    return(coordonnes(dP))
            return(x,y)
        def tracerPoints(self) :
            interface.delete("all")
            dPoints = {}
            for s in self.listeS :
                dPoints[s.cle]=coordonnes(dPoints)
            for name,padj in self.listeAdj.items() :
                for adj in padj :
                    interface.create_line(dPoints[name][0]+10,dPoints[name][1]+10,dPoints[adj][0]+10,dPoints[adj][1]+10,width=2)
            for p in self.listeS :
                x,y = dPoints[p.cle]
                interface.create_oval(x,y,x+20,y+20,fill=p.couleur,outline="")
                interface.create_text(x+10,y+10,text=str(p.cle),fill="white")
            interface.update()
        root = t.Tk()
        root.title("Graphes")
        interface = t.Canvas(root,width=len(self.listeS)*10,height=len(self.listeS)*10)
        tracerPoints(self)
        interface.bind("<Button-1>",lambda event: tracerPoints(self))
        interface.pack()
        root.bind("<Escape>",lambda event :root.destroy())
        root.mainloop()

    def rechercheChaine(self,cleD,cleA,liste=[]) :
        liste=liste+[cleD]
        if cleD == cleA :
            return(liste)

        S = self.getSommets(cleD)
        for cleV in self.listeAdj[S.cle] :
            Sv = self.getSommets(cleV)
            if Sv.cle not in liste :
                newChaine = self.rechercheChaine(Sv.cle,cleA,liste)
                if newChaine!=[] :
                    return(newChaine)
        return([])