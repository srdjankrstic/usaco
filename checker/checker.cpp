/*
ID: skrstic2
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

#define MAXN 13

using namespace std;

ifstream fin("checker.in");
ofstream fout("checker.out");
int sol[3][MAXN], soln, n;
int pos[MAXN];
bool vert[MAXN], diag1[2 * MAXN], diag2[2 * MAXN];

void recurse(int d)
{
   if (d == n && soln++ < 3)
         memcpy(sol[soln - 1], pos, n * sizeof(int));
   else
      for (int i = 0; i < n; i++)
         if (!vert[i] && !diag1[d + i] && !diag2[d - i + n - 1])
         {
            pos[d] = i; vert[i] = true; diag1[d + i] = true; diag2[d - i + n - 1] = true;
            recurse(d + 1);
            vert[i] = false; diag1[d + i] = false; diag2[d - i + n - 1] = false;
         }
}

void place(int p)
{ 
   pos[0] = p; vert[p] = true; diag1[p] = true; diag2[n - 1 - p] = true;
   recurse(1);
   vert[p] = false; diag1[p] = false; diag2[n - 1 - p] = false;
}

void read()
{
   fin >> n;
}

void write()
{
   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < n - 1; j++)
         fout << sol[i][j] + 1 << " ";
      fout << sol[i][n - 1] + 1 << endl;
   }
   fout << soln << endl;
}

void solve()
{
   int i;
   for (i = 0; i < n / 2; i++)
      place(i);
   
   int half = soln;
   if (n % 2 == 1)
      place(i++);
   
   if (soln < 3)
      for (; i < n; i++)
         place(i);
   else
      soln += half;
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
