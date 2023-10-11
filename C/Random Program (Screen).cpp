


#include<iostream>
//#include<string>
#include<vector>


using namespace std;


// -------------- Screen -------------------
// A virtual screen with pixels x: 0-(w-1) and y: 0-(h-1)
// NOTE: (0,0) is the bottom left - 
// Pixels can be any character, determined by each Point.


class Screen {
   friend class Shape;

private:
   int width, height;
   //std::vector<std::vector<char>> pixels;
   vector<vector<char>> pixels;

public:
   static const char DEFAULT_FG_CH = '*', DEFAULT_BG_CH = '.';


   Screen(int w = 100, int h = 100) {
      this->width = w;
      height = h;
      clear();
   }


   // TODO
/* Type your code here */
   int getWidth() { return width; }
   int getHeight() { return height; }
   void setPixel(int w, int h, char c) { pixels[w][h] = c; }


   void clear() {
      fill(DEFAULT_BG_CH);
   }

   void fill(char c) {
      //pixels.resize(h);    ///  use .push_back();   or .resize()
      for (int i = 0; i < height; i++)
      {
         pixels.push_back(vector<char>(width));    ///  use .push_back();   or .resize()
         //pixels[i] = vector<char>(w);
         for (int k = 0; k < width; k++)
         {
            //cout << DEFAULT_FG_CH;
            pixels[i][k] = c;
            //cout << pixels[i][k];
         }
      }

   }

   string toString() const {
      string rtStr = "";

      for (int i = 0; i < height; i++)
      {
         for (int k = 0; k < width; k++)
            rtStr += pixels[i][k];
         rtStr += "\n";
      }

      return rtStr;
   }

   //friend std::ostream& operator<<(std::ostream, const Screen& scr);
   friend ostream& operator<<(ostream, const Screen& scr);


};         ///////      ; after class definition



// --------- Shape ---------------------------------

// Base class for Point, Line, etc.
// Abstract.

class Shape {
private:
   // empty
public:
   // TODO
   /* Type your code here */

   virtual bool draw(Screen& scr, char ch) = 0;     ////////////////////////////


};


// --------- Point ---------------------------------
class Point : public Shape {
private:
   int x, y;

public:
   Point(int x1, int y1) : x(x1), y(y1) {}; ///////////////

   // TODO
    /* Type your code here */
   bool draw(Screen& scr, char ch) {
      if (x < 0 | x >= scr.getWidth() | y < 0 | y >= scr.getHeight())
         return false;

      scr.setPixel(x, y, ch);
      return true;
   }
};


// ----------- Line --------------------------------
// Line in two point notation


class Line : public Shape {

private:
   int x1, y1, x2, y2;

   // Helpers
// TODO
/* Type your code here */
   //Point dot();           //////////  ??  right way to init ??

public:
   // TODO
   /* Type your code here */

   Line(int x1, int y1, int x2, int y2) {
      this->x1 = x1;
      this->y1 = y1;
      this->x2 = x2;
      this->y2 = y2;
   }


   bool draw(Screen& scr, char ch) {

      //Point startPt(x1,y1), endPt(x2,y2);

      if (x1 > x2 && y1 < y2) {
         int x = x1, y = y1;
         //Point currPt(); //(x, y);
         while (x >= x2 && y <= y2) {
            Point currPt(x, y);
            if (currPt.draw(scr, ch) == true) {
               cout << "CASE 1 --------- loop in Line.DRAW() :  " << x << " " << y << endl;

               if (abs(x2 - x1) > abs(y2 - y1)) {
                  x--;
                  y = y2 - static_cast<int>(x * abs(y2 - y1) / abs(x2 - x1));
                  //y = y2 - std::round(x * abs(y2 - y1) / abs(x2 - x1));
               }
               else {
                  y++;
                  x = x1 - static_cast<int>((y * abs(x2 - x1) / abs(y2 - y1)));
                  //x = x1 - std::round(y * abs(x2 - x1) / abs(y2 - y1));
               }
            }
         }
         return true;
      }

      else if (x1 < x2 && y1 > y2) {
         int x = x1, y = y1;
         //Point currPt(); //(x, y);
         while (x <= x2 && y >= y2) {
            Point currPt(x, y);
            if (currPt.draw(scr, ch) == true) {
               cout << "loop in Line.DRAW() :  " << x << " " << y << endl;
               if (abs(x2 - x1) > abs(y2 - y1)) {
                  x++;
                  y = y1 - static_cast<int>((x * abs(y2 - y1) / abs(x2 - x1)));
                  //y = std::round(x * abs(y2 - y1) / abs(x2 - x1));
               }
               else {
                  y--;
                  x = x2 - static_cast<int>((y * abs(x2 - x1) / abs(y2 - y1)));
                  //x = x2 - std::round(y * abs(x2 - x1) / abs(y2 - y1));
               }
            }
         }
         return true;
      }

      else {
         if (x1 > x2 && y1 > y2) {
            int a = x1, b = y1;
            x1 = x2;
            y1 = y2;
            x2 = a;
            y2 = b;
         }

         int x = x1, y = y1;
         //Point currPt(); //(x, y);

         while (x <= x2 && y <= y2) {
            Point currPt(x, y);
            if (currPt.draw(scr, ch) == true) {
               cout << "loop in Line.DRAW() :  " << x << " " << y << endl;

               if (abs(x2 - x1) > abs(y2 - y1)) {
                  x++;
                  y = static_cast<int>((x * abs(y2 - y1) / abs(x2 - x1)));
                  //y = std::round(x * abs(y2 - y1) / abs(x2 - x1));
               }
               else {
                  y++;
                  x = static_cast<int>((y * abs(x2 - x1) / abs(y2 - y1)));
                  //x = std::round(y * abs(x2 - x1) / abs(y2 - y1));
               }
               //x++;
               //y++;
            }
         }
      }


      return true;
   }

};






/*
int main() {
   Screen a = Screen();
   /*
   for (unsigned int i = 0; i < 100; i++)
   {
        for (unsigned int k = 0; k < 100; k++)
           cout << a.pixels[i][k];
           //cout << "OK";
       cout << endl;

   }
   
   ////////////
   

   cout << a.toString();

   cout << endl << endl;

   Point b(50, 50);
   b.draw(a, 'Q');

   cout << a.toString();

   for (int i = 0; i <= 0; i++)
      cout << "OK" << endl;

   Line c(2, 2, 30, 2);// , 0, 0);
   c.draw(a, '*');
   cout << a.toString();


   return 0;
}
*/








int main(){
    Screen a = Screen();
    /*
    for (unsigned int i = 0; i < 100; i++)
    {
         for (unsigned int k = 0; k < 100; k++)
            cout << a.pixels[i][k];
            //cout << "OK";
        cout << endl;
        
    } 
    */
    
    cout <<a.toString();
    
    cout << endl << endl;
    
    Point b(50, 50);
    b.draw(a, 'Q');
    
    cout << a.toString();
    
    for (int i = 0; i <= 0; i++)
       cout << "OK" << endl;
    
    Line c(2, 2, 30, 2);// , 0, 0);
    c.draw(a, '*');
    cout << a.toString();

    
    return 0;
}
