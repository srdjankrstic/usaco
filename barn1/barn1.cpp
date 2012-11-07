/*
ID: skrstic2
PROG: barn1
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

ifstream FIN("barn1.in");
ofstream FOUT("barn1.out");
int M, S, C, SOL;
vector<int> COWS;

void read()
{
   int c;
   FIN >> M >> S >> C;
   for (int i = 0; i < C; i++)
   {
      FIN >> c;
      COWS.push_back(c);
   }
}

void write()
{
   FOUT << SOL << endl;
}

void solve()
{
   sort(COWS.begin(), COWS.end());
   int span = COWS[C - 1] - COWS[0] + 1;
   for (int i = 0; i < C - 1; i++)
      COWS[i] = COWS[i + 1] - COWS[i] - 1;
   sort(COWS.begin(), COWS.end() - 1);
   reverse(COWS.begin(), COWS.end() - 1);
   int i = 0;
   SOL = 0;
   M--;
   while (M != 0 && i != C - 1)
   {
      SOL += COWS[i];
      M--; i++;
   }
   SOL = span - SOL;
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
