#include <iostream>
#include <string.h>

using namespace std;

class Konto {
  private:
  int k_nr;
  double k_stand;
  char* k_inhaber = NULL;
  
  public:
  Konto(void);
  Konto(int, char*, double);
  Konto (Konto &);
  ~Konto(void);
  Konto operator = (Konto);

  void set(int, char*, double);
  void ausgabe(void);
  void einzahlen(double);
  bool auszahlen(double);
};

void Konto::set(int nr, char* inh, double stand = 0) {
  k_nr = nr;
  k_stand = stand;
  if (k_inhaber != NULL) {
    cout << "Wieder frei" << endl;
    delete[] k_inhaber;
  }
  k_inhaber = new char[strlen(inh) + 1];
  strcpy(k_inhaber, inh);
}

Konto::Konto(void) {
  k_nr = 0;
  k_stand = 0;
  k_inhaber = new char;
  k_inhaber[0] = 0;
  // (char *) "";
}

Konto::Konto(int nr, char* inh, double stand = 0) {
  set(nr, inh, stand);
}

Konto::Konto (Konto& k) {
  k_nr = k.k_nr;
  k_stand = k.k_stand;
  k_inhaber = new char[strlen(k.k_inhaber) + 1];
  strcpy(k_inhaber, k.k_inhaber);
}

Konto::~Konto() {
  delete[] k_inhaber;
}

Konto Konto::operator = (Konto k) {
  set(k.k_nr, k.k_inhaber, k.k_stand);
  return *this;
}

void Konto::ausgabe() {
  cout
  << " | Konto-Nummer: " << k_nr << endl
  << " | Konto-Name: " << k_inhaber << endl
  << " | Konto-Stand: " << k_stand << endl << endl;
}

void Konto::einzahlen(double betrag) {
  k_stand += betrag;
}

bool Konto::auszahlen(double betrag) {
  if (k_stand >= betrag)
  {
    k_stand -= betrag;
    return true;
  }
  return false;
}

int main() {
  // Konto *k1 = new Konto;
  Konto k1 (6789, (char *) "Müller"), k2 = k1;
  k1.ausgabe();
  k1.set(984, (char *) "Maier", 518);
  cout << "Bool: " << (k1.auszahlen(100)) << endl;
  k1.ausgabe();
  k2.ausgabe();
  cin.peek();
  // delete k1;
}