#include <iostream>
#include <string.h>

using namespace std;

class Person {
  private:
  string name;
  int kinder;
  int personal_nr;
  
  protected:
  void set_name(string);
  void set_kinder(int);
  void set_personal_nr(int);
  
  public:
  Person(void);
  Person(string, int, int);
  Person (Person &);
  ~Person(void);
  Person operator = (Person);

  void set(string, int, int);
  void ausgabe(void);
  string get_name(void);
  int get_kinder(void);
  int get_personal_nr(void);
};

class Gehalt :public Person {
  private:
  double betrag;
  
  public:
  Gehalt(void);
  Gehalt(string, int, int, double);
  
  void set(string, int, int, double);
  void verdienst_ausgabe(void);
};

class Zeitlohn :public Person {
  private:
  int stunden;
  double stundensatz;
  
  public:
  Zeitlohn(void);
  Zeitlohn(string, int, int, int, double);
  
  void set(string, int, int, int, double);
  void verdienst_ausgabe(void);
};


//********** Methoden ****************

string Person::get_name(void) {
  return name;
}

int Person::get_kinder(void) {
  return kinder;
}

int Person::get_personal_nr(void) {
  return personal_nr;
}


void Person::set_name(string n) {
  name = n;
}

void Person::set_kinder(int k) {
  kinder = k;
}

void Person::set_personal_nr(int pnr) {
  personal_nr = pnr;
}


void Person::set(string n = " ", int k = 0, int pnr = 0) {
  name = n;
  kinder = k;
  personal_nr = pnr;
}

Person::Person(void) {
  name = " ";
  kinder = 0;
  personal_nr = 0;
}

Person::Person(string n, int k, int pnr) {
  set(n, k, pnr);
}

Person::Person (Person& k) {
  name = k.name;
  kinder = k.kinder;
  personal_nr = k.personal_nr;
}

Person::~Person() {
  // delete[] name;
}

Person Person::operator = (Person k) {
  set(k.name, k.kinder, k.personal_nr);
  return *this;
}

void Person::ausgabe() {
  cout
  << " | Anzahl Kinder : " << kinder << endl
  << " | Name          : " << name << endl
  << " | Personal-Nr.  : " << personal_nr << endl << endl;
}


//********** Gehalt ******************
Gehalt::Gehalt(void) {
  betrag = 0;
}

Gehalt::Gehalt(string n, int k = 0, int pnr = 0, double b = 0):Person(n, k, pnr) {
  betrag = b;
}

void Gehalt::set(string n = " ", int k = 0, int pnr = 0, double b = 0) {
  set_name(n);
  set_kinder(k);
  set_personal_nr(pnr);
  betrag = b;
}

void Gehalt::verdienst_ausgabe() {
  Person::ausgabe();
  cout << "|| Betrag: " << betrag << endl << endl;
}


//********** Zeitlohn ****************
Zeitlohn::Zeitlohn(void) {
  stunden = 0;
  stundensatz = 0;
}

Zeitlohn::Zeitlohn(string n, int k = 0, int pnr = 0, int std = 0, double ssatz = 0):Person(n, k, pnr) {
  stunden = std;
  stundensatz = ssatz;
}

void Zeitlohn::set(string n = " ", int k = 0, int pnr = 0, int std = 0, double ssatz = 0) {
  /*
  name = n;
  kinder = get_kinder();
  personal_nr = get_personal_nr();
  */
  set_name(n);
  set_kinder(k);
  set_personal_nr(pnr);
  stunden = std;
  stundensatz = ssatz;
}

void Zeitlohn::verdienst_ausgabe(void) {
  Person::ausgabe();
  cout << "|| Verdienst: " << stunden*stundensatz << endl << endl;
}


//**********Start (main)**************

int main() {
  // Person *p1 = new Person;
  Person p1 ((char *) "Müller", 3, 1000), p2 = p1;
  p1.ausgabe();
  p1.set((char *) "Maier", 1, 594);
  p1.ausgabe();
  cout << endl;
  p2.ausgabe();
  
  Gehalt g1, g2((char *) "Müller G.", 2, 4399, 1000);
  g1.set((char *) "Schulz", 3, 1234);
  g1.verdienst_ausgabe();
  g2.verdienst_ausgabe();
  
  Zeitlohn z1, z2((char *) "Müller G.", 4, 39756, 12, 10.01);
  z1.verdienst_ausgabe();
  z1.set((char *) "Schulz", 0, 568, 9, 15.5);
  z1.verdienst_ausgabe();
  z2.verdienst_ausgabe();
  //z2.ausgabe();
  cin.peek();
  // delete p1;
}