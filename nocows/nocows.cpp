/*
ID: skrstic2
PROG: nocows
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

#define MAXN 201
#define MAXK 101
#define MOD 9901

using namespace std;

ifstream fin("nocows.in");
ofstream fout("nocows.out");
int n, k, sol, ways[MAXN][MAXK];

void read()
{
   fin >> n >> k;
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   ways[1][1] = 1;
   for (int i = 3; i <= n; i += 2)
   {
      for (int j = 2; j <= k; j++)
      {
         for (int left = 1; left <= i - 2; left += 2)
         {
            int right = i - left - 1;
            for (int j1 = 1; j1 < j - 1; j1++)
            {
               ways[i][j] += (ways[left][j1] * ways[right][j - 1]);
               ways[i][j] += (ways[left][j - 1] * ways[right][j1]);
               ways[i][j] %= MOD;
            }
            ways[i][j] += (ways[left][j - 1] * ways[right][j - 1]);
            ways[i][j] %= MOD;
         }
      }
   }
   sol = ways[n][k];
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
