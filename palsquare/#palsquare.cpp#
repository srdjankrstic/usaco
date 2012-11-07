/*
ID: skrstic2
PROG: palsquare
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

ifstream FIN("palsquare.in");
ofstream FOUT("palsquare.out");
char _DIGITS[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int B;
vector<int> SOL;

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

void read()
{
   FIN >> B;
}

void write()
{
   for (int i = 0, len = SOL.size(); i < len; i++)
      FOUT << toBase(SOL[i], B) << " " << toBase(SOL[i] * SOL[i], B) << endl;
}

void solve()
{
   for (int i = 1; i < 300; i++)
      if (palindrome(toBase(i * i, B)))
         SOL.push_back(i);
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
