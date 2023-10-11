#include <iostream>
#include <string.h>

using namespace std;

class Konto {
  private:
  int k_nr;
  char* k_inhaber = NULL;
  double k_stand;
  // double k_zinssatz;
  
  protected:
  void set_k_stand(double);
  // void verzinsen(void);
  
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
  double get_k_stand();
};

class Girokonto :public Konto {
  private:
  double k_dispo;
  
  public:
  Girokonto(void);
  Girokonto(int, char*, double, double);
  void setDispo(double);
  void ausgabe(void);
  bool auszahlen(double);
};

class Sparkonto :public Konto {
  private:
  double k_zinssatz;
  
  public:
  Sparkonto(void);
  Sparkonto(int, char*, double, double);
  void ausgabe(void);
  void setZins(double);
  void verzinsen(void);
};


//**********Methoden******************

double Konto::get_k_stand(void) {
  return k_stand;
}

void Konto::set_k_stand(double stand) {
  k_stand = stand;
}

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
  << " | Konto-Stand: " << k_stand << endl;
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

//**********Giro-Konto****************
Girokonto::Girokonto(void) {
  k_dispo = 0;
}

Girokonto::Girokonto(int nr, char* inh, double stand = 0, double di = 0):Konto(nr, inh, stand) {
  k_dispo = di;
}

void Girokonto::ausgabe(void) {
  Konto::ausgabe();
  cout << "|| Konto-Dispo: " << k_dispo << endl << endl;
}

void Girokonto::setDispo(double d) {
  k_dispo = d;
}

bool Girokonto::auszahlen(double betrag) {
  if (get_k_stand() >= betrag - k_dispo)
  {
    set_k_stand(get_k_stand() - betrag);
    return true;
  }
  return false;
}

//**********Spar-Konto (Zins)*********
Sparkonto::Sparkonto(void) {
  k_zinssatz = 0;
}

Sparkonto::Sparkonto(int nr, char* inh, double stand = 0, double zi = 0):Konto(nr, inh, stand) {
  k_zinssatz = zi;
}

void Sparkonto::ausgabe(void) {
  Konto::ausgabe();
  cout << "|| Konto-Zinssatz: " << k_zinssatz << endl << endl;
}

void Sparkonto::setZins(double z) {
  k_zinssatz = z;
}

void Sparkonto::verzinsen() {
  set_k_stand (get_k_stand() * (k_zinssatz + 1));
}

//**********Start (main)**************

int main() {
  // Konto *k1 = new Konto;
  Konto k1 (6789, (char *) "Müller"), k2 = k1;
  k1.ausgabe();
  k1.set(984, (char *) "Maier", 518);
  cout << "Bool: " << (k1.auszahlen(100)) << endl;
  k1.ausgabe();
  cout << endl;
  k2.ausgabe();
  
  Girokonto g1, g2(4399, (char *) "Müller G.", 3456, 1000);
  g1.set(1234, (char *) "Schulz", 753);
  g1.setDispo(390);
  g1.einzahlen(100);
  g1.auszahlen(1243);
  g1.ausgabe();
  g2.ausgabe();
  
  Sparkonto s1, s2(4399, (char *) "Müller G.", 3456, 0.01);
  s1.ausgabe();
  s1.set(1234, (char *) "Schulz", 753);
  s1.setZins(0.017);
  s1.einzahlen(1900);
  s1.auszahlen(653);
  s1.verzinsen();
  s1.ausgabe();
  //s2.ausgabe();
  cin.peek();
  // delete k1;
}