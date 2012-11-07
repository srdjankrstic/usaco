/*
ID: skrstic2
PROG: hamming
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

#define MAXN 64

using namespace std;

ifstream fin("hamming.in");
ofstream fout("hamming.out");
int n, b, d, sol[MAXN];
int maxn;
bool found;

void read()
{
   fin >> n >> b >> d;
}

void write()
{
   for (int i = 0; i < n; i++)
   {
      if (i % 10 != 0)
         fout << ' ';
      else if (i > 0)
         fout << endl;

      fout << sol[i];
   }

   fout << endl;
}

bool distok(int x, int y)
{
   int ret = 0;
   while (x != 0 || y != 0)
   {
      ret += (x & 1) ^ (y & 1);
      if (ret == d)
         return true;
      x >>= 1;
      y >>= 1;
   }
   return false;
}

bool distok(int q)
{
   for (int i = 0; i < q; i++)
      if (!distok(sol[i], sol[q]))
         return false;
   return true;
}

void recurse(int depth)
{
   if (found)
      return;
   if (depth == n)
   {
      found = true;
      write();
      exit(0);
   }
   else
      for (sol[depth] = sol[depth - 1] + 1; !found && sol[depth] < maxn; sol[depth]++)
         if (distok(depth))
            recurse(depth + 1);
}

void solve()
{
   maxn = 1 << b;
   sol[0] = 0;
   recurse(1);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
