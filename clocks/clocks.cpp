/*
  ID: skrstic2
  PROG: clocks
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

ifstream FIN("clocks.in");
ofstream FOUT("clocks.out");
int CONFIG, S1, S2, S3, S4, S5, S6, S7, S8, S9 = 2000000000;

void doA()
{
   int d = (CONFIG >> 16) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 16);
   else
      CONFIG ^= (3 << 16);
}

void doB()
{
   int d = (CONFIG >> 14) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 14);
   else
      CONFIG ^= (3 << 14);
}

void doC()
{
   int d = (CONFIG >> 12) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 12);
   else
      CONFIG ^= (3 << 12);
}

void doD()
{
   int d = (CONFIG >> 10) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 10);
   else
      CONFIG ^= (3 << 10);
}

void doE()
{
   int d = (CONFIG >> 8) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 8);
   else
      CONFIG ^= (3 << 8);
}

void doF()
{
   int d = (CONFIG >> 6) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 6);
   else
      CONFIG ^= (3 << 6);
}

void doG()
{
   int d = (CONFIG >> 4) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 4);
   else
      CONFIG ^= (3 << 4);
}

void doH()
{
   int d = (CONFIG >> 2) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 2);
   else
      CONFIG ^= (3 << 2);
}

void doI()
{
   int d = (CONFIG >> 0) & 3;
   if (d == 0 || d == 2)
      CONFIG ^= (1 << 0);
   else
      CONFIG ^= (3 << 0);
}

void makemove(int move)
{
   switch (move)
   {
      case 1:
         doA(); doB(); doD(); doE(); break;
      case 2:
         doA(); doB(); doC(); break;
      case 3:
         doB(); doC(); doE(); doF(); break;
      case 4:
         doA(); doD(); doG(); break;
      case 5:
         doB(); doD(); doE(); doF(); doH(); break;
      case 6:
         doC(); doF(); doI(); break;
      case 7:
         doD(); doE(); doG(); doH(); break;
      case 8:
         doG(); doH(); doI(); break;
      case 9:
         doE(); doF(); doH(); doI(); break;
      default:
         break;
   }
}

void read()
{
   int t;
   CONFIG = 0;
   for (int i = 0; i < 9; i++)
   {
      FIN >> t;
      t = (t / 3) % 4;
      CONFIG = 4 * CONFIG + t;
   }
}

void write()
{
   if (S9 == 2000000000)
      return;

   vector<int> sol;
   for (int i = 0; i < S1; i++)
      sol.push_back(1);
   for (int i = 0; i < S2; i++)
      sol.push_back(2);
   for (int i = 0; i < S3; i++)
      sol.push_back(3);
   for (int i = 0; i < S4; i++)
      sol.push_back(4);
   for (int i = 0; i < S5; i++)
      sol.push_back(5);
   for (int i = 0; i < S6; i++)
      sol.push_back(6);
   for (int i = 0; i < S7; i++)
      sol.push_back(7);
   for (int i = 0; i < S8; i++)
      sol.push_back(8);
   for (int i = 0; i < S9; i++)
      sol.push_back(9);

   for (int i = 0, len = sol.size() - 1; i < len; i++)
      FOUT << sol[i] << " ";
   FOUT << sol[sol.size() - 1] << endl;
}

void solve()
{
   int m1, m2, m3, m4, m5, m6, m7, m8, m9;
   for (m1 = 0; m1 < 4; m1++)
   {
      for (m2 = 0; m2 < 4; m2++)
      {
         for (m3 = 0; m3 < 4; m3++)
         {
            for (m4 = 0; m4 < 4; m4++)
            {
               for (m5 = 0; m5 < 4; m5++)
               {
                  for (m6 = 0; m6 < 4; m6++)
                  {
                     for (m7 = 0; m7 < 4; m7++)
                     {
                        for (m8 = 0; m8 < 4; m8++)
                        {
                           for (m9 = 0; m9 < 4; m9++)
                           {
                              if (CONFIG == 0 && m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 < S1 + S2 + S3 + S4 + S5 + S6 + S7 + S8 + S9)
                              {
                                 S1 = m1; S2 = m2; S3 = m3; S4 = m4; S5 = m5; S6 = m6; S7 = m7; S8 = m8; S9 = m9;
                              }
                              makemove(9);
                           }
                           makemove(8);
                        }
                        makemove(7);
                     }
                     makemove(6);
                  }
                  makemove(5);
               }
               makemove(4);
            }
            makemove(3);
         }
         makemove(2);
      }
      makemove(1);
   }
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
