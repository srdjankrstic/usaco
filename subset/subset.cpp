/*
ID: skrstic2
PROG: subset
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

#define MAXN 40

using namespace std;

ifstream fin("subset.in");
ofstream fout("subset.out");
int n;
long long sol;

void read()
{
   fin >> n;
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   long long sums[MAXN * MAXN] = {0};
   
   int max = n * (n + 1) / 2;
   if (max % 2)
      return;
   max /= 2;

   sums[0] = 1;
   for (int i = 1; i <= n; i++)
      for (int s = max - i; s >= 0; s--)
         sums[s + i] += sums[s];

   sol = sums[max] / 2;
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
