/*
ID: skrstic2
PROG: maze1
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

#define MAXN 220

using namespace std;

struct coor
{
   int x, y;
};

ifstream fin("maze1.in");
ofstream fout("maze1.out");

int w, h, sol, si[2], sj[2];
int di[] = {-1, 0,  0, 1};
int dj[] = { 0, 1, -1, 0};
bool wall[MAXN][MAXN];

void init()
{
}

void read()
{
   fin >> w >> h;
   w = 2 * w + 1;
   h = 2 * h + 1;
   string line;
   getline(fin, line);
   for (int i = 0; i < h; i++)
   {
      getline(fin, line);
      for (int pos = 0, len = line.length(); pos < w; pos++)
      {
         if (pos >= len || line[pos] == ' ')
            wall[i][pos] = false;
         else
            wall[i][pos] = true;
      }
   }
}

void write()
{
   fout << sol << endl;
}

coor makecoor(int x, int y)
{
   coor c;
   c.x = x; c.y = y;
   return c;
}

void solve()
{
   int exitno = 0;
   for (int i = 0; i < h; i++)
   {
      if (!wall[i][0])
      {
         si[exitno] = i;
         sj[exitno++] = 0;
      }
      if (!wall[i][w - 1])
      {
         si[exitno] = i;
         sj[exitno++] = w - 1;
      }
   }

   for (int i = 0; i < w; i++)
   {
      if (!wall[0][i])
      {
         si[exitno] = 0;
         sj[exitno++] = i;
      }
      if (!wall[h - 1][i])
      {
         si[exitno] = h - 1;
         sj[exitno++] = i;
      }
   }
   if (exitno == 1)
   {
      si[1] = si[0];
      sj[1] = sj[0];
   }

   bool marked[MAXN][MAXN];
   int dist1[MAXN][MAXN], dist2[MAXN][MAXN];
   int pi, pj;
   queue<coor> bfsq;

   for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) { dist1[i][j] = 9999; marked[i][j] = false; }
   bfsq.push(makecoor(si[0], sj[0]));
   dist1[si[0]][sj[0]] = 1;
 frl]][sj[0]] = true;
   while (!bfsq.empty())
   {
      coor cur = bfsq.front();
      bfsq.pop();
      for (int d = 0; d < 4; d++)
      {
         pi = cur.x + di[d];
         pj = cur.y + dj[d];
         if (pi > 0 && pj > 0 && pi < h && pj < w && !wall[pi][pj] && !marked[pi][pj])
         {
            bfsq.push(makecoor(pi, pj));
            marked[pi][pj] = true;
            dist1[pi][pj] = dist1[cur.x][cur.y] + 1;
         }
      }
   }

   for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) { dist2[i][j] = 9999; marked[i][j] = false; }
   bfsq.push(makecoor(si[1], sj[1]));
   dist2[si[1]][sj[1]] = 1;
   marked[si[1]][sj[1]] = true;
   while (!bfsq.empty())
   {
      coor cur = bfsq.front();
      bfsq.pop();
      for (int d = 0; d < 4; d++)
      {
         pi = cur.x + di[d];
         pj = cur.y + dj[d];
         if (pi > 0 && pj > 0 && pi < h && pj < w && !wall[pi][pj] && !marked[pi][pj])
         {
            bfsq.push(makecoor(pi, pj));
            marked[pi][pj] = true;
            dist2[pi][pj] = dist2[cur.x][cur.y] + 1;
         }
      }
   }

   sol = 0;
   for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
         if (!wall[i][j])
         {
            int t = min(dist1[i][j], dist2[i][j]);
            if (t < 9999 && t > sol)
               sol = t;
         }
   sol /= 2;
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
