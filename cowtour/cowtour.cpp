/*
ID: skrstic2
PROG: cowtour
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

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
bool edge[MAXN][MAXN], marked[MAXN];
int i, n, x[MAXN], y[MAXN], room[MAXN], rooms;
double sol, diam[MAXN], farthest[MAXN], dist[MAXN][MAXN];

void init()
{
}

void read()
{
   fin >> n;
   for (int i = 0; i < n; i++)
      fin >> x[i] >> y[i];
   string line;
   getline(fin, line);
   for (int i = 0; i < n; i++)
   {
      getline(fin, line);
      for (int j = 0, len = line.length(); j < len; j++)
         if (line[j] == '1')
            edge[i][j] = true;
   }
}

void write()
{
   fout.precision(6);
   fout.setf(ios::fixed, ios::floatfield);
   fout << sol << endl;
}

double distances(int a, int b)
{
   return sqrt((double)(x[a] - x[b]) * (double)(x[a] - x[b]) + (double)(y[a] - y[b]) * (double)(y[a] - y[b]));
}

void DFS(int a)
{
   room[a] = rooms;
   marked[a] = true;
   for (int i = 0; i < n; i++)
      if (!marked[i] && edge[a][i])
         DFS(i);
}

void solve()
{
   memset(marked, false, sizeof(marked[0]) * MAXN);
   for (int i = 0; i < n; i++)
      if (!marked[i])
      {
         DFS(i);
         rooms++;
      }

   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         dist[i][j] = 1e08;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         if (edge[i][j])
            dist[i][j] = distances(i, j);

   for (int k = 0; k < n; k++)
      for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            if (i != j && i != k && k != j && dist[i][j] > dist[i][k] + dist[k][j])
               dist[i][j] = dist[i][k] + dist[k][j];
   for (int i = 0; i < n; i++)
      dist[i][i] = 0;

   memset(farthest, 0, sizeof(farthest[0]) * MAXN);
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
         if (room[i] == room[j] && dist[i][j] > farthest[i])
            farthest[i] = dist[i][j];

   memset(diam, 0, sizeof(diam[0]) * MAXN);
   for (int i = 0; i < n; i++)
      if (farthest[i] > diam[room[i]])
         diam[room[i]] = farthest[i];

   sol = 1e08;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++)
         if (room[i] != room[j])
         {
            double here = max(max(distances(i, j) + farthest[i] + farthest[j], diam[room[i]]), diam[room[j]]);
            if (here < sol)
               sol = here;
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
