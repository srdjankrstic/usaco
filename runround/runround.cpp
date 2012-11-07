/*
ID: skrstic2
PROG: runround
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

ifstream fin("runround.in");
ofstream fout("runround.out");
unsigned int n, sol;

void read()
{
   fin >> n;
}

void write()
{
   fout << sol << endl;
}

int runaround(unsigned int x)
{
   short digits[10];
   int dig = 0, ret = 1;
   bool touched[10] = {false}, seen[10] = {false};

   while (x != 0)
   {
      digits[dig++] = x % 10;
      x /= 10;
   }

   for (int i = dig - 1; i >= 0; i--)
      if (seen[digits[i]] || digits[i] == 0) 
      {
         for (int j = 0; j < i; j++)
            ret *= 10;
         return ret;
      }
      else
         seen[digits[i]] = true;

   int pos = dig - 1;
   int minright = dig;
   int t = 0;
   while (!touched[pos])
   {
      touched[pos] = true;
      if (pos < minright)
         minright = pos;
      t++;
      pos = (pos - digits[pos] + dig * 10) % dig;
   }

   if (pos == dig - 1 && t == dig)
      return 0;

   for (int i = 0; i < minright; i++)
      ret *= 10;
   return ret;
}

void solve()
{
   int t;
   sol = n + 1;
   while (1)
   {
      t = runaround(sol);
      if (t == 0)
         break;
      sol /= t;
      sol++;
      sol *= t;
   }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
