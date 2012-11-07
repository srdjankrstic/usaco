/*
ID: skrstic2
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

#define MAXN 1000

using namespace std;

ifstream fin("ratios.in");
ofstream fout("ratios.out");
int sol1, sol2, sol3, solt, a1, a2, a3, b1, b2, b3, c1, c2, c3, at, bt, ct;

void init()
{
}

void read()
{
   fin >> at >> bt >> ct;
   fin >> a1 >> b1 >> c1;
   fin >> a2 >> b2 >> c2;
   fin >> a3 >> b3 >> c3;
}

void write()
{
   if (solt == 0)
      fout << "NONE" << endl;
   else
      fout << sol1 << " " << sol2 << " " << sol3 << " " << solt << endl;
}

void solve()
{
   int ta, tb, tc, best = 1000;
   for (int x = 0; x <= 100; x++)
      for (int y = 0; y <= 100; y++)
         for (int z = 0; z <= 100; z++)
         {
            if (x == 0 && y == 0 && z == 0)
               continue;
            ta = x * a1 + y * a2 + z * a3;
            tb = x * b1 + y * b2 + z * b3;
            tc = x * c1 + y * c2 + z * c3;
            if ((at == 0 || ta % at == 0) && (bt == 0 || tb % bt == 0) && (ct == 0 || tc % ct == 0) && (ta * bt == tb * at) && (ta * ct == tc * at) && x + y + z < best)
            {
               best = x + y + z;
               sol1 = x; sol2 = y; sol3 = z;
               solt = ta / at;
            }
         }
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
