/*
ID: skrstic2
PROG: lamps
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

#define MAXN 101

using namespace std;

ifstream fin("lamps.in");
ofstream fout("lamps.out");
int n, C, lamp[MAXN];
vector<string> sol;
int layout[MAXN];

void read()
{
   int t;
   fin >> n;
   fin >> C;
   fin >> t;
   while (t != -1)
   {
      lamp[t - 1] = 1;
      fin >> t;
   } 
   fin >> t;
   while (t != -1)
   {
      lamp[t - 1] = 2;
      fin >> t;
   }
}

void write()
{
   sort(sol.begin(), sol.end());
   for (int i = 0, len = sol.size(); i < len; i++)
      fout << sol[i] << endl;
   if (sol.size() == 0)
      fout << "IMPOSSIBLE" << endl;
}

void press1()
{
   for (int i = 0; i < n; i++)
      layout[i] = 1 - layout[i];
}

void press2()
{
   for (int i = 0; i < n; i += 2)
      layout[i] = 1 - layout[i];
}

void press3()
{
   for (int i = 1; i < n; i += 2)
      layout[i] = 1 - layout[i];
}

void press4()
{
   for (int i = 0; i < n; i += 3)
      layout[i] = 1 - layout[i];
}

void solve()
{
   int i;
   for (int a = 0; a < 2; a++)
   {
      for (int b = 0; b < 2; b++)
      {
         for (int c = 0; c < 2; c++)
         {
            for (int d = 0; d < 2; d++)
            {
               for (i = 0; i < n; i++)
                  if ((layout[i] == 0 && lamp[i] == 2) || (layout[i] == 1 && lamp[i] == 1))
                     break;
               if (i == n)
               {
                  if (a + b + c + d <= C && (a + b + c + d) % 2 == C % 2)
                  {
                     string s = "";
                     for (int j = 0; j < n; j++)
                        s.append(layout[j] == 0 ? "1" : "0");
                     sol.push_back(s);
                  }
               }
               press4();
            }
            press3();
         }
         press2();
      }
      press1();
   }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
