/*
ID: skrstic2
PROG: concom
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
#include <queue>

#define MAXN 102
#define INF 1e08
#define CUTOFF 0.50L

using namespace std;

struct dbl
{
   int c1, c2;
   
   friend bool operator< (const dbl &a, const dbl &b)
   {
      return a.c1 < b.c1 ? true : (a.c1 == b.c1 ? a.c2 < b.c2 : false);
   }
};

ifstream fin("concom.in");
ofstream fout("concom.out");
double wt[MAXN][MAXN];
vector<dbl> sol;
int n;
bool control[MAXN][MAXN];

void init()
{
}

void read()
{
   fin >> n;
   int a, b, c;
   for (int i = 0; i < n; i++)
   {
      fin >> a >> b >> c;
      wt[a - 1][b - 1] = (double)c / 100.0L;
   }
}

void write()
{
   for (int i = 0, len = sol.size(); i < len; i++)
      fout << sol[i].c1 + 1 << " " << sol[i].c2 + 1 << endl;
}

void solve()
{
   while (true)
   {
      bool found = false;
      for (int i = 0; i < MAXN; i++)
         for (int j = 0; j < MAXN; j++)
            if (i != j && !control[i][j] && wt[i][j] > CUTOFF)
            {
               control[i][j] = true;
               found = true;
               for (int k = 0; k < MAXN; k++)
                  if (k != i && k != j)
                     wt[i][k] += wt[j][k];
            }
      if (!found)
         break;
   }
   
   for (int i = 0; i < MAXN; i++)
      for (int j = 0; j < MAXN; j++)
         if (control[i][j])
         {
            dbl x;
            x.c1 = i; x.c2 = j;
            sol.push_back(x);
         }

   sort(sol.begin(), sol.end());
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
