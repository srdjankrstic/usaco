/*
ID: skrstic2
PROG: sort3
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

#define MAXN 1001

using namespace std;

ifstream fin("sort3.in");
ofstream fout("sort3.out");
int n, s[MAXN], sol;

void read()
{
   fin >> n;
   for (int i = 0; i < n; i++)
      fin >> s[i];
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   int c[4] = {0}, t[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

   for (int i = 0; i < n; i++)
      c[s[i]]++;
   for (int i = 0; i < c[1]; i++)
      t[1][s[i]]++;
   for (int i = c[1]; i < c[1] + c[2]; i++)
      t[2][s[i]]++;
   for(int i = c[1] + c[2]; i < c[1] + c[2] + c[3]; i++)
      t[3][s[i]]++;

   sol = 2 * (t[1][2] + t[2][1]) - 3 * min(t[1][2], t[2][1]) + min(t[1][3], t[3][1]) + min(t[2][3], t[3][2]);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
