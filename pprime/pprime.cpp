/*
ID: skrstic2
PROG: pprime
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

ifstream fin("pprime.in");
ofstream fout("pprime.out");
int m, n;
vector<int> sol;

bool prime(int x)
{
   if (x <= 1)
      return false;
   int ul = ceil(sqrt(x));
   for (int i = 2; i <= ul; i++)
      if (x % i == 0)
         return false;
   return true;
}

void read()
{
   fin >> m >> n;
}

void write()
{
   sort(sol.begin(), sol.end());
   for (int i = 0, len = sol.size(); i < len; i++)
      fout << sol[i] << endl;
}

void solve()
{
   int a, b, c, d, num;
   for (a = 0; a < 10; a++)
      for (b = 0; b < 10; b++)
         for (c = 0; c < 10; c++)
            for (d = 0; d < 10; d++)
            {
               cout << d << endl;
               num = a + 10 * b + 100 * c + 1000 * d + 10000 * c + 100000 * b + 1000000 * a;
               if (num == 0)
                  continue;
               while (num % 10 == 0)
                  num /= 10;
               if (num >= m && num <= n && prime(num))
                  sol.push_back(num);

               num = a + 10 * b + 100 * c + 1000 * d + 10000 * d + 100000 * c + 1000000 * b + 10000000 * a;
               if (num == 0)
                  continue;
               while (num % 10 == 0)
                  num /= 10;
               if (num >= m && num <= n && prime(num))
                  sol.push_back(num);
            }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
