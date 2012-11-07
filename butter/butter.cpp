/*
ID: skrstic2
PROG: butter
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

#define MAXP 810
#define MAXN 510

using namespace std;

ifstream fin("butter.in");
ofstream fout("butter.out");
int n, p, cow[MAXN], dist[MAXP][MAXP], sol;

void init()
{
   for (int i = 0; i < MAXP; i++)
   {
      for (int j = 0; j < MAXP; j++)
         dist[i][j] = 100000;
      dist[i][i] = 0;
   }
}

void read()
{
   int x, y, z, c;
   fin >> n >> p >> c;
   for (int i = 0; i < n; i++)
   {
      fin >> x;
      cow[i] = x - 1;
   }
   for (int i = 0; i < c; i++)
   {
      fin >> x >> y >> z;
      dist[x - 1][y - 1] = dist[y - 1][x - 1] = z;
   }
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   for (int k = 0; k < p; k++)
      for (int i = 0; i < p; i++)
         for (int j = 0; j < p; j++)
            if (dist[i][j] > dist[i][k] + dist[k][j])
               dist[i][j] = dist[i][k] + dist[k][j];

   sol = 1000000;
   for (int i = 0; i < p; i++)
   {
      int temp = 0;
      for (int j = 0; j < n; j++)
         temp += dist[i][cow[j]];
      if (temp < sol)
         sol = temp;
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
