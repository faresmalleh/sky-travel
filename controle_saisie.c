#include "controle_saisie.h"

int digital(char x[15])
{
int res=0;
int i,a;
a=strlen(x);
for(i=0;i<=a;i++)
  {
    if (isdigit(x[i])!=0)
    {
      res=res+1;
    }
  }
  if(res==a)
      {return 1;}
    else {return 0;}

}


int controle_saisie_numtel(char x[15])
{
int a;
a=strlen(x); 
if ((digital(x)==1) && (strlen(x)>=8))
{ return 1;}
else {return 0;}
}

int controle_saisie_nonvide(char x[15])
{ 
int a ;
a=strlen(x);
if (a!=0)
{return 1;}
else {return 0;}
}
