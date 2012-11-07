/*
ID: skrstic2
PROG: castle
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

#define MAXN 50

using namespace std;

ifstream fin("castle.in");
ofstream fout("castle.out");
int m, n;
bool wall[MAXN][MAXN][4];
int rooms, maxsize, maxsize2, breaki, breakj;
char breakdir;
int room[MAXN][MAXN], pi, pj, cursize, size[MAXN];
bool marked[MAXN][MAXN];
char chardir[] = {'N', 'E', 'S', 'W'};
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

void read()
{
   int wallcode;
   fin >> m >> n;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
      {
         fin >> wallcode;
         wall[i][j][0] = (wallcode >> 1) & 1;
         wall[i][j][1] = (wallcode >> 2) & 1;
         wall[i][j][2] = (wallcode >> 3) & 1;
         wall[i][j][3] = (wallcode >> 0) & 1;
      }
}

void write()
{
   fout << rooms << endl << maxsize << endl << maxsize2 << endl << breaki + 1 << " " << breakj + 1 << " " << breakdir << endl;
}

void DFS(int i, int j)
{
   cursize++;
   marked[i][j] = true;
   room[i][j] = rooms;
   for (int d = 0; d < 4; d++)
   {
      if (wall[i][j][d])
         continue;
      pi = i + di[d]; pj = j + dj[d];
      if (pi >= 0 && pj >= 0 && pi < n && pj < m && !marked[pi][pj])
         DFS(pi, pj);
   }
}

void printall()
{
   for (int j = 0; j < 4 * m + 1; j++)
      cout << '#';
   cout << endl;
   for (int i = 0; i < n; i++)
   {
      cout << '#';
      for (int j = 0; j < m; j++)
         cout << (room[i][j] > 9 ? "" : " ") << room[i][j] << ' ' << (wall[i][j][1] ? '#' : '|');
      cout << endl;
      cout << '#';
      for (int j = 0; j < m; j++)
         cout << (wall[i][j][2] ? "###" : "---") << '#';
      cout << endl;
   }

}

void solve()
{
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         if (!marked[i][j])
         {
            cursize = 0;
            DFS(i, j);
            size[rooms++] = cursize;
            if (cursize > maxsize)
               maxsize = cursize;
         }

//   printall();
   for (int j = 0; j < m; j++)
      for (int i = n - 1; i >= 0; i--)
         for (int d = 0; d < 4; d++)
         {
            pi = i + di[d]; pj = j + dj[d];
            if (pi >= 0 && pj >= 0 && pi < n && pj < m)
               if (room[i][j] != room[pi][pj] && size[room[i][j]] + size[room[pi][pj]] > maxsize2)
               {
                  maxsize2 = size[room[i][j]] + size[room[pi][pj]];
                  breaki = i; breakj = j; breakdir = chardir[d];
               }
         }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
