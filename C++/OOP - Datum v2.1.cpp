#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

bool is_leap_year(int year) {
  if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    return true;
  else
    return false;
}

class Datum {
  private:
  int day;
  int month;
  int year;
  
  public:
  static int    const month_lens[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  static string const month_names[12] = {"Januar", "Februar", "März", "April", "Mai", "Juni", "Juli", "August", "September", "Oktober", "November", "Dezember"};

  Datum(void);
  Datum(int, int, int);
  

  void add(int);
  void set(int, int, int);
  void ausgabe(void);
  void kurz_ausgabe(void);
  void lang_ausgabe(void);
  
  int getDay();
  int getMonth();
  int getYear();
};

void Datum::add(int days) {
  if (days == 0)
    return;
  day += days;
  bool todo = true;
  if (days > 0)
  {
  while (todo) {
    if (day > month_lens[month - 1]) {
      if (month == 2 && is_leap_year(year))
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
  } else
  {
  while (todo) {
    if (day < 1) {
      if (month == 3 && is_leap_year(year))
        day++;
      day += month_lens[month - 2];
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
      month = 13;
      year--;
    }
  }
  }
}

int Datum::getDay() {
    return day;
}

int Datum::getMonth() {
    return month;
}

int Datum::getYear() {
    return year;
}

void Datum::set(int _day, int _month, int _year) {
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

Datum::Datum(int day, int month, int year) {
  set(day, month, year);
}

void Datum::ausgabe() {
  cout << setfill('0')
  << " | Tag   : " << setw(2) << day - 0  << endl
  << " | Monat : " << setw(2) << month - 0 << endl
  << " | Jahr  : " << setw(4) << year << endl << endl;
}

void Datum::kurz_ausgabe() {
  cout << setfill('0') << setw(2) << day - 0 << "." << setw(2) << month - 0 << "." << setw(2) << year << endl;
}

void Datum::lang_ausgabe() {
  if (month < 1 || month > 12) {
    cout << "Ungültiger Monat.";
    return;
  }
  cout << setfill('0') << setw(2) << day - 0 << ". " << month_names[month - 1] << " " << setw(4) << year << endl;
}

int main() {
  Datum d1(19, 5, 2014);
  for (int i = 0; i < 12; i++) {
    cout << month_names[i] << ": " << month_lens[i] - 0 << " Tage." << endl;
  }
  cout << endl;
    
  d1.ausgabe();
  d1.set(2, 7, 2020);
  cout << d1.getYear() << endl;
  d1.ausgabe();
  d1.kurz_ausgabe();
  d1.lang_ausgabe();
  d1.add(-9999);
  d1.kurz_ausgabe();
  cin.peek();
}