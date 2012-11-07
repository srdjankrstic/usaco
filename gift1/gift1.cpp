/*
ID: skrstic2
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
   ifstream fin("gift1.in");
   ofstream fout("gift1.out");

   map<string, int> amounts;
   vector<string> names;
   int n;
   string name;

   fin >> n;
   for (int i = 0; i < n; i++)
   {
      fin >> name;
      names.push_back(name);
      amounts[name] = 0;
   }
   while (!fin.eof())
   {
      string giver, givee;
      int c, p, each;
      fin >> giver;
      fin >> c >> p;
      if (p != 0)
      {
         amounts[giver] -= c;
         amounts[giver] += c % p;
         each = c / p;
         for (int i = 0; i < p; i++)
         {
            fin >> givee;
            amounts[givee] += each;
         }
      }
   }
   for (int i = 0, len = names.size(); i < len; i++)
   {
      fout << names[i] << " " << amounts[names[i]] << endl;
   }
   return 0;
}
