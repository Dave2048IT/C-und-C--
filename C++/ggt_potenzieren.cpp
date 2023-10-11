//Funktionen ggt und potenzieren mit der Möglichkeit der Übergabe von negativen Zahlen

#include <stdio.h>


double potenzieren(int basis, int expo);

int ggt(int z1, int z2)
{
int i;
if(z1==0&&z2==0)
	return 1;
if(z1<0)	
	z1=-z1;
if(z2<0)   
	z2=-z2;
if(z1<z2)
	i=z1;
else
	i=z2;
for(;i>0;i--)
if((z1%i==0)&&(z2%i==0))
	return i;
}


void main()
{
int zahl1, zahl2, teiler;
printf("Eingabe Zahl1: ");
scanf("%i",&zahl1);
fflush(stdin);
printf("Eingabe Zahl2: ");
scanf("%i",&zahl2);
fflush(stdin);
printf("\nGroesster gemeinsamer Teiler: %d",ggt(zahl1,zahl2));
printf("\n%i hoch %i = %lf",zahl1,zahl2,potenzieren(zahl1,zahl2));
getchar();
}

double potenzieren(int basis, int expo)
{
char vz='p';
long ergebnis;
if (expo<=0 && basis==0) //Potenzieren nicht möglich
	return 0;
if(expo<0)
{
	vz='n';
	expo=-expo;
}
ergebnis=1;
while (expo>0)
	{
	ergebnis=ergebnis*basis;
	expo--;
	}
if(vz=='p')
	return ergebnis;
else
	return 1/(double) ergebnis;
}