/*
ID: skrstic2
PROG: beads
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

ifstream FIN("beads.in");
ofstream FOUT("beads.out");
int N, SOL;
string NECKLACE;

void read()
{
   FIN >> N >> NECKLACE;
}

void write()
{
   FOUT << SOL << endl;
}

void solve()
{
   int toleftbw[N], toleftrw[N], torightbw[N], torightrw[N];
   toleftbw[0] = toleftrw[0] = torightbw[N - 1] = torightrw[N - 1] = 0;

   for (int i = N - 1; i >= 0 && (NECKLACE[i] == 'w' || NECKLACE[i] == 'b'); i--, toleftbw[0]++);
   for (int i = N - 1; i >= 0 && (NECKLACE[i] == 'w' || NECKLACE[i] == 'r'); i--, toleftrw[0]++);
   for (int i = 0; i < N && (NECKLACE[i] == 'w' || NECKLACE[i] == 'b'); i++, torightbw[N - 1]++);
   for (int i = 0; i < N && (NECKLACE[i] == 'w' || NECKLACE[i] == 'r'); i++, torightrw[N - 1]++);

   // init toleft[0], toright[N-1]
   for (int i = 1; i < N; i++)
   {
      if (NECKLACE[i - 1] == 'w')
      {
         toleftbw[i] = min(N, toleftbw[i - 1] + 1);
         toleftrw[i] = min(N, toleftrw[i - 1] + 1);
      }
      else if (NECKLACE[i - 1] == 'b')
      {
         toleftbw[i] = min(N, toleftbw[i - 1] + 1);
         toleftrw[i] = 0;
      }
      else
      {
         toleftbw[i] = 0;
         toleftrw[i] = min(N, toleftrw[i - 1] + 1);
      }
   }
   for (int i = N - 2; i >= 0; i--)
   {
      if (NECKLACE[i + 1] == 'w')
      {
         torightbw[i] = min(N, torightbw[i + 1] + 1);
         torightrw[i] = min(N, torightrw[i + 1] + 1);
      }
      else if (NECKLACE[i + 1] == 'b')
      {
         torightbw[i] = min(N, torightbw[i + 1] + 1);
         torightrw[i] = 0;
      }
      else
      {
         torightbw[i] = 0;
         torightrw[i] = min(N, torightrw[i + 1] + 1);
      }
   }
   
   SOL = 0;
   for (int i = 0; i < N; i++)
   {
      int here = min(N, max(toleftbw[i], toleftrw[i]) + max(torightbw[(i + N - 1) % N], torightrw[(i + N - 1) % N]));
      if (here > SOL)
      {
         SOL = here;
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
