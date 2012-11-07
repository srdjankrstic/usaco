/*
ID: skrstic2
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct point
{
   bool left;
   int value;
} point;

vector<point> POINTS;
int N, SOLH, SOLL;

ifstream FIN("milk2.in");
ofstream FOUT("milk2.out");

int pointscomp(point a, point b) {
   return (a.value < b.value);
}

void read() {
   point lo, hi;
   lo.left = true; hi.left = false;

   FIN >> N;
   for (int i = 0; i < N; i++) {
      FIN >> lo.value >> hi.value;
      POINTS.push_back(lo); POINTS.push_back(hi);
   }
}

void write() {
   FOUT << SOLH << " " << SOLL << endl;
}

void solve() {
   if (N == 0) {
      SOLL = SOLH = 0;
      return;
   }
   sort(POINTS.begin(), POINTS.end(), pointscomp);
   int current = 0, curH = 0, curL = 0, prev = POINTS[0].value;
   for (int i = 0, len = POINTS.size(); i < len; i++)
   {
      bool waszero = false;
      if (current == 0) {
         waszero = true;
         curH = 0;
         curL = POINTS[i].value - prev;
         if (curL > SOLL)
            SOLL = curL;
      }

      while (POINTS[i].value == POINTS[i + 1].value && i < len) {
         if (POINTS[i].left)
            current++;
         else
            current--;
         i++;
      }

      if (POINTS[i].left)
         current++;  
      else
         current--;
      
      if (!waszero) {
         curH += POINTS[i].value - prev;
         if (curH > SOLH)
            SOLH = curH;
      }

      if (current == 0)
         curH = 0;

      prev = POINTS[i].value;
   }
}

int main() {
   read();
   solve();
   write();
   return 0;
}
