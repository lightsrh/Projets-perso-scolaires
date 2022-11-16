// JEU DE TIR SUR LES FANTOMES



//----------------- DECLARATIONS ---------------------------------------------------------------
//import ddf.minim.*; // importe la bibliothèque minim pour les commandes audio

int cadre_x=280; // abscisse du début du cadre en pixels
int cadre_y=50; // ordonnée du début du cadre en pixels
int ecart=20; // largeur d'une case en pixel (intervalle)
int boucle=0; // compteur de boucle du draw
int tank_x=10; // abscisse du tank
int tank_y=29; // ordonnée du tank
int feu=0; // feu non activé
int score=0; // compteur de points
int compteur=500000; //compteur de temps
int fin_partie=0; // indicateur de fin de partie

PImage blinky_image; // variable de type image 
PImage inky_image; // variable de type image

PFont myFont; // police de caractere



//Minim tir; // on déclare l'objet audio intro de type Minim
//Minim mort; // on déclare l'objet audio mort de type Minim
//AudioPlayer morceau_tir; // declaration de l'objet son morceau_intro
//AudioPlayer morceau_mort; // declaration de l'objet son morceau_mort

Fantome [] fantome=new Fantome[20];



//-------------- FONCTION setup ( ) ---------------------------------------------------------
void setup()   // doit TOUJOURS etre présente, même vide. On ecrit void devant car la fonction ne renvoie rien
{
  size(1200, 700); // Taille de la fenêtre principale (on ne peut passer que des nombres, pas des variables)
  background(0) ; // Couleur du fond de la fenêtre en Noir
  frameRate(20); // la fonction draw sera executée 20 fois par secondes

  myFont=createFont("Ravie", 32); // police de caractere

  blinky_image=loadImage("blinky.gif"); // on charge la variable blinky_image avec le fichier blinky.gif présent dans le répertoire data (faire glisser)
  inky_image=loadImage("inky.gif");


  //tir=new Minim(this); // implémentation de l'objet intro dans "ce" fichier processing
  //morceau_tir=tir.loadFile("pacman_eatghost.wav"); // on charge le fichier son

  //mort = new Minim(this); // implémentation de l'objet mort dans "ce" fichier processing
  //morceau_mort=mort.loadFile("pacman_death.wav");

  for (int i=0; i<20; i+=1) {  // initialisation de 10 fantomes
  fantome[i]=new Fantome(i,11, 5, blinky_image, 1.8, 1);
  }
}

//------------------- FONCTION draw ( ) -----------------------------------------------------------
void draw() // doit TOUJOURS etre pésente, même vide. Elle sera rappellée à la fréquence du frameRate. Elle peut être inhibée par noLoop();
{
  boucle=boucle+1; // on incrémente le compteur de boucle 
  if (boucle%5==0) {
    compteur=compteur-1; // on décrément le compteur
    if (compteur==0) {
      fin_partie=1;
    }
  }

  background(0) ; // On recolore  en noir le fond de la fenêtre ce qui efface le tracé précédent
  tracer_cadre() ; // On trace le jeu
  affiche_score(); // affiche le score


  for (int i=0; i< 20; i+=1) {  // on charge et affiche les 10 fantomes (fantome.size donne la dimension du tableau fantome)
      fantome[i].display();
  }

  tracer_tank();
  feu=0; // le feu est desactivé
  if (fin_partie==1) {
    textFont(myFont); // on choisit la police à utiliser
    textAlign(CENTER, CENTER); //le texte sera centré sur les coordonnées choisies
    fill(255, 255, 0); // définit la couleur du texte en jaune
    text("GAME OVER", cadre_x+35*ecart, cadre_y+15*ecart); //affiche le mot
    //morceau_mort.rewind(); // remet au début le morceau
    //morceau_mort.play(); // joue le morceau mort
    noLoop();
  }
}  

