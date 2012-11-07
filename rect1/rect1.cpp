/*
ID: skrstic2
PROG: rect1
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

#define MAXC 2510

using namespace std;

typedef struct rect rect;

struct rect
{
   int llx, lly, urx, ury, color;
   bool dirty;
   // friend bool operator< (const rect &x, const rect &y)
   // {
   //    int area1 = (x.urx - x.llx) * (x.ury - x.lly);
   //    int area2 = (y.urx - y.llx) * (y.ury - y.lly);
   //    return (are1 < area2) ? true : ((area1 == area2) ? x.color < y.color : false);
   // }
};

ifstream fin("rect1.in");
ofstream fout("rect1.out");
vector<rect> rects;
int a, b, n, color[MAXC], maxc;

rect makerec(int llx, int lly, int urx, int ury, int color)
{
   rect newrec;
   newrec.llx = llx;
   newrec.lly = lly;
   newrec.urx = urx;
   newrec.ury = ury;
   newrec.color = color;
   newrec.dirty = false;
   return newrec;
}

bool intersect(rect r1, rect r2)
{
   if (r2.urx <= r1.llx || r2.llx >= r1.urx || r2.ury <= r1.lly || r2.lly >= r1.ury)
      return false;

   if (r2.llx >= r1.llx && r2.urx <= r1.urx && r2.lly >= r1.lly && r2.ury <= r1.ury)
   {
      rects.push_back(makerec(r1.llx, r2.ury, r2.urx, r1.ury, r1.color));
      rects.push_back(makerec(r2.urx, r2.lly, r1.urx, r1.ury, r1.color));
      rects.push_back(makerec(r2.llx, r1.lly, r1.urx, r2.lly, r1.color));
      rects.push_back(makerec(r1.llx, r1.lly, r2.llx, r2.ury, r1.color));
      return true;
   }

   if (r2.llx <= r1.llx && r2.urx >= r1.urx && r2.lly <= r1.lly && r2.ury >= r1.ury)
      return true;

   if (r2.llx <= r1.llx && r2.urx >= r1.llx && r2.urx <= r1.urx)
   {
      if (r2.ury >= r1.ury && r2.lly >= r1.lly && r2.lly <= r1.ury)
      {
         rects.push_back(makerec(r1.llx, r1.lly, r1.urx, r2.lly, r1.color));
         rects.push_back(makerec(r2.urx, r2.lly, r1.urx, r1.ury, r1.color));
         return true;
      }
      if (r2.ury >= r1.ury && r2.lly <= r1.lly)
      {
         rects.push_back(makerec(r2.urx, r1.lly, r1.urx, r1.ury, r1.color));
         return true;
      }
      if (r2.ury >= r1.lly && r2.ury <= r1.ury)
      {
         if (r2.lly >= r1.lly)
         {
            rects.push_back(makerec(r1.llx, r2.ury, r1.urx, r1.ury, r1.color));
            rects.push_back(makerec(r2.urx, r2.lly, r1.urx, r2.ury, r1.color));
            rects.push_back(makerec(r1.llx, r1.lly, r1.urx, r2.lly, r1.color));
            return true;
         }
         else
         {
            rects.push_back(makerec(r1.llx, r2.ury, r1.urx, r1.ury, r1.color));
            rects.push_back(makerec(r2.urx, r1.lly, r1.urx, r2.ury, r1.color));
            return true;
         }
      }
   }

   if (r2.llx >= r1.llx && r2.llx <= r1.urx && r2.urx >= r1.urx)
   {
      if (r2.ury >= r1.ury && r2.lly >= r1.lly && r2.lly <= r1.ury)
      {
         rects.push_back(makerec(r1.llx, r2.lly, r2.llx, r1.ury, r1.color));
         rects.push_back(makerec(r1.llx, r1.lly, r1.urx, r2.lly, r1.color));
         return true;
      }
      if (r2.ury >= r1.ury && r2.lly <= r1.lly)
      {
         rects.push_back(makerec(r1.llx, r1.lly, r2.llx, r1.ury, r1.color));
         return true;
      }
      if (r2.ury >= r1.lly && r2.ury <= r1.ury)
      {
         if (r2.lly >= r1.lly)
         {
            rects.push_back(makerec(r1.llx, r2.ury, r1.urx, r1.ury, r1.color));
            rects.push_back(makerec(r1.llx, r2.lly, r2.llx, r2.ury, r1.color));
            rects.push_back(makerec(r1.llx, r1.lly, r1.urx, r2.lly, r1.color));
            return true;
         }
         else
         {
            rects.push_back(makerec(r1.llx, r2.ury, r1.urx, r1.ury, r1.color));
            rects.push_back(makerec(r1.llx, r1.lly, r2.llx, r2.ury, r1.color));
            return true;
         }
      }
   }

   if (r1.ury <= r2.ury && r1.ury >= r2.lly)
   {
      if (r1.llx <= r2.llx && r2.urx <= r1.urx && r2.lly >= r1.lly)
      {
         rects.push_back(makerec(r1.llx, r1.lly, r2.llx, r1.ury, r1.color));
         rects.push_back(makerec(r2.llx, r1.lly, r2.urx, r2.lly, r1.color));
         rects.push_back(makerec(r2.urx, r1.lly, r1.urx, r1.ury, r1.color));
         return true;
      }
      if (r1.llx >= r2.llx && r2.urx >= r1.urx && r2.lly >= r1.lly)
      {
         rects.push_back(makerec(r1.llx, r1.lly, r1.urx, r2.lly, r1.color));
         return true;
      }
   }

   if (r2.lly <= r1.lly && r2.ury >= r1.lly)
   {
      if (r1.llx <= r2.llx && r2.urx <= r1.urx && r2.ury <= r1.ury)
      {
         rects.push_back(makerec(r1.llx, r1.lly, r2.llx, r1.ury, r1.color));
         rects.push_back(makerec(r2.llx, r2.ury, r2.urx, r1.ury, r1.color));
         rects.push_back(makerec(r2.urx, r1.lly, r1.urx, r1.ury, r1.color));
         return true;
      }
      if (r1.llx >= r2.llx && r2.urx >= r1.urx && r2.ury <= r1.ury)
      {
         rects.push_back(makerec(r1.llx, r2.ury, r1.urx, r1.ury, r1.color));
         return true;
      }
   }

   if (r2.llx <= r1.llx && r2.urx >= r1.urx && r2.lly >= r1.lly && r2.ury <= r1.ury)
   {
      rects.push_back(makerec(r1.llx, r2.ury, r1.urx, r1.ury, r1.color));
      rects.push_back(makerec(r1.llx, r1.lly, r1.urx, r2.lly, r1.color));
      return true;
   }

   if (r2.llx >= r1.llx && r2.urx <= r1.urx && r2.lly <= r1.lly && r2.ury >= r1.ury)
   {
      rects.push_back(makerec(r1.llx, r1.lly, r2.llx, r1.ury, r1.color));
      rects.push_back(makerec(r2.urx, r1.lly, r1.urx, r1.ury, r1.color));
      return true;
   }
   
   return false;
}
   
void processrec(rect rec)
{
   for (int i = 0, len = rects.size(); i <= len; i++)
      if (intersect(rects[i], rec))
         rects[i].dirty = true;
   rects.push_back(rec);
}

void init()
{
}

void debugp()
{
   int board[a][b];
   for (int i = 0, len = rects.size(); i < len; i++)
      for (int x = rects[i].llx; x < rects[i].urx; x++)
         for (int y = rects[i].lly; y < rects[i].ury; y++)
            board[x][y] = rects[i].color;

   for (int i = a - 1; i >= 0; i--)
   {
      for (int j = 0; j < b; j++)
      {
         printf("%d", board[j][i]);
      }
      printf("\n");
   }
   printf("\n\n");
}

void read()
{
   fin >> a >> b >> n;
   int llx, lly, urx, ury, color;
   vector<rect> rects2;
   maxc = 1;
   rects.push_back(makerec(0, 0, a, b, 1));
//   debugp();
   for (int i = 0; i < n; i++)
   {
      fin >> llx >> lly >> urx >> ury >> color;
      maxc = max(maxc, color);
      processrec(makerec(llx, lly, urx, ury, color));
      for (int j = 0, len = rects.size(); j < len; j++)
         if (!rects[j].dirty)
            rects2.push_back(rects[j]);
      rects.assign(rects2.begin(), rects2.end());;
      rects2.clear();
//      debugp();
   }
}

void write()
{
   for (int i = 1; i <= maxc; i++)
      if (color[i] > 0)
         fout << i << " " << color[i] << endl;
}

void solve()
{
   for (int i = 0, len = rects.size(); i < len; i++)
   {
      if (!rects[i].dirty)
      {
         int area = (rects[i].urx - rects[i].llx) * (rects[i].ury - rects[i].lly);
         color[rects[i].color] += area;
      }
   }
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
