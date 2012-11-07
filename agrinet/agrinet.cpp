/*
ID: skrstic2
PROG: agrinet
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

#define MAXN 1000

using namespace std;

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
int n, sol, dist[MAXN][MAXN];

void init()
{
}

void read()
{
   fin >> n;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         fin >> dist[i][j];
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   bool marked[n];
   int ddist[n];
   for (int i = 0; i < n; i++)
      ddist[i] = 2147483647;
   memset(marked, 0, sizeof(marked[0]) * n);
   sol = 0;
   marked[0] = true;
   for (int i = 0; i < n; i++)
      ddist[i] = dist[0][i];
   for (int i = 0; i < n - 1; i++)
   {
      int min = 2147483647;
      int minj;
      for (int j = 0; j < n; j++)
         if (!marked[j] && ddist[j] < min)
         {
            min = ddist[j];
            minj = j;
         }
      marked[minj] = true;
      sol += min;
      for (int j = 0; j < n; j++)
         if (ddist[j] > dist[minj][j])
            ddist[j] = dist[minj][j];
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
