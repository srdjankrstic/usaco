/*
ID: skrstic2
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct dbl {
   int p;
   int q;

   friend bool operator< (dbl const& a, dbl const& b)
   {
      return a.p < b.p ? true : (a.p == b.p ? a.q < b.q : false);
   }
};

ifstream FIN("packrec.in");
ofstream FOUT("packrec.out");
int SOL = 2000000000;
dbl RECTS[4];
vector<dbl> SOLSV;
set<dbl> SOLSS;

bool cmp(dbl a, dbl b)
{
   return a.p < b.p;
}

dbl config1(dbl r1, dbl r2, dbl r3, dbl r4)
{
   int p, q;
   p = max(max(max(r1.p, r2.p), r3.p), r4.p);
   q = r1.q + r2.q + r3.q + r4.q;
   dbl ret = {p, q};
   return ret;
}

dbl config2(dbl r1, dbl r2, dbl r3, dbl r4)
{
   int p, q;
   p = max(max(r1.p, r2.p), r3.p) + r4.p;
   q = max(r4.q, r1.q + r2.q + r3.q);
   dbl ret = {p, q};
   return ret;
}

dbl config3(dbl r1, dbl r2, dbl r3, dbl r4)
{
   int p, q;
   p = max(r1.p, r4.p + max(r2.p, r3.p));
   q = r1.q + max(r4.q, r2.q + r3.q);
   dbl ret = {p, q};
   return ret;
}

dbl config4(dbl r1, dbl r2, dbl r3, dbl r4)
{
   int p, q;
   p = max(max(r1.p, r4.p), r2.p + r3.p);
   q = r1.q + r4.q + max(r2.q, r3.q);
   dbl ret = {p, q};
   return ret;
}

dbl config5(dbl r1, dbl r2, dbl r3, dbl r4)
{
   int p, q;
   p = max(max(r1.p + r2.p, r3.p), r4.p);
   q = max(r1.q, r2.q) + r3.q + r4.q;
   dbl ret = {p, q};
   return ret;
}

dbl config6(dbl r1, dbl r2, dbl r3, dbl r4)
{
   int p, q;
   p = max(r1.p + r2.p, r3.p + r4.p);
   if (r3.q < r4.q)
      p = max(p, r1.p + r4.p);
   
   q = max(max(r1.q + r3.q, r2.q), r4.q);
   if (r1.p + r2.p > r3.p && r1.p <= r3.p + r4.p)
      q = max(q, r2.q + r4.q);
   if (r3.p < r1.p)
      q = max(q, r1.q + r4.q);
   if (r1.p + r2.p <= r3.p)
      q = max(q, r2.q + r3.q);
   if (r3.p > r1.p)
      q = max(q, r2.q + r3.q);
   dbl ret = {p, q};
   return ret;
}

dbl r(dbl rect)
{
   dbl ret = {rect.q, rect.p};
   return ret;
}

void test(dbl potentialsol)
{
   if (potentialsol.p > potentialsol.q)
      potentialsol = r(potentialsol);
   int area = potentialsol.p * potentialsol.q;
   if (area < SOL)
   {
      SOL = area;
      SOLSV.clear();
      SOLSS.clear();
      SOLSV.push_back(potentialsol);
      SOLSS.insert(potentialsol);
   }
   else if (area == SOL)
      if (SOLSS.find(potentialsol) == SOLSS.end())
      {
         SOLSV.push_back(potentialsol);
         SOLSS.insert(potentialsol);
      }
}

void read()
{
   for (int i = 0; i < 4; i++)
      FIN >> RECTS[i].p >> RECTS[i].q;
}

void write()
{
   FOUT << SOL << endl;
   for (int i = 0, len = SOLSV.size(); i < len; i++)
      FOUT << SOLSV[i].p << " " << SOLSV[i].q << endl;
}

bool FLAG = true;

void doalltests(dbl rect1, dbl rect2, dbl rect3, dbl rect4)
{
      test(config1(rect1, rect2, rect3, rect4));
      test(config2(rect1, rect2, rect3, rect4));
      test(config3(rect1, rect2, rect3, rect4));
      test(config4(rect1, rect2, rect3, rect4));
      test(config5(rect1, rect2, rect3, rect4));
      test(config6(rect1, rect2, rect3, rect4));
      // if (SOL == 36 && FLAG)
      // {
      //    cout << rect1.p << ", " << rect1.q << "; " << rect2.p << ", " << rect2.q << "; " << rect3.p << ", " << rect3.q << "; " << rect4.p << ", " << rect4.q << endl;
      //    FLAG = false;
      // }
}

void solve()
{
   bool marked[4];
   int temp[5];
   dbl rect1, rect2, rect3, rect4;
   for (int perm = 0; perm < 24; perm++)
   {
      for (int i = 0; i < 4; i++)
         marked[i] = false;
      
      // calc rect1
      int pos = perm / 6;
      marked[pos] = true;
      rect1 = RECTS[pos];
      temp[1] = pos;
 
      // calc rect2
      int rem = perm % 6;
      pos = rem / 2;
      int k = -1, i = 0;
      do
      {
         k++;
         if(marked[k])
            k++;
      }
      while (i++ < pos);

      marked[k] = true;
      rect2 = RECTS[k];
      temp[2] = k;

      // calc rect3, rect4
      rem = rem % 2;
      bool first = true;
      for (int i = 0; i < 4; i++)
         if (!marked[i])
         {
            if ((rem == 0 && first) || (rem == 1 && !first))
            {
               rect3 = RECTS[i];
               temp[3] = i;
            }
            else
            {
               rect4 = RECTS[i];
               temp[4] = i;
            }
            first = false;
         }

//      for (int i = 1; i < 5; i++)
//         cout << temp[i] << " ";
//      cout << endl;

      doalltests(rect1, rect2, rect3, rect4);
      doalltests(rect1, rect2, rect3, r(rect4));
      doalltests(rect1, rect2, r(rect3), rect4);
      doalltests(rect1, rect2, r(rect3), r(rect4));
      doalltests(rect1, r(rect2), rect3, rect4);
      doalltests(rect1, r(rect2), rect3, r(rect4));
      doalltests(rect1, r(rect2), r(rect3), rect4);
      doalltests(rect1, r(rect2), r(rect3), r(rect4));
      doalltests(r(rect1), rect2, rect3, rect4);
      doalltests(r(rect1), rect2, rect3, r(rect4));
      doalltests(r(rect1), rect2, r(rect3), rect4);
      doalltests(r(rect1), rect2, r(rect3), r(rect4));
      doalltests(r(rect1), r(rect2), rect3, rect4);
      doalltests(r(rect1), r(rect2), rect3, r(rect4));
      doalltests(r(rect1), r(rect2), r(rect3), rect4);
      doalltests(r(rect1), r(rect2), r(rect3), r(rect4));
   }
   sort(SOLSV.begin(), SOLSV.end());
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
