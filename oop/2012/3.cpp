//
// Created by rols on 4/6/17.
//

#include "stdio.h"
#include "stdlib.h"
#define making(x,y,z) z++; \
printf(y, GlassOfWater(), Sugar::TwoCubesOfSugar(), x); z++;
#define boil(x,y) TwoCubesOfSugar()+Water::x+Sugar::x+(int)x
#define swap(x,y) x=x+y; y=x-y; x=x-y;
char *s = new char[100];
int i=0;
char* JustDoIt(char* c);
class Sugar
{
private:
    int x;
public:
    Sugar() { x= 1; s[i]='$'; s[i+1]='d'; }
    int TwoCubesOfSugar() { return x; }
    friend class Coffee;
};
class Water : public Sugar
{
private:
    int x;
public:
    Water() { x=-2; making(this, JustDoIt(s), i); }
    Water(int X) { x=X; }
    int GlassOfWater() { return x; }
    friend class Coffee;
};
class Coffee : public Water, public Sugar
{
private:
    unsigned int x;
public:
    Coffee() { x=Water::x; making(this, JustDoIt(s), i); }
    int AddMoreWater(Water* w)
    {
        printf("%d",w->TwoCubesOfSugar()+Water::x+Sugar::x+x);
        swap(i,x);
        return i;
    }
    int AddMoreSugar(Sugar* r)
    {
        printf("%d",r->boil(x,this));
        swap(i,x);
        return i;
    }
};
char* JustDoIt(char* c)
{
    char* cup = new char[i+2];
    int j;
    for (j=0; j<i+1; j++)
        if ((j+1)%2)
        {
            cup[j]=c[j]+1;
        }
        else
        {
            cup[j]=c[j]|0x11;
        }
    cup[i+1]='\0';
    return cup;
}
int main(int argc, char* argv[])
{
    Coffee c;
    Water w(3);
    c.AddMoreSugar((Sugar*)&w);
    return int(0);
}