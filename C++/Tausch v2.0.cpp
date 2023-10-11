#include <iostream>
#include <iomanip>
using namespace std;

inline void tausch(int &a, int &b) {
    a ^= b, b ^= a, a ^= b;
}

int main()
{
    int a = -898984140523, b = 567890;
    cout<<"Vorher: a -> "<<a<<", b -> "<<b<<endl;
    tausch(a, b);
    cout<<"Nachher: a -> "<<a<<", b -> "<<b<<endl;
	cout << "Wie viele Elemente?"<<endl;
    cin >> a;
    int c[a];
    cout << sizeof(c);
}
