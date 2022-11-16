// TP 7 jeu de massacre (à partir du TP4 -5)
//import ddf.minim.*; // importe la bibliothèque minim pour les commandes audio

// DECLARATIONS
int[] x=new int[4]; //tableau d'abscisses des centres de cercle
int[] y=new int[4]; //tableau d'abscisses des centres de cercle
int[] dx=new int[4]; //tableau incrément de deplacement
int[] dy=new int[4]; //tableau incrément de deplacement
int[] Dx=new int[4]; // tableau de déplacement signé en x
int[] Dy=new int[4]; // tableau de déplacement signé en y
int[] dessin=new int[4]; // tableau des etats de dessin
int x_tank=250; //abscisse du tank
int y_tank=550; //ordonnée du tank
PImage mario1; // variable de type image 
PImage mario2; // variable de type image
PImage mario3; // variable de type image 
PImage mario4; // variable de type image
PImage mario5; // variable de type image
PImage mario;
int x_mario=150;
int y_mario=850;
int sens=1;
int tempo=0;
PFont myFont; // définit une variable de type PFont (police)
int score=0;

//Minim tir; // on déclare l'objet audio intro de type Minim
//AudioPlayer morceau_tir; // declaration de l'objet son morceau_intro


// SETUP------------------------------------------------------------------------------------------------------------------------------------------------------
void setup() { // la fonction setup doit toujours etre présente. Elle ne renvoie rien
  size (1000, 1000); // on ouvre une fenetre 500x600
  background(0, 255, 0); // fond en vert
  frameRate(200); // la fonction draw sera réaffichée 30 fois par seconde (par défaut : 60 fois)
  myFont = createFont("Ravie", 32); // on définit un paramètre police (avec la taille)
  //tir=new Minim(this); // implémentation de l'objet intro dans "ce" fichier processing
  //morceau_tir=tir.loadFile("pacman_eatghost.wav"); // on charge le fichier son
  mario1=loadImage("mario1.jpg"); // on charge la variable blinky_image avec le fichier blinky.gif présent dans le répertoire data (faire glisser)
  mario2=loadImage("mario2.jpg"); // on charge la variable blinky_image avec le fichier blinky.gif présent dans le répertoire data (faire glisser)
  mario3=loadImage("mario3.jpg"); // on charge la variable blinky_image avec le fichier blinky.gif présent dans le répertoire data (faire glisser)
  mario4=loadImage("mario4.jpg"); // on charge la variable blinky_image avec le fichier blinky.gif présent dans le répertoire data (faire glisser)
  mario5=loadImage("mario5.jpg"); // on charge la variable blinky_image avec le fichier blinky.gif présent dans le répertoire data (faire glisser)
  for (int i=0; i<=3; i+=1) {
    x[i]=255; // initialisation ds tableaux
    y[i]=255;
    dx[i]=1;
    dy[i]=1;
    Dx[i]=1;
    Dy[i]=1;
    dessin[i]=1;
  }
}

// fonction DRAW----------------------------------------------------------------------------------------------------------------------------------------------
void draw() { //cette fonction doit toujours etre presente
  background(255); // on redessine le fond pour effacer le tracé précédent
  tracer_escalier();
  tracer_mario();
  tracer_jump();
  tracer_boules(); // on trace les ellipses
  affiche_score();// on affiche le score
}

// fonction tracer les boules-----------------------------------------------------------------------------------------------------------------------------
void tracer_boules() {
  for (int i=0; i<=3; i+=1) {
    stroke(0); //en noir
    strokeWeight(1); // epaisseur
    fill(255,0,0); // on dessine en rouge
    if (dessin[i]==1) { // on ne dessine l ellipse i que si dessin[i] est à 1
      ellipse(x[i], y[i], 80, 80); // on trace un cercle de centre (x,y) et de diametre 80
    }
    dx[i]=int(random(0, 5));
    dy[i]=int(random(0, 5));

    if (x[i]>=960) {
      Dx[i]=-dx[i];
    }
    if (x[i]<=40) {
      Dx[i]=dx[i];
    }
    if (y[i]>=300) {
      Dy[i]=-dy[i];
    }
    if (y[i]<=40) {
      Dy[i]=dy[i];
    }

    x[i]=x[i]+Dx[i];// on incremente l'abscisse du cercle
    y[i]=y[i]+Dy[i];
  }
}

