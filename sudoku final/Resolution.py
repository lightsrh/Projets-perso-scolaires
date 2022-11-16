from Class import *

def recuperationListe(graphe) :
    """Permet de transformer un graphe en liste"""
    l = []
    for i in range(int(m.sqrt(len(graphe.listeS)))) :
        l.append([])
        for j in range(int(m.sqrt(len(graphe.listeS)))) :
            l[i].append(graphe.getSommets(str(i)+','+str(j)).number) #j'ajoute le nombre de chaque case dans la matrice
    return(l)

def implementationArrete(self,l,c,longueur=9) :
    """Permet de creer pour un sommets toutes les arretes auquel il est connecté
    cela cree donc de manieres temporaires un graphe orienté"""
    for i in range(longueur) :
        self.addArrete(str(l)+","+str(c),str(i)+","+str(c)) #les colonnes
        self.addArrete(str(l)+","+str(c),str(l)+","+str(i)) #kes lignes
    tailleCarre = int(m.sqrt(longueur))
    x,y = l//tailleCarre,c//tailleCarre #je calcule le coin en haut a gauche du bloc de la case
    for j in range(tailleCarre) :
        for i in range(tailleCarre) :
            if str(x*tailleCarre+i)+","+str(y*tailleCarre+j) not in self.listeAdj[str(l)+","+str(c)] and (i!=l and c!=j) : #je ne veux pas faire de boucle donc je teste
                self.addArrete(str(l)+","+str(c),str(x*tailleCarre+i)+","+str(y*tailleCarre+j)) #les bloc

def affichage(graphe) :
    """Permet d'afficher sous forme de texte la matrice du graphe"""
    for i in range(int(m.sqrt(len(graphe.listeS)))) :
        for j in range(int(m.sqrt(len(graphe.listeS)))) :
            print(graphe.getSommets(str(i)+','+str(j)).number,end='')
        print('')

rechercheManquant = lambda liste,longueur = 9 : [element for element in [i for i in range(1,longueur+1)] if element not in liste]
#Retourne les element qui ne sont pas dans la liste d'adjacences
#je liste l"alphabet" possible du sudoku
#je retourne tous l'alphabet qui ne se trouve pas dans la liste d'adjacenet

recupIndice0 = lambda graphe : [sommet.cle for sommet in graphe.listeS if sommet.number==0]
#permet de recuperer les indices de toutes les cases a 0

def resolutionRecursive(graphe) :
    """Permet de resoudre le sudoku"""
    sommetChecker = recupIndice0(graphe) #contient le nom de tous les sommets qui sont vide
    if sommetChecker == [] : #s'il n'y en a aucun alors le sudoku est fini
        return True
    else :
        manquant = rechercheManquant([graphe.getSommets(adj).number for adj in graphe.listeAdj[sommetChecker[0]]],int(m.sqrt(len(graphe.listeS))))
        #manquant est une liste qui contient tout les nombres possible a mettre dans la case
        if manquant==[] : #si on ne peut rien mettre alors le sudoku est faux
            return(False)
        for element in manquant : #on fait un for de tous les elements possibles
            graphe.getSommets(sommetChecker[0]).number = element #j'affecte le chiffre et donc modifie le graphe
            if resolutionRecursive(graphe) : #si on passe ce if alors cela veut dire que l'arbre des possibles est fini et que l'algo a trouve la solution
            #sinon cela veut dire que l'element testé n'est pas le bon donc on continue le for
                return(True) #si le lien est true donc que le sudoku n'est pas faux
        graphe.getSommets(sommetChecker[0]).number = 0 #si on a tester toutes les combinaisons mais que l'arbre des possibles ne renvoie que des faux
        #alors cela veut dire que le choix de la case d'avant n'est pas bon donc on renvoie faux et affecte 0 a cette case
        return(False)

def implementationSudoku(matrice) :
    final = Graphes() #un graphes vide
    for i in range(len(matrice)) : #double for de parcours de la matrice
        for j in range(len(matrice[0])) :
            final.addSommets(Sommets(str(i)+","+str(j),matrice[i][j],"black")) #pour chaque element du sudoku, je cree un sommet avec pour noms 'x,y' ex: "5,4"
            implementationArrete(final,i,j,len(matrice)) #une fois le sommets cree je dois le relier au graphe par de nombreuses arretes
    return(final) # je renvoie le graphe completé