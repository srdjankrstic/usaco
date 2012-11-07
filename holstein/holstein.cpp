/*
ID: skrstic2
PROG: holstein
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

#define INF 2147483647
#define MAXV 25
#define MAXG 15

using namespace std;

ifstream fin("holstein.in");
ofstream fout("holstein.out");
int v, g, req[MAXV], vit[MAXG][MAXV];
int soln = INF, sol;

void read()
{
   fin >> v;
   for (int i = 0; i < v; i++)
      fin >> req[i];
   fin >> g;
   for (int i = 0; i < g; i++)
      for (int j = 0; j < v; j++)
         fin >> vit[i][j];
}

void write()
{
   int sols[MAXG], sn = soln;

   fout << soln;
   for (int i = 0; i < g; i++)
   {
      if (sol & 1)
         sols[--soln] = i;
      sol >>= 1;
   }

   sort(sols, sols + sn);
   for (int i = 0; i < sn; i++)
      fout << " " << sols[i] + 1;
   fout << endl;
}

void trywith(int x)
{
   int ones = 0, y = x;
   int filled[MAXV] = {0};

   for (int i = 0; i < g; i++)
   {
      if (x & 1)
      {
         ones++;
         for (int j = 0; j < v; j++)
            filled[j] += vit[i][j];
      }
      x >>= 1;
   }

   for (int i = 0; i < v; i++)
      if (filled[i] < req[i])
         return;

   if (ones < soln)
   {
      soln = ones;
      sol = y;
   }
}

void solve()
{
   int t = 1 << g;
   for (int i = 0; i < t; i++)
      trywith(i);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
