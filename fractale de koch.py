from turtle import*
up()
goto(-150,100)
down()
speed(0)
def koc(n,l):
    if n==0:
        forward(l)
    else :
            koc(n-1,l/3)
            left(60)
            koc(n-1,l/3)
            right(120)
            koc(n-1,l/3)
            left(60)
            koc(n-1,l/3)
koc(5,300)
right(120)
koc(5,300)
right(120)
koc(5,300)
