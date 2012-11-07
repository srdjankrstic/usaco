/*
ID: skrstic2
PROG: dualpal
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

ifstream FIN("dualpal.in");
ofstream FOUT("dualpal.out");
int N, S;
vector<int> SOL;
string _DIGITS = "0123456789";

bool palindrome(string str)
{
   int len = str.length();
   for (int i = 0; i < len; i++)
      if (str[i] != str[len - i - 1])
         return false;
   return true;
}

string reverse(string str)
{
   int len = str.length();
   char temp;
   for (int i = 0; i < len/2; i++)
   {
      temp = str[i];
      str[i] = str[len - i - 1];
      str[len - i - 1] = temp;
   }
   return str;
}

string toBase(int num, int b)
{
   string sol = "";
   while (num != 0)
   {
      sol.append(1, _DIGITS[num % b]);
      num /= b;
   }
   return reverse(sol);
}

int palcount(int num)
{
   int cnt = 0;
   for (int i = 2; i <= 10; i++)
      if (palindrome(toBase(num, i)))
         cnt++;
   return cnt;
}

void read()
{
   FIN >> N >> S;
}

void write()
{
   for (int i = 0, len = SOL.size(); i < len; i++)
      FOUT << SOL[i] << endl;
}

void solve()
{
   int curr = S + 1;
   while (N != 0)
      if (palcount(curr++) >= 2)
      {
         SOL.push_back(curr - 1);
         N--;
      }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
