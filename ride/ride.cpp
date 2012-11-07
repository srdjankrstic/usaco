/*
ID: skrstic2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int hash(string line)
{
   short hash = 1;
   for (int i = 0, len = line.length(); i != len; ++i)
   {
      hash *= (line[i] - 'A' + 1);
      hash %= 47;
   }
   return hash;
}

int main()
{
   ifstream fin("ride.in");
   ofstream fout("ride.out");
   string line1, line2;
   fin >> line1 >> line2;
   fout << (hash(line1) == hash(line2) ? "GO" : "STAY") << endl;
}
