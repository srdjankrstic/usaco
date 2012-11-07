/*
ID: skrstic2
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

struct milk
{
   int p;
   int amount;
};

bool compare(milk m1, milk m2)
{
   return (m1.p < m2.p);
}

ifstream FIN("milk.in");
ofstream FOUT("milk.out");
int N, M, SOL;
vector<milk> FARMERS;

void read()
{
   int a, p;
   FIN >> N >> M;
   for (int i = 0; i < M; i++)
   {
      FIN >> p >> a;
      milk s = {p, a};
      FARMERS.push_back(s);
   }
}

void write()
{
   FOUT << SOL << endl;
}

void solve()
{
   sort(FARMERS.begin(), FARMERS.end(), compare);
   int i = 0;
   SOL = 0;
   while (N != 0)
   {
      int diff = min(N, FARMERS[i].amount);
      SOL += diff * FARMERS[i].p;
      N -= diff;
      i++;
   }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
