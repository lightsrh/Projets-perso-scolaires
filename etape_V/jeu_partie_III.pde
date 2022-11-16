//------------------------Variables globales-------------------------------------
import controlP5.*;              //on importe le biblio cp5 qui cree zone de txt, button...
ControlP5 cp5;                    //variable de type cp5 dont le nom est cp5
PFont font = createFont("arial",30); //police et taille de zone d'affichage
Textarea zoneScore;                    //zone d'affichage pour le score
int x=800;                      //largeur de la fenêtre
int y=800;                       //hauteur de la fenêtre
int xraquette=100;              //position de la raquette
int yraquette=500;
int[] xobjet =new int[3];                //coordonnées des objets qui tombent
int[] yobjet =new int[3] ;
color rouge=color(255,0,0);                //définition des deux couleurs
color vert=color(0,255,0);
color[] couleur_objet=new color[3];        //couleurs des objet
int[] objet=new int[3];                    //nature des objets : 0=invisible; 1=carré; 2=cercle
int n=0 ;                                  //n est le rang (0, 1 ou 2) de l'objet le plus bas
int xbasobjet;
int ybasobjet;
float couleur;                                  //variable de couleur au hasard
float couloir;                                //variable de x au hasard
//------------------------fonction setup()-------------------------------------
void setup()
{
    cp5 = new ControlP5(this);        //creation de l'objet cp5
    zoneScore = cp5.addTextarea("zone")   //ajouter zone d'affichage dans l'objet cp5 et celle-ci apparaît dans la fenetre
      .setPosition(30 , 650 )                                                           // Abscisse et ordonnées du coin supérieur gauche
        .setSize ( 700 , 150 )                                                             // Largeur et hauteur de la zone d'affichage
          .setFont ( createFont ( "arial" , 12 ) )                                // type et taille de la police
            .setLineHeight ( 14 )                                                      // hauteur de chaque ligne dans la zone d'affichage
              .setColor ( color ( 0 ) )                                             // Couleur de la police (une valeur veut dire les « trois » identiques)
                .setColorBackground ( color ( 255 ) )                       // Couleur du fond de la zone d'affichage
                  .setColorForeground ( color ( 255 ) )                     // Couleur de premier plan
                    .setVisible ( true ) ;                                              // true : visible et false : invisible
    size(x, y);                  //taille de la fenêtre
    background(0,75,0);          //couleur du fond d'écran
    stroke(0);                  //couleur contours du rectangle
    fill(200);                  //couleur intérieur du rectangle
    rect(50,0,700,600);         //zone d'animation
    frameRate(60);              //nombre d'appels à la fonction draw()  
    for (int i=0; i<3 ; i++)      //creer 3 objets
    {
      creer_objet();              //création des caractéristiques d'un objet
      n=(n+1)%3;
    }  
    yobjet[1] = yobjet[1] - 120;       //on decale les objets
    yobjet[2] = yobjet[1] - 320;
}

//------------------------fonction draw()-------------------------------------
void draw()
{
  fill(200);                  //couleur intérieur du rectangle
  rect(50,0,700,600);         //zone d'animation
  frameRate(60);              //nombre d'appels à la fonction draw() 
  raquette();                  //on dessine la raquette
  dessiner_objet();            //on dessine l'objet
  collision();                 //on regarde s'il y a cillision avec la raquette
  for( int i = 0 ; i<3 ; i++)
  {
    yobjet[i] = yobjet[i] + 2;             //ils descendent tous de 2   
  }
  if(yobjet[n]>518)               // si l'objet n est en bas, il repart du haut et on change ses caractéristiques
  {
    yobjet[n]=-80;
    creer_objet();
    n=(n+1)%3;
  }
}
//------------------------fonction raquette()---------------------
void raquette()                //fonction qui dessine la raquette
{
  stroke(0);
  fill(0);
  rect(xraquette, yraquette, 100, 10);
}
//------------------------fonction keyPressed()---------------------
void keyPressed()
{
  if(keyCode == LEFT  &&  xraquette>50 )                  //si on veut aller à gauche
  {
    xraquette=xraquette-10;            //on modifie xraquette
  }
  if(keyCode == RIGHT  && xraquette<650)
  {
    xraquette=xraquette+10;
  }
  if(keyCode == DOWN && yraquette<590)
  {
    yraquette=yraquette+10;
  }
  if(keyCode == UP && yraquette>0)
  {
    yraquette=yraquette-10;
  }
}
//--------------------------fonction dessiner_objet()-----------------------
void dessiner_objet()
{
  for(int i = 0; i <3; i++)                  //dessiner les 3 objets
  {
    fill(couleur_objet[i]);                          //couleur du rectangle
    if(objet[i] != 0)                                  //choix de la forme de l'objet
    {
       if(objet[i] == 2)
       {
          ellipse(xobjet[i],yobjet[i],80,80); 
       } 
       if(objet[i] == 1)
       {
          rect(xobjet[i],yobjet[i],80,80); 
       } 
    }  
  }
}
//--------------------------fonction creer_objet()--------------------------
void creer_objet()
{
  int couleur=int(random(1,3));     //choix au hasard d'un entier : 1 ou 2 
  if(couleur == 1)                  //1 sera le vert et 2 le rouge
  {
      couleur_objet[n]=vert;
  }
  else
  {
      couleur_objet[n]=rouge;
  }
  int couloir=int(random(0,7));      //choix au hasard du couloir entre 0 et 6
  objet[n]=int(random(1,3));            //choix au hasard de la nature de l'objet
  if(objet[n]==1)                      //si c'est un carré
  {
      xobjet[n]=60+100*couloir;             //on décale l'abscisse de l'objet
      yobjet[n]=-80;
  }
  else
  {
      xobjet[n]=100+100*couloir;
      yobjet[n]=-40;
  }
}
//------------------------------fonction collision() --------------------------------------------------
void collision()                              //fonction que traite les collisions entre la raquette et les objets
{
   for(int i = 0 ; i<3 ; i++)
   {
        int boutraquette = xraquette + 100;              //extremité droite de la raquette
        int xraquette100 = xraquette - 100;                //extremité-100 de la raquette
        if(objet[i] == 1)                                      //si l'objet est un rectangle
        {
          ybasobjet = yobjet[i] + 80;
          xbasobjet = xobjet[i];
        }
        if(objet[i] == 2)                                        //si l'objet est un cercle
        {
          ybasobjet = yobjet[i] + 40;
          xbasobjet = xobjet[i] - 40;
        }
        if(ybasobjet == yraquette && xbasobjet>xraquette100 && xbasobjet<boutraquette)   //si l'objet touche la raquette                 //condition pour faire disparaître l'objet 
        {
          objet[i] = 0;
        }
   }
}
