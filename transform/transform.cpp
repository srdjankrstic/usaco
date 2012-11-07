/*
  ID: skrstic2
  PROG: transform
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

#define _MAXN 11

class board
{
private:
   int size;
   char layout[_MAXN][_MAXN];
public:
   board(int size, string whole)
   {
      this->size = size;
      for (int i = 0; i < size; i++)
         for (int j = 0; j < size; j++)
            layout[i][j] = whole[i * size + j];
   }

   board(int size, char layout[_MAXN][_MAXN])
   {
      this->size = size;
      for (int i = 0; i < size; i++)
         for (int j = 0; j < size; j++)
            this->layout[i][j] = layout[i][j];
   }

   board* rot90()
   {
      char newlayout[_MAXN][_MAXN];
      for (int i = 0; i < size; i++)
         for (int j = 0; j < size; j++)
            newlayout[j][size - i - 1] = layout[i][j];
      return new board(size, newlayout);
   }
   
   board* rot180()
   {
      return this->rot90()->rot90();
   }
   
   board* rot270()
   {
      return this->rot180()->rot90();
   }
   
   board* reflect()
   {
      char newlayout[_MAXN][_MAXN];
      for (int i = 0; i < size; i++)
         for (int j = 0; j < size; j++)
            newlayout[i][size - j - 1] = layout[i][j];
      return new board(size, newlayout);
   }
   
   bool operator== (const board &that) const
   {
      if (this->size != that.size)
         return false;
      for (int i = 0; i < size; i++)
         for (int j = 0; j < size; j++)
            if (this->layout[i][j] != that.layout[i][j])
               return false;
      return true;
   }   
};

ifstream FIN("transform.in");
ofstream FOUT("transform.out");
int N, SOL;
board *START, *END;

void read()
{
   FIN >> N;
   string whole = "", line;
   for (int i = 0; i < N; i++)
   {
      FIN >> line;
      whole = whole.append(line);
   }
   START = new board(N, whole);
   string whole2 = "";
   for (int i = 0; i < N; i++)
   {
      FIN >> line;
      whole2 = whole2.append(line);
   }
   END = new board(N, whole2);
}

void write()
{
   FOUT << SOL << endl;
}

void solve()
{
   if (*START->rot90() == *END)
      SOL = 1;
   else if (*START->rot180() == *END)
      SOL = 2;
   else if (*START->rot270() == *END)
      SOL = 3;
   else if (*START->reflect() == *END)
      SOL = 4;
   else if (*START->reflect()->rot90() == *END)
      SOL = 5;
   else if (*START->reflect()->rot180() == *END)
      SOL = 5;
   else if (*START->reflect()->rot270() == *END)
      SOL = 5;
   else if (*START == *END)
      SOL = 6;
   else
      SOL = 7;

   delete START;
   delete END;
}

int main()
{
   read();
   solve();
   write();
   return 0;
}
