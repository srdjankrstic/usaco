/*
ID: skrstic2
PROG: ttwo
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

#define MAXN 11

using namespace std;

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
bool wall[MAXN][MAXN];
int ci, cj, fi, fj, cd, fd, sol;
int di[] = {-1, 0, 1,  0};
int dj[] = { 0, 1, 0, -1};

void init()
{
}

void read()
{
   char c;
   string dummy;
   for (int i = 0; i < 10; i++)
   {
      for(int j = 0; j < 10; j++)
      {
         fin >> c;
         switch (c)
         {
            case '.':
               wall[i][j] = false;
               break;
            case 'F':
               fi = i;
               fj = j;
               wall[i][j] = false;
               break;
            case 'C':
               ci = i;
               cj = j;
               wall[i][j] = false;
               break;
            case '*':
               wall[i][j] = true;
               break;
            default:
               break;
         }
      }
   }
}

void print()
{
   for (int i = 0; i < 10; i++)
   {
      for (int j = 0; j < 10; j++)
         if (ci == i && cj == j)
            fout << 'C';
         else if (fi == i && fj == j)
            fout << 'F';
         else
            fout << (wall[i][j] ? '*' : '.');
      fout << endl << endl << endl;
   }
}

void write()
{
   fout << sol << endl;
}

void solve()
{
   cd = 0; fd = 0;
   int pi, pj;
   int step;
   for (step = 0; step < 200000; step++)
   {
//      if (step < 30)
//         print();
      if (ci == fi && cj == fj)
         break;

      pi = ci + di[cd]; pj = cj + dj[cd];
      if (pi < 0 || pj < 0 || pi > 9 || pj > 9 || wall[pi][pj])
         cd = (cd + 1) % 4;
      else
      {
         ci = pi;
         cj = pj;
      }

      pi = fi + di[fd]; pj = fj + dj[fd];
      if (pi < 0 || pj < 0 || pi > 9 || pj > 9 || wall[pi][pj])
         fd = (fd + 1) % 4;
      else
      {
         fi = pi;
         fj = pj;
      }
   }
   sol = (step < 200000 ? step : 0);
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
