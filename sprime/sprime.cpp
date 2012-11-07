/*
ID: skrstic2
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>

#define MAXN 1000

using namespace std;

ifstream fin("sprime.in");
ofstream fout("sprime.out");
vector<int> sol;
int n, number[10], digs[] = {1, 2, 3, 5, 7, 9};

int makenum(int digits)
{
   int num = 0;
   for (int i = 0; i < digits; i++)
   {
      num *= 10;
      num += number[i];
   }
   return num;
}

bool isprime(int x)
{
   if (x < 2)
      return false;
   if (x < 4)
      return true;
   int ul = ceil(sqrt(x));
   for (int i = 2; i <= ul; i++)
      if (x % i == 0)
         return false;
   return true;
}

void recurse(int d)
{
   if (d == 0)
      sol.push_back(makenum(n));
   else
      for (int i = 0; i < 6 ; i++)
      {
         number[n - d] = digs[i];
         if (isprime(makenum(n - d + 1)))
             recurse(d - 1);
      }
}

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

void solve()
{
   recurse(n);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
