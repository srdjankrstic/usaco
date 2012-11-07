/*
ID: skrstic2
PROG: stamps
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

#define MAXN 55
#define MAXK 210
#define MAXVAL 10010

using namespace std;

ifstream fin("stamps.in");
ofstream fout("stamps.out");
int n, k, sol, s[MAXN];
int best[MAXVAL];

void init()
{
}

void read()
{
   fin >> k >> n;
   for (int i = 0; i < n; i++)
      fin >> s[i];
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   for (int i = 0; i < MAXVAL; i++)
      best[i] = MAXK;
   sort(s, s + n);
   best[0] = 0;
   int total = 0;
   bool endnow = false;
   while (true)
   {
      for (int i = 0; i < MAXVAL; i++)
      {
         if (total != 0)
            best[i] = MAXK;
         for (int j = 0; j < n; j++)
            if ((total >= MAXVAL || i - s[j] >= 0) && best[(i - s[j] + MAXVAL) % MAXVAL] + 1 < best[i])
               best[i] = best[(i - s[j] + MAXVAL) % MAXVAL] + 1;
         if (best[i] > k)
         {
            endnow = true;
            break;
         }
         total++;
      }
      if (endnow)
         break;
   }
   sol = total - 1;
}

int main()
{
   cout << sizeof(short) << endl;
   init();
   read();
   solve();
   write();
   return 0;
}
