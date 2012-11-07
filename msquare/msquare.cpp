/*
ID: skrstic2
PROG: msquare
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

ifstream fin("msquare.in");
ofstream fout("msquare.out");
int c[8], target, sol;
unsigned int forseen[600000];
vector<char> sols;

void mark(int x)
{
   int pos = x / 32;
   int off = x % 32;
   forseen[pos] |= (1U << off);
}

bool ismarked(int x)
{
   int pos = x/32;
   int off = x % 32;
   return ((forseen[pos] & (1U << off)) != 0);
}

int hash()
{
   int h = 0, d = 1;
   for (int i = 0; i < 8; i++)
   {
      h += (c[7 - i] % 8) * d;
      d *= 8;
   }
   return h;
}

void unhash(int x)
{
   for (int i = 0; i < 8; i++)
   {
      c[7 - i] = (x % 8 == 0 ? 8 : x % 8);
      x /= 8;
   }
}

int movea(int x)
{
   unhash(x);
   int d[8];
   for (int i = 0; i < 8; i++)
      d[i] = c[7 - i];
   for (int i = 0; i < 8; i++)
      c[i] = d[i];
   return hash();
}

int moveb(int x)
{
   unhash(x);
   int d[8];
   d[0] = c[3]; d[1] = c[0]; d[2] = c[1]; d[3] = c[2];
   d[4] = c[5]; d[5] = c[6]; d[6] = c[7]; d[7] = c[4];
   for (int i = 0; i < 8; i++)
      c[i] = d[i];
   return hash();
}

int movec(int x)
{
   unhash(x);
   int d[8];
   for (int i = 0; i < 8; i++)
      d[i] = c[i];
   d[1] = c[6]; d[2] = c[1]; d[5] = c[2]; d[6] = c[5];
   for (int i = 0; i < 8; i++)
      c[i] = d[i];
   return hash();
}

void init()
{
}

void read()
{
   for (int i = 0; i < 8; i++)
      fin >> c[i];
   target = hash();
}

void write()
{
   fout << sol << endl;
   int count = 0;
   for (int len = sols.size(), i = len - 1; i >= 0; i--)
   {
      fout << sols[i];
      count++;
      if (count % 60 == 0)
         fout << endl;
   }
   if (count % 60 != 0 || count == 0)
      fout << endl;
}

void solve()
{
   if (target == 2739128)
      return;

   int bfsq[50000], parent[50000];
   char move[50000];
   int l = 0, r = 0;
   bfsq[0] = 2739128;
   mark(bfsq[0]);
   int cur, newone;
   while (l <= r)
   {
      cur = bfsq[l++];
      newone = movea(cur);
      if (!ismarked(newone))
      {
         mark(newone);
         bfsq[++r] = newone;
         move[r] = 'A';
         parent[r] = l - 1;
         if (newone == target)
            break;
      }

      newone = moveb(cur);
      if (!ismarked(newone))
      {
         mark(newone);
         bfsq[++r] = newone;
         move[r] = 'B';
         parent[r] = l - 1;
         if (newone == target)
            break;
      }

      newone = movec(cur);
      if (!ismarked(newone))
      {
         mark(newone);
         bfsq[++r] = newone;
         move[r] = 'C';
         parent[r] = l - 1;
         if (newone == target)
            break;
      }
   }
   sol = 0;
   cur = r;
   while (cur > 0)
   {
      sols.push_back(move[cur]);
      cur = parent[cur];
      sol++;
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
