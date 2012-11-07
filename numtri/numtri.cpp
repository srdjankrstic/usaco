/*
ID: skrstic2
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#define MAXN 1000

using namespace std;

ifstream fin("numtri.in");
ofstream fout("numtri.out");
int r, tri[MAXN][MAXN], sol = 0;

void read()
{
   fin >> r;
   for (int i = 0; i < r; i++)
      for (int j = 0; j <= i; j++)
         fin >> tri[i][j];
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   int best[MAXN];
   for (int i = 0; i < r; i++)
      best[i] = tri[r - 1][i];
   for (int i = r - 2; i >= 0; i--)
      for (int j = 0; j <= i; j++)
         best[j] = tri[i][j] + max(best[j], best[j + 1]);
   sol = best[0];
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
