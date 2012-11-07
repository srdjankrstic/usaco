/*
ID: skrstic2
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#define _MAXN 21

using namespace std;

ifstream fin("milk3.in");
ofstream fout("milk3.out");
int a, b, c, sol[_MAXN * _MAXN * _MAXN], soln = 0;
bool marked[_MAXN][_MAXN][_MAXN];
int temp;

void read()
{
   fin >> a >> b >> c;
}

void write()
{
   sort(sol, sol + soln);
   for (int i = 0; i < soln - 1; i++)
      fout << sol[i] << " ";
   fout << sol[soln - 1] << endl;
}

void DFS(int x, int y, int z)
{
   marked[x][y][z] = true;
   if (x == 0)
      sol[soln++] = z;

   temp = min(x, b - y);
   if (!marked[x - temp][y + temp][z])
      DFS(x - temp, y + temp, z);

   temp = min(x, c - z);
   if (!marked[x - temp][y][z + temp])
      DFS(x - temp, y, z + temp);

   temp = min(y, a - x);
   if (!marked[x + temp][y - temp][z])
      DFS(x + temp, y - temp, z);

   temp = min(y, c - z);
   if (!marked[x][y - temp][z + temp])
      DFS(x, y - temp, z + temp);

   temp = min(z, a - x);
   if (!marked[x + temp][y][z - temp])
      DFS(x + temp, y, z - temp);

   temp = min(z, b - y);
   if (!marked[x][y + temp][z - temp])
      DFS(x, y + temp, z - temp);
}

void solve()
{
   DFS(0, 0, c);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
