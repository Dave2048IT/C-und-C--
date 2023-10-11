#include <iostream>
#include <iomanip>
using namespace std;

void main()
{
wchar_t zk[31];
cout<<"Dezimal: "<<12<<" Oktal: "<<oct<<12<<" Hexa: "<<hex<<12<<dec<<endl;
cout<<setfill('0')<<setw(10)<<8<<endl;
cout<<setw(8)<<setprecision(3)<<right<<12.567654<<endl;
cout<<setw(8)<<setprecision(3)<<fixed<<12.567654<<endl;
cout<<resetiosflags(ios_base::fixed);
cout<<setw(8)<<setprecision(3)<<12.567654<<endl;
cout<<"Eingabe Zeichenkette: ";
wcin>>zk;
wcin.seekg(ios_base::end);
wcin.clear();
wcout<<"Eingegebene Zeichenkette: "<<zk;

cin.peek();
}
