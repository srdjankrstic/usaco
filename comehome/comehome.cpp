/*
ID: skrstic2
PROG: comehome
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
#define INF 2147483647

using namespace std;

ifstream fin("comehome.in");
ofstream fout("comehome.out");
int sol, soli;
int dist[52][52];

int hash(char c)
{
   if (c >= 'a' && c <= 'z')
      return c - 'a';
   return 26 + c - 'A';
}

char unhash(int x)
{
   if (x < 26)
      return x + 'a';
   return x - 26 + 'A';
}

void init()
{
   for (int i = 0; i < 52; i++)
      for (int j = 0; j < 52; j++)
         dist[i][j] = INF;
}

void read()
{
   int p;
   fin >> p;
   char c1, c2;
   int d, a, b;
   for (int i = 0; i < p; i++)
   {
      fin >> c1 >> c2 >> d;
      a = hash(c1);
      b = hash(c2);
      if (dist[a][b] > d)
      {
         dist[a][b] = d;
         dist[b][a] = d;
      }
   }
}

void write()
{
   fout << unhash(soli) << " " << sol << endl;
}

void solve()
{
   for (int k = 0; k < 52; k++)
      for (int i = 0; i < 52; i++)
         for (int j = 0; j < 52; j++)
            if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
               dist[i][j] = dist[i][k] + dist[k][j];

   sol = INF;
   for (int i = 26; i < 51; i++)
      if (dist[i][51] < sol)
      {
         sol = dist[i][51];
         soli = i;
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
