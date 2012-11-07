/*
ID: skrstic2
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

ifstream FIN("namenum.in");
ofstream FOUT("namenum.out");
vector<string> DICT, SOL;
string INPUT;

int convert(char c)
{
   if (c < 'Q')
      return (c - 'A') / 3 + 2;
   else
      return (c - 'A' - 1) / 3 + 2;
}

bool fits(string word, string nums)
{
   if (word.length() != nums.length())
      return false;
   for (int i = 0, len = word.length(); i < len; i++)
      if (nums[i] - '0' != convert(word[i]))
         return false;
   return true;
}

void read()
{
   ifstream fdict("dict.txt");
   string line;
   while (fdict >> line)
      DICT.push_back(line);
   FIN >> INPUT;
}

void write()
{
   int length = SOL.size();
   if (length == 0)
      FOUT << "NONE" << endl;
   else
      for (int i = 0; i < length; i++)
         FOUT << SOL[i] << endl;
}

void solve()
{
   for (int i = 0, len = DICT.size(); i < len; i++)
      if (fits(DICT[i], INPUT))
         SOL.push_back(DICT[i]);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
