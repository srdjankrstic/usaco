/*
ID: skrstic2
PROG: fracdec
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
#include <sstream>

#define MAXN 1000010

using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
string sol;
int a, b;
int seen[MAXN];

void init()
{
}

void read()
{
   fin >> a >> b;
}

void write()
{
   unsigned int start = 0;
   while (true)
   {
      fout << sol.substr(start, 76) << endl;
      start += 76;
      if (start >= sol.length())
         break;
   }
}

void solve()
{
   int frac = a / b;
   int rem = 10 * (a % b);
   ostringstream sstream;
   sstream << frac;
   sol = sstream.str();
   sol = sol.append(".");
   int pos = 1;
   while (true)
   {
      if (seen[rem] != 0)
         break;
      seen[rem] = pos++;
      frac = rem / b;
      rem = 10 * (rem % b);
      ostringstream sstream2;
      sstream2 << frac;
      sol = sol.append(sstream2.str());
   }
   int dot = sol.find('.');
   int repeatbeg = dot + seen[rem];
   if (pos - seen[rem] != 1 || sol[repeatbeg] != '0')
   {
      string sol2 = sol.substr(0, repeatbeg).append("(").append(sol.substr(repeatbeg, sol.length() - repeatbeg)).append(")");
      sol = sol2;
   }
   if (sol[sol.length() - 1] == '0' && sol[sol.length() - 2] != '.')
      sol = sol.substr(0, sol.length() - 1);
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
