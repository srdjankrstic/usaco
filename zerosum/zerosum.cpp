/*
ID: skrstic2
PROG: zerosum
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

#define MAXN 30

using namespace std;

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
int n;
vector<string> sol;
string current;

void read()
{
   fin >> n;
}

void write()
{
   sort(sol.begin(), sol.end());
   for (int i = 0, len = sol.size(); i < len; i++)
      fout << sol[i] << endl;
}

void recurse(int t, int c, int d, bool plus)
{
   if (d == n)
   {
      if (plus)
         t += c;
      else
         t -= c;
      if (t == 0)
         sol.push_back((string)current);
      return;
   }

   current[2 * d - 1] = ' ';
   current[2 * d] = d + 1 + '0';
   recurse(t, 10 * c + d + 1, d + 1, plus);

   current[2 * d - 1] = '+';
   if (plus)
      recurse(t + c, d + 1, d + 1, true);
   else
      recurse(t - c, d + 1, d + 1, true);

   current[2 * d - 1] = '-';
   if (plus)
      recurse(t + c, d + 1, d + 1, false);
   else
      recurse(t - c, d + 1, d + 1, false);

}

void solve()
{
   current.append(2 * n - 1, '1');

   recurse(0, 1, 1, true);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
