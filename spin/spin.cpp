/*
ID: skrstic2
PROG: spin
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

ifstream fin("spin.in");
ofstream fout("spin.out");
int angle[5], pos[5], w[5], sol;
bool wedge[5][360];

void init()
{
}

void read()
{
   int a, b;
   for (int i = 0; i < 5; i++)
   {
      fin >> angle[i] >> w[i];
      for (int j = 0; j < w[i]; j++)
      {
         fin >> a >> b;
         for (int k = a; k <= a + b; k++)
            wedge[i][k % 360] = true;
      }
   }
}

void write()
{
   if (sol >= 360)
      fout << "none" << endl;
   else
      fout << sol << endl;
}

bool check()
{
   for (int i = 0; i < 360; i++)
      if (wedge[0][(pos[0] - i + 360) % 360] && wedge[1][(pos[1] - i + 360) % 360] &&
          wedge[2][(pos[2] - i + 360) % 360] && wedge[3][(pos[3] - i + 360) % 360] &&
          wedge[4][(pos[4] - i + 360) % 360])
         return true;
   return false;
}

void rotate()
{
   for (int i = 0; i < 5; i++)
      pos[i] = (pos[i] - angle[i] + 360) % 360;
}

void solve()
{
   for (sol = 0; sol < 360; sol++, rotate())
      if (check())
         break;
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
