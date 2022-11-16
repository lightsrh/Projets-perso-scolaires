// TP 3: déplavement aleatoire d'une boule dans l'écran et qui rebondit

// DECLARATIONS
int x=0; //abscisse du centre du cercle initialisée à 0
int y=0; // ordonnée du centre
int dx=1; //incrément de deplacement
int dy=1; //incrément de deplacement
int Dx=1; // déplacement signé en x
int Dy=1; // déplacement signé en y


// SETUP
void setup() { // la fonction setup doit toujours etre présente. Elle ne renvoie rien
  size (500, 500); // on ouvre une fenetre 500x500
  background(0, 255, 0); // fond en vert
  frameRate(60); // la fonction draw sera réaffichée 30 fois par seconde (par défaut : 60 fois)
}

// fonction DRAW
void draw(){ //cette fonction doit toujours etre presente
background(0,255,0); // on redessine le fond pour effacer le tracé précédent
stroke(0); //en noir
ellipse(x,y,80,80); // on trace un cercle de centre (x,y) et de diametre 80
stroke(255,0,0); //en rouge
line(x,y,250,0);
dx=int(random(0,5));
dy=int(random(0,5));

if (x>=460) {
  Dx=-dx;
}
if (x<=40) {
  Dx=dx;
}
if (y>=460) {
  Dy=-dy;
}
if (y<=40) {
  Dy=dy;
}

x=x+Dx;// on incremente l'abscisse du cercle
y=y+Dy;
}


