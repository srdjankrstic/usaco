/*
ID: skrstic2
PROG: calfflac
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

ifstream FIN("calfflac.in");
ofstream FOUT("calfflac.out");
string INPUT;
int SOLLEN, SOLBEGIN, SOLEND;

bool same(char a, char b)
{
   if (a >= 'A' && a <= 'Z')
      a = a - 'A' + 'a';
   if (b >= 'A' && b <= 'Z')
      b = b - 'A' + 'a';
   return a == b;
}

void read()
{
   INPUT = "";
   string line;
   while (getline(FIN, line))
      INPUT.append(line + "\n");
}

void write()
{
   FOUT << SOLLEN << endl;
   FOUT << INPUT.substr(SOLBEGIN, SOLEND - SOLBEGIN + 1) << endl;
}

void solve()
{
   int curlen, left, right, lastleft, lastright, len = INPUT.length();
   SOLLEN = 0;

   for (int mid = 0; mid < len; mid++)
   {
      // even sized, center at just before mid
      left = mid - 1; right = mid; curlen = 0; lastleft = 0; lastright = 0;
      while (left >= 0 && right < len)
      {
         while (!isalpha(INPUT[left]) && left >= 0)
            left--;
         while(!isalpha(INPUT[right]) && right < len)
            right++;
         if (left >= 0 && right < len && same(INPUT[left], INPUT[right]))
         {
            lastleft = left;
            lastright = right;
            left--;
            right++;
            curlen++;
         }
         else
            break;            
      }
      if (2 * curlen > SOLLEN)
      {
         SOLLEN = 2 * curlen;
         SOLBEGIN = lastleft;
         SOLEND = lastright;
      }

      if (!isalpha(INPUT[mid]))
         continue;
      // odd sized, center at mid
      left = mid - 1; right = mid + 1; curlen = 0; lastleft = 0; lastright = 0;
      while (left >= 0 && right < len)
      {
         while (!isalpha(INPUT[left]) && left >= 0)
            left--;
         while(!isalpha(INPUT[right]) && right < len)
            right++;
         if (left >= 0 && right < len && same(INPUT[left], INPUT[right]))
         {
            lastleft = left;
            lastright = right;
            left--;
            right++;
            curlen++;
         }
         else
            break;    
      }
      if (2 * curlen + 1 > SOLLEN)
      {
         SOLLEN = 2 * curlen + 1;
         SOLBEGIN = lastleft;
         SOLEND = lastright;
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
