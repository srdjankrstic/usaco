/*
ID: skrstic2
PROG: prefix
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
#define MAXP 200001

using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");
string target, tokens[MAXN];
int n, sol;
bool possible[MAXP];

void init()
{
   target = "";
   n = 0;
   for (int i = 0; i < MAXN; i++)
      possible[i] = false;
   sol = 0;
}

void read()
{
   string s;
   while (true)
   {
      fin >> s;
      if (s.compare(".") == 0)
         break;
      tokens[n++] = s;
   }
   while (!fin.eof())
   {
      fin >> s;
      if (!fin.eof())
         target = target.append(s);
   }
}

void write()
{
   fout << sol << endl;
}

void solve()
{
//   for (int i = 0; i < n; i++)
//      fout << tokens[i] << endl;
//   fout << target << endl;
   possible[0] = true;
   for (int i = 1, len = target.length(); i <= len; i++)
      for (int j = 0; j < n; j++)
      {
         int l = tokens[j].length();
         if (i >= l && possible[i - l] && tokens[j].compare(target.substr(i - l, l)) == 0)
         {
            possible[i] = true;
            if (i > sol)
               sol = i;
            break;
         }
      }
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
