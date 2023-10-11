// David - am 24.06.2020
// LK - EBA > OOP

#include <iostream>
#include <iomanip>

using namespace std;

class Zeit {
  private:
  int hour;
  int minute;
  int second;
  
  public:
  Zeit(void);
  Zeit(int, int, int);
  
  bool set(int, int, int);
  void add(int);
  void ausgabe(void);
  void ausgabe12(void);
  void ausgabe24(void);
  
  int getHour();
  int getMinute();
  int getSecond();
};

int Zeit::getHour() {
    return hour;
}

int Zeit::getMinute() {
    return minute;
}

int Zeit::getSecond() {
    return second;
}

bool Zeit::set(int _hour, int _minute, int _second) {
  if (_hour < 24 && _minute < 60 && _second < 60) {
    hour = _hour;
    minute = _minute;
    second = _second;
	return true;
  }
  else {
    hour = 0;
    minute = 0;
    second = 0;
    cout << "Ungültiges Format." << endl;
	return false;
  }
}

Zeit::Zeit(void) {
  hour = 0;
  minute = 0;
  second = 0;
}

Zeit::Zeit(int hour, int minute, int second) {
  set(hour, minute, second);
}

void Zeit::add(int hours) {
	hour += hours;
	hour %= 24;
	if (hour < 0)
	  hour += 24;
}

void Zeit::ausgabe() {
  cout << setfill('0')
  << " | Stunde  : " << setw(2) << hour << endl
  << " | Minute  : " << setw(2) << minute << endl
  << " | Sekunde : " << setw(2) << second << endl << endl;
}

void Zeit::ausgabe24() {
  cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << endl;
}

void Zeit::ausgabe12() {
  char am[3] = "AM";
  if (hour >= 12) {
    am[0] = 'P';
  }
  int h = hour % 12;
  if (!h)
    h = 12;

  cout << setfill('0') << setw(2) << h << ":" << setw(2) << minute << " " << am << endl;
}

int main() {
  Zeit z1(19, 5, 20), z2;
  z1.ausgabe();
  z2.ausgabe();
  z1.set(2, 7, 59);
  cout << z1.getSecond() << endl;
  
  z1.ausgabe();
  z1.ausgabe24();
  z1.ausgabe12();
  z1.add(11);
  cout << endl;
  z1.ausgabe24();
  z1.ausgabe12();
  cin.peek();
}