/*
ID: skrstic2
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

#define _MAXN 10

using namespace std;

ifstream FIN("crypt1.in");
ofstream FOUT("crypt1.out");

int N, SOL, digits[_MAXN];
bool ISDIGIT[_MAXN];

int digok(int num)
{
   while (num != 0)
   {
      if (!ISDIGIT[num % 10])
         return false;
      num /= 10;
   }
   return true;
}

bool works(int first, int ten, int one)
{
   int prod1 = first * ten;
   int prod2 = first * one;
   int prod3 = 10 * prod1 + prod2;
   if (prod1 >= 100 && prod1 < 1000 && prod2 >= 100 && prod2 < 1000 && prod3 >= 1000 && prod3 < 10000 && digok(prod1) && digok(prod2) && digok(prod3))
      return true;
   return false;
}

void read()
{
   FIN >> N;
   for (int i = 0; i < N; i++)
   {
      FIN >> digits[i];
      ISDIGIT[digits[i]] = true;
   }
}

void write()
{
   FOUT << SOL << endl;
}

void solve()
{
   int a, b, c, d, e;
   SOL = 0;
   for (a = 0; a < N; a++)
      for (b = 0; b < N; b++)
         if (ISDIGIT[(digits[a] * digits[b]) % 10])
            for (c = 0; c < N; c++)
               if (ISDIGIT[(digits[a] * digits[c]) % 10])
                  for (d = 0; d < N; d++)
                     for (e = 0; e < N; e++)
                        if (works(100 * digits[e] + 10 * digits[d] + digits[a], digits[c], digits[b]))
                            SOL++;
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
