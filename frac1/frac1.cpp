/*
ID: skrstic2
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

#define MAXN 161

using namespace std;

struct frac
{
   int p, q;
   
   friend bool operator< (const frac &x, const frac &y)
   {
      return ((float)(x.p) / (float)(x.q) < (float)(y.p) / (float)(y.q));
   }
};

ifstream fin("frac1.in");
ofstream fout("frac1.out");
int n, soln;
frac sol[MAXN * MAXN];
bool seen[MAXN][MAXN];

int gcd(int a, int b)
{
   if (a < b)
      return gcd(b, a);
   if (b == 0)
      return a;
   return gcd(b, a % b);
}

frac reduce(int p, int q)
{
   int g = gcd(p, q);
   frac ret = {p / g, q / g};
   return ret;
}

void read()
{
   fin >> n;
}

void write()
{
   sort(sol, sol + soln);
   for (int i = 0; i < soln; i++)
      fout << sol[i].p << '/' << sol[i].q << endl;
}

void solve()
{
   frac t;
   for (int q = 1; q <= n; q++)
      for (int p = 0; p <= q; p++)
      {
         t = reduce(p, q);
         if (!seen[t.p][t.q])
         {
            seen[t.p][t.q] = true;
            sol[soln++] = t;
         }
      }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
