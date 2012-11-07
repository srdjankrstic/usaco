/*
ID: skrstic2
PROG: money
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

#define MAXV 25
#define MAXN 10001

using namespace std;

ifstream fin("money.in");
ofstream fout("money.out");
int v, n, c[MAXV];
long long ways[MAXN];

void read()
{
   fin >> v >> n;
   for (int i = 0; i < v; i++)
      fin >> c[i];
}

void write()
{
   fout << ways[n] << endl;
}

void solve()
{
   ways[0] = 1;
   for (int i = 0; i < v; i++)
      for (int j = c[i]; j <= n; j++)
         ways[j] += ways[j - c[i]];
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
