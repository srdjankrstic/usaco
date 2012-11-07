/*
ID: skrstic2
PROG: preface
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

#define MAXN 1000

using namespace std;

ifstream fin("preface.in");
ofstream fout("preface.out");
int n, numi, numv, numx, numl, numc, numd, numm;

void read()
{
   fin >> n;
}

void write()
{
   if (numi > 0)
      fout << "I " << numi << endl;
   if (numv > 0)
      fout << "V " << numv << endl;
   if (numx > 0)
      fout << "X " << numx << endl;
   if (numl > 0)
      fout << "L " << numl << endl;
   if (numc > 0)
      fout << "C " << numc << endl;
   if (numd > 0)
      fout << "D " << numd << endl;
   if (numm > 0)
      fout << "M " << numm << endl;
}

int calc1(int n)
{
   int c = 7 * (n / 5);
   switch (n % 5)
   {
      case 1:
         c += 1;
         break;
      case 2:
         c += 3;
         break;
      case 3:
         c += 6;
         break;
      case 4:
         c += 7;
      default:
         break;
   }
   return c;
}

int calc5(int n)
{
   int c = 5 * (n / 10);
   int t = n % 10;
   if (t > 3)
      c += (t > 8) ? 5 : t - 3;
   return c;
}

int _i[] = {0, 1, 2, 3, 1, 0, 1, 2, 3, 1};
int _v[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0};

void process(int x)
{
   numm += x / 1000;
   x %= 1000;
   if (x >= 900)
      numm++;
   numc += _i[x / 100];
   numd += _v[x / 100];
   x %= 100;
   if (x >= 90)
      numc++;
   numx += _i[x / 10];
   numl += _v[x / 10];
   x %= 10;
   if (x >= 9)
      numx++;
   numi += _i[x];
   numv += _v[x];
}

void solve()
{
   for (int i = 1; i <= n; i++)
      process(i);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
