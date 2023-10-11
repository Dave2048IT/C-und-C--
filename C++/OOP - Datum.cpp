#include <iostream>
#include <string.h>

using namespace std;

char month_lens[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string month_names[12] = {"Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};

bool is_leap_year(int year) {
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
  return true;
  else
  return false;
}

class Datum {
  private:
  char day;
  char month;
  int year;
  
  public:
  Datum(void);
  Datum(char, char, int);
  Datum (Datum &);
  ~Datum(void);
  Datum operator = (Datum);

  void add(int);
  void set(char, char, int);
  void ausgabe(void);
  void kurz_ausgabe(void);
  void lang_ausgabe(void);
};

void Datum::add(int days) {
  day += days;
  bool todo = true;
  if (days == 0)
    return;
  if (days < 0)
    goto a2;

  while (todo) {
    if (day > month_lens[month - 1]) {
      if (is_leap_year(year) && month == 2)
        day--;
      day -=  month_lens[month - 1];
      month++;
    }
    else
      todo = false;
    if (day == 0) {
      month--;
      day = month_lens[month - 1] + 1;
      todo = false;
    }
    
    if (month > 12) {
      month = 1;
      year++;
    }
  }
  return;
a2:
  while (todo) {
    if (day < 1) {
      if (is_leap_year(year) && month == 2)
        day++;
      day += month_lens[month - 1];
      month--;
    }
    else
      todo = false;
    /*if (day == 0) {
      day = 1;
      todo = false;
    }
    */
    if (month < 1) {
      month = 12;
      year--;
    }
  }
}

void Datum::set(char _day, char _month, int _year) {
  if (_month >= 1 && _month < 13
  && _day >= 1 && _day < month_lens[_month - 1] + 1) {
    day = _day;
    month = _month;
    year = _year;
  }
  else {
    day = 1;
    month = 1;
    year = 2000;
    cout << "Ungültiges Format." << endl;
  }
}

Datum::Datum(void) {
  day = 1;
  month = 1;
  year = 2000;
}

Datum::Datum(char day, char month, int year) {
  set(day, month, year);
}

Datum::Datum (Datum& k) {
  day = k.day;
  month = k.month;
  year = k.year;
}

Datum::~Datum() {
  // delete[] k_inhaber;
}

Datum Datum::operator = (Datum k) {
  set(k.day, k.month, k.year);
  return *this;
}

void Datum::ausgabe() {
  cout
  << " | Tag   : " << day - 0 << endl
  << " | Monat : " << month - 0 << endl
  << " | Jahr  : " << year << endl << endl;
}

void Datum::kurz_ausgabe() {
  cout << day - 0 << "." << month - 0 << "." << year << endl;
}

void Datum::lang_ausgabe() {
  if (month < 1 || month > 12) {
    cout << "Ungültiger Monat.";
    return;
  }
  cout << day - 0 << ". " << month_names[month - 1] << " " << year << endl;
}

int main() {
  for (char i = 0; i < 12; i++) {
    cout << month_names[i] << ": " << month_lens[i] - 0 << " Tage." << endl;
  }
  cout << endl;
  
  Datum d1;
  d1.ausgabe();
  d1.set(31, 1, 2020);
  d1.ausgabe();
  d1.kurz_ausgabe();
  d1.lang_ausgabe();
  d1.add(30);
  d1.kurz_ausgabe();
  cin.peek();
}