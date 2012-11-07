/*
ID: skrstic2
PROG: fence
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

#define MAXF 1050

using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");
int f, n, fence[MAXF], degree[MAXF], pos;
int edge[MAXF][MAXF];
int tempfence[MAXF];

void init()
{
}

void read()
{
   int a, b;
   fin >> f;
   for (int i = 0; i < f; i++)
   {
      fin >> a >> b;
      edge[a - 1][b - 1]++; edge[b - 1][a - 1]++;
      degree[a - 1]++;
      degree[b - 1]++;
      n = max(n, max(a, b));
   }
}

void write()
{
   for (int i = f; i >= 0; i--)
      fout << fence[i] + 1 << endl;
}

void euler(int i)
{
   if (degree[i] == 0)
      fence[pos++] = i;
   else
   {
      while (degree[i] > 0)
      {
         int j;
         for (j = 0; j < n; j++)
            if (edge[i][j] > 0)
               break;
         edge[i][j]--; edge[j][i]--;
         degree[i]--; degree[j]--;
         euler(j);
      }
      fence[pos++] = i;
   }
}

void solve()
{
   int start = 0;
   pos = 0;
   for (int i = 0; i < n; i++)
      if (degree[i] % 2 == 1)
      {
         start = i;
         break;
      }
   euler(start);
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