// fonction tracer escalier-------------------------------------------------------------------------------------------------------------------------------
void tracer_escalier() {
  stroke (0); //  en noir
  strokeWeight(10); // epaisseur
  for (int i=0; i<=10; i+=1) {
    line(200+i*50, 900-i*50, 200+i*50, 850-i*50); // on trace une ligne
    line(200+i*50, 850-i*50, 250+i*50, 850-i*50); // on trace une ligne
  }
  line(750, 350, 900, 350);
  line(900, 350, 900, 850);
}

// fonction tracer_mario---------------------------------------------------------------------------------------------------------------------------------
void tracer_mario() {
  if (sens==0) { // s'il saute
    mario = mario5;
  }
  if (((x_mario-150)/50)%2==0) {
    if (sens==1) {
      mario=mario1;
    } 
    if (sens==-1) {
      mario=mario3;
    }
  } else
  {
    if (sens==1) {
      mario=mario2;
    } 
    if (sens==-1) {
      mario=mario4;
    }
  }
  imageMode(CENTER);
  image(mario, x_mario, y_mario, 100, 100); // affiche le fantome
}

// fonction tracer_jump-------------------------------------------------------------------------------------------------------------------------------
void tracer_jump() {
  if (sens==0) {
    tempo=tempo+1;
    if ((tempo>0)&(tempo<=50)) {
      y_mario=y_mario-5;
    }
    if ((tempo>50)&(tempo<=100)) {
      y_mario=y_mario+5;
    }
    for (int i=0; i<=3; i+=1) {
      if (((x_mario>=x[i]-40)&(x_mario<=x[i]+40)) & ((y_mario>=y[i]-50)&(y_mario<=y[i]+40)))
      {
        dessin[i]=0; // on passe le dessine[i] à 0 pour ne plus dessiner la boule i
      }
    }
  }
}

// fonction keyReleased----------------------------------------------------------------------------------------------------------------------------
void keyReleased () {
  if (keyCode==UP) {
    sens=0; // il saute en l'air
    if (tempo>100) { // si on a finit de sauter
      tempo=0; // on remet à 0 la tempo de saut
    }

   // morceau_tir.rewind(); // remet au début le morceau
    //morceau_tir.play(); // joue le morceau tir
  }



  if (keyCode==LEFT) {
    sens=-1;
    x_mario=x_mario-50; // on décréemnte le deplacement du tank
    println((x_mario-150)/50);
    if (((x_mario-150)/50>=0) & ((x_mario-150)/50<=10)) {
      y_mario=y_mario+50;
    }
  }
  if (keyCode==RIGHT) {
    sens=1;
    x_mario=x_mario+50; // on incrémente le deplacement du tank
    println((x_mario-150)/50);
    if (((x_mario-150)/50>=1) & ((x_mario-150)/50<=11)) {
      y_mario=y_mario-50;
    }
  }
}

//----------------------------------------------------affiche le score--------------------------------------------------------------

void affiche_score() // ceci est une fonction personnelle. On ecrit void devant car la fonction ne renvoie rien
{
  score=4;
  for (int i=0; i<=3; i+=1) {
    score=score-dessin[i];
  }

  textFont(myFont); // on choisit la police à utiliser
  textAlign(CENTER, CENTER); //le texte sera centré sur les coordonnées choisies
  fill(255, 0, 0); // définit la couleur du texte en rouge
  text("Score", 700, 600); //affiche le mot
  fill(0); // définit la couleur du texte en blanc
  text(score, 710, 650); // affiche la variable score
}
