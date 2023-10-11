#include<iostream>
using namespace std;


void tausch(int&, int&);

void main()
{
int x, y;
cout<<"Eingabe X: ";
cin>>x;
cin.seekg(ios_base::end);
cin.clear();
cout << "Eingabe Y: ";
cin >> y;
cin.seekg(ios_base::end);
cin.clear();
tausch(x,y);
cout<<"x: "<<x<<endl<<"y: "<<y;
cin.peek();
}



void tausch(int& a, int& b)     
{
int h;
h=a;        
a=b;
b=h;
}
