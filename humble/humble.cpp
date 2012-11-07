/*
ID: skrstic2
PROG: humble
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

#define MAXN 100010
#define MAXK 110
#define INF 2147483647

using namespace std;

ifstream fin("humble.in");
ofstream fout("humble.out");
int sol, k, n, num[MAXK], lastused[MAXN], mid, bound, l;
int nums[MAXN];

void init()
{
}

void read()
{
   fin >> k >> n;
   for (int i = 0; i < k; i++)
      fin >> num[i];
}

void write()
{
   fout << sol << endl;
}

int find(int test, int prime, int h)
{
   bound = (int)ceil((double)test/prime);
   if (nums[0] >= bound)
   {
      lastused[prime] = 0;
      return prime * nums[0];
   }
   
   l = lastused[prime];
   while (l < h)
   {
      mid = (l + h) / 2;
      if (bound == nums[mid])
      {
         lastused[prime] = mid;
         return prime * bound;
      }
      if (bound < nums[mid])
         h = mid;
      else
         l = mid + 1;
   }
   if (nums[l] >= bound)
   {
      lastused[prime] = l;
      return prime * nums[l];
   }
   else if (nums[h] >= bound)
   {
      lastused[prime] = h;
      return prime * nums[h];
   }
   else
      return INF;
}

void solve()
{
   sort(num, num + k);
   int test = num[0] + 1, best, possible, last = 0;
   nums[0] = num[0];
   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j < k; j++)
         if (test == num[j])
         {
            nums[i] = test;
            last = j;
         }

      if (nums[i] == 0)
      {
         best = INF;
         if (last < k - 1)
            best = num[last + 1];
         for (int j = 0; j < k; j++)
         {
            possible = find(test, num[j], i - 1);
            if (possible < best)
               best = possible;
         }
         nums[i] = best;
         if (best == num[last + 1])
            last++;
      }
      test = nums[i] + 1;
   }
   sol = nums[n - 1];
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
