/*
ID: skrstic2
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#define _MAXN 251
#define _MAXSOL 10000

using namespace std;

struct sol
{
   int a, b;

   friend bool operator< (sol const &x, sol  const &y)
   {
      return x.b < y.b;
   }
};

ifstream FIN("ariprog.in");
ofstream FOUT("ariprog.out");
int N, M, NUMS[_MAXN * _MAXN], NUM = 0, SOLN = 0;
sol SOL[_MAXSOL];
bool ISNUM[2 * _MAXN * _MAXN];

void read()
{
   FIN >> N >> M;
}

void write()
{
   sort(SOL, SOL + SOLN);
   if (SOLN == 0)
      FOUT << "NONE" << endl;
   else
      for (int i = 0; i < SOLN; i++)
         FOUT << SOL[i].a << " " << SOL[i].b << endl;
}

void solve()
{
   int t, i, j, curr, diff, max, run;
   for (int p = 0; p <= M; p++)
      for (int q = 0; q <= M; q++)
      {
         t = p * p + q * q;
         if (!ISNUM[t])
         {
            ISNUM[t] = true;
            NUMS[NUM++] = t;
         }
      }

   sort(NUMS, NUMS + NUM);

   max = NUMS[NUM - 1];
   for (i = 0; i < NUM - 1; i++)
   {
      for (j = i + 1; j < NUM; j++)
      {
         diff = NUMS[j] - NUMS[i];
         curr = NUMS[j] + diff;
         run = 2;
         while (run < N && curr <= max && ISNUM[curr])
         {
            curr += diff;
            run++;
         }
         if (run >= N)
         {
            SOL[SOLN].a = NUMS[i];
            SOL[SOLN++].b = diff;
         }
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
