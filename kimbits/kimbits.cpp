/*
ID: skrstic2
PROG: kimbits
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

#define MAXN 32

using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
unsigned int n, l, k;
unsigned int choose[MAXN][MAXN];
unsigned int sol[MAXN];

void init()
{
   for (int i = 0; i < 32; i++)
      choose[i][0] = 1;
   for (int i = 1; i < 32; i++)
      for (int j = 1; j <= i; j++)
         choose[i][j] = choose[i - 1][j - 1] * i / j;
}

void read()
{
   fin >> n >> l >> k;
}

void write()
{
   for (unsigned int i = 0; i < n; i++)
      fout << sol[i];
   fout << endl;
}

void solve()
{
   for (unsigned int i = 0; i < n; i++)
   {
      if (k == 1)
         break;
      unsigned int total = 0;
      for (unsigned int j = 0; j <= l; j++)
         if (n - i - 1 >= j)
            total += choose[n - i - 1][j];
      if (total < k)
      {
         k -= total;
         l--;
         sol[i] = 1;
      }
      else
         sol[i] = 0;         
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
