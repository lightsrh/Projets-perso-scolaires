//------------------------------------------------- DECLARATIONS ---------------------------------------------------------------

PImage mario1;
PImage mario2;
int x = 90;
int y = 725;
int m =1;
int vie;
int point=0;

int nb = 5;
int [] xc= new int [nb]; //abscisse du centre du cercle initialisée à 0
int [] yc= new int [nb]; // ordonnée du centre
int [] Dx= new int [nb]; // déplacement signé en x
int [] Dy= new int [nb]; // déplacement signé en y
int [] oct = new int [nb];
PImage photo;
int yl=-500;
int xl=-500;
//------------------------------------------------- FONCTION setup ( ) ---------------------------------------------------------
void setup()   // doit TOUJOURS etre présente, même vide. On ecrit void devant car la fonction ne renvoie rien
{
  background(250);    //fond d'écran
  size(800, 800); //Taille de la fenêtre
  frameRate(60); // la fonction draw sera réaffichée 30 fois par seconde (par défaut : 60 fois)
  for (int j = 0; j<nb; j++)
  {
    xc[j] = int(random(40, 460));
    yc[j] = int(random(40, 460));
    Dx[j]=int(random(1, 5));
    Dy[j]=int(random(1, 5));
    oct[j] = 1;
  } 
  photo = loadImage("ball.png");
}
//----------------------------------------------- FONCTION draw ( ) -----------------------------------------------------------
void draw() // doit TOUJOURS etre pésente, même vide. Elle sera rappellée à la fréquence du frameRate. Elle peut être inhibée par noLoop();
{
  background(250);
  fill(0);
  stroke(0);
  mario1=loadImage("mario1.jpg");
  mario2=loadImage("mario2.jpg");
  rect(200, 700, 600, 100);
  rect(300, 600, 500, 100);
  rect(400, 500, 400, 100);
  rect(500, 400, 300, 100);
  rect(600, 300, 200, 100);
  fill(200, 20, 50);
  if ( m==1)
  {
    image(mario1, x, y);
  } else
  {
    image(mario2, x, y);
  }
  finjeu();
  for (int i = 0; i<nb; i++)
  {
    if (oct[i] == 1)
    {
      xc[i]=xc[i]+Dx[i];// on incremente l'abscisse du cercle
      yc[i]=yc[i]+Dy[i];
      stroke(0); //en noir
      //ellipse(xc[i],yc[i],80,80); // on trace un cercle de centre (x,y) et de diametre 80
      stroke(255, 0, 0); //en rouge
      image(photo, xc[i], yc[i], 80, 80);
      imageMode(CENTER); // on affiche l'image avec pour ref son centre
      if (xc[i]>=760)
      {
        Dx[i]=-int(random(1, 5));
      }
      if (xc[i]<=40) {
        Dx[i]=int(random(1, 5));
      }
      if (yc[i]>=360) {
        Dy[i]=-int(random(1, 5));
      }
      if (yc[i]<=40) {
        Dy[i]=int(random(1, 5));
      }
    }
    turc();
  }
      textSize(20);
    fill(0, 0, 0);
    text("score : ", 500, 50);
    text(point, 575, 50);
}
//--------------------------------------------------------------------------------------------------------------------
void keyPressed()
{
  if (keyCode == LEFT  )                  //si on veut aller à gauche
  {
    x=x-110;
    y=y+100;
    m=0;
    yl=y;
    xl=x;
  }
  if (keyCode == RIGHT  )
  {
    x=x+110;
    y=y-100;
    m=1;
    yl=y;
    xl=x;
  }
  if (keyCode == UP)
  {
    for (int i=0; i<50; i++)
    {
      y=y-2;
      yl=y;
      xl=x;
    }
  }
  if (keyCode == DOWN)
  {
    for (int i=0; i<50; i++)
    {
      y=y+2;
      yl=y;
      xl=x;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------------------
void finjeu()
{
  if (point==nb)
  {
    textSize(32);
    fill(250, 0, 0);
    text("Tu as gagné !", 250, 250);
  }
}
//---------------------------------------------------------------------------
void turc()
{
  for (int i = 0; i<nb; i++)
  {
    if (xc[i]+40>xl-56 && xc[i]-40<xl+56 && yc[i]+40>yl-62 && yc[i]-40<yl+62 && oct[i]<2)
    {
      oct[i] = 0;
    }
    if (oct[i]==0)
    {
      point=point+1;
      oct[i]=2;
    }
  }
}