//----------------- FONCTION tracer_cadre ( ) --------------------------------------------------------
void tracer_cadre() // ceci est une fonction personnelle. On ecrit void devant car la fonction ne renvoie rien
{
  stroke(0, 0, 255); // à partir de maintenant les contours sont en bleu
  strokeWeight(4); // épaisseur 
  noFill(); //  à partir de maintenant, on ne remplit pas
  rectMode(CORNER); // rectangle defini par son coin sup gauche
  rect(cadre_x, cadre_y, 27*ecart, 30*ecart); // dessine le cadre un rectangle Coin sup gauche (0,0), largeur 27 intervalles, hauteur 30 intervalles; // dessine le cadre un rectangle Coin sup gauche (280,100), largeur 27 intervalles, hauteur 30 intervalles
}

//----------------- FONCTION tracer_tank ( ) --------------------------------------------------------
void tracer_tank() // ceci est une fonction personnelle. On ecrit void devant car la fonction ne renvoie rien
{
  stroke(0, 255, 0); // à partir de maintenant les contours sont en vert
  strokeWeight(4); // épaisseur 
  fill(255, 0, 0); //  à partir de maintenant, on remplit en rouge
  rectMode(CENTER); // rectangle defini par son centre
  rect(cadre_x+tank_x*ecart, cadre_y+tank_y*ecart, ecart, ecart);
}

//-------------- key_released()
void keyReleased() {
  if (keyCode==LEFT) {
    tank_x=tank_x-1;
  }
  if (keyCode==RIGHT) {
    tank_x=tank_x+1;
  }
}

// --------------mousePreessed()
void mousePressed() {
  feu=1; // le feu est activé
  stroke(255, 0, 0); // en rouge
  line(cadre_x+tank_x*ecart, cadre_y+tank_y*ecart, cadre_x+tank_x*ecart, cadre_y); // ligne de feu verticale
  //morceau_tir.rewind(); // remet au début le morceau
  //morceau_tir.play(); // joue le morceau mort
}

//----------------------------------------------------affiche le score--------------------------------------------------------------

void affiche_score() // ceci est une fonction personnelle. On ecrit void devant car la fonction ne renvoie rien
{

  textFont(myFont); // on choisit la police à utiliser
  textAlign(CENTER, CENTER); //le texte sera centré sur les coordonnées choisies
  fill(255, 0, 0); // définit la couleur du texte en rouge
  text("Score", cadre_x+35*ecart, cadre_y+2.5*ecart); //affiche le mot
  fill(255); // définit la couleur du texte en blanc
  text(score, cadre_x+35*ecart, cadre_y+5*ecart); // affiche la variable score
  text(compteur, cadre_x+35*ecart, cadre_y+10*ecart); // affiche la variable score
}


//----------------------------------------------- classe Fantome --------------------------------------------------------
class Fantome {
  //Déclaration des variables internes, spécifiques à la classe fantome
  int x; // son abscisse
  int y; // son ordonnée
  int r; // modulo affichage
  PImage img; // son image
  float aff; // parametre d'affichage (taille de l'image)
  int vie; // parametre de vie

    //Constructeur du fantome
  Fantome (int nouvX, int nouvY, int nouvR, PImage nouvImg, float nouvAff, int nouvVie) {
    x          = nouvX; // on charge dans les variables internes, les valeurs des variables passées par la classe
    y          = nouvY;
    r           =nouvR;
    img        = nouvImg;
    aff        = nouvAff;
    vie        = nouvVie;
  }

  //Dessin et mouvement du fantome
  void display() {
    if (vie==1) { // si le fantome est en vie)
      if (boucle%r==0) { // on ne fait le traitement suivant qu etout les r boucles
        x=x+int(random(-2, 2)); // on fait evoluer son abscisse aleatoirement entre -1, 0 ou +1
        y=y+int(random(-2, 2)); // on fait evoluer son ordonnée aleatoirement entre -1, 0 ou +1
        if (x>26) {
          x=26;
        }
        if (x<1) {
          x=1;
        }
        if (y>25) {
          y=25;
        }
        if (y<1) {
          y=1;
        }
      }
      if ((feu==1) & (x==tank_x)) {
        vie=0; // le fantome meurt
        score=score+1; // on met à jour le score
      } else {
        imageMode(CENTER); // on affiche l'image avec pour ref son centre
        image(img, cadre_x+x*ecart, cadre_y+y*ecart, aff*ecart, aff*ecart); // affiche le fantome
      }
    }
  }
}
