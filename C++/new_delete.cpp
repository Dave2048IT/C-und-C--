#include <iostream>

using namespace std;

void main()
{
int anzahl;
char *zk;

cout<<"Wie viele Zeichen sollen eingegeben werden? ";
cin>>anzahl;
cin.seekg(ios_base::end);
cin.clear();
zk=new char[anzahl+1];
if (zk != NULL)
{
	cout<<"Eingabe von "<<anzahl<<" Zeichen: ";
	cin>>zk;
	cin.seekg(ios_base::end);
	cin.clear();
	cout<<"Zeichenkette: "<<zk;
}
else
	cout<<"Eingabe von "<<anzahl<<" Zeichen nicht moeglich!!!";
delete []zk;
cin.peek();
}


