/*
ID: skrstic2
PROG: fact4
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

#define MAXN 1000

using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");
int n, sol;

void init()
{
}

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
   int fives = 0, t = n;
   while (t > 0)
   {
      fives += t / 5;
      t /= 5;
   }
   sol = 1;
   for (int i = 1; i <= n; i++)
   {
      int x = i;
      while (x % 5 == 0)
         x /= 5;
      while (x % 2 == 0 && fives-- > 0)
         x /= 2;
      sol *= x;
      sol %= 10;
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
