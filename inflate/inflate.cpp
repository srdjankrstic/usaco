/*
ID: skrstic2
PROG: inflate
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

#define MAXN 10010

using namespace std;

ifstream fin("inflate.in");
ofstream fout("inflate.out");
int m, n, sol, p[MAXN], v[MAXN], best[MAXN];

void init()
{
}

void read()
{
   fin >> m >> n;
   for (int i = 0; i < n; i++)
      fin >> p[i] >> v[i];
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   for (int i = 0; i <= m; i++)
      for (int j = 0; j < n; j++)
         if (i >= v[j] && best[i] < best[i - v[j]] + p[j])
            best[i] = best[i - v[j]] + p[j];
   while (best[m] == 0 && m > 0)
      m--;
   sol = best[m];
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
