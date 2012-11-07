/*
ID: skrstic2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int NEXT_LEAP[12] = {3, 1, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
int NEXT_NOLEAP[12] = {3, 0, 3, 2, 3, 2, 3, 3, 2, 3, 2, 3};
int N;

bool leap(int year)
{
   if (year % 100 == 0)
   {
      return (year % 400 == 0);
   }
   return (year % 4 == 0);
}

int thirteenth(int first)
{
   return (first + 5) % 7;
}

int main()
{
   ifstream fin("friday.in");
   ofstream fout("friday.out");

   fin >> N;

   int count[7] = {0};
   int first = 2;
   for (int year = 1900; year < 1900 + N; year++)
   {
      int *offsets = (leap(year) ? NEXT_LEAP : NEXT_NOLEAP);

      for (int i = 0; i < 12; i++)
      {
         count[thirteenth(first)]++;
         first += offsets[i];
         first %= 7;
      }
   }

   for (int i = 0; i < 6; i++)
   {
      fout << count[i] << " ";
   }
   fout << count[6] << endl;

   return 0;
}
