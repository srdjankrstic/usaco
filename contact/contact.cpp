/*
ID: skrstic2
PROG: contact
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
#include <sstream>

#define MAXN 50
#define MAXC 200010

using namespace std;

struct seq
{
   int freq;
   string data;
   int number;

   friend bool operator< (const seq &a, const seq &b)
   {
      if (a.freq > b.freq)
         return true;
      else if (a.freq < b.freq)
         return false;
      if (a.data.length() < b.data.length())
         return true;
      else if (a.data.length() > b.data.length())
         return false;
      return a.number < b.number;
   }
};

ifstream fin("contact.in");
ofstream fout("contact.out");
string input;
int a, b, n, len, t[MAXC];
vector<seq> seqs;
int ptwo[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384};

void init()
{
}

void read()
{
   fin >> a >> b >> n;
   ostringstream stream;
   string line;
   getline(fin, line);
   while (!fin.eof())
   {
      getline(fin, line);
      if (line.length() > 0)
         stream << line;
   }
   input = stream.str();
   len = input.length();
   b = min(b, len);
}

void write()
{
   int i = 0, h = seqs.size();
   while (n && i < h && seqs[i].freq > 0)
   {
      fout << seqs[i].freq << endl;
      fout << seqs[i].data;
      int howmany = 1;
      while (i + 1 < h && seqs[i].freq == seqs[i + 1].freq)
      {
         fout << (howmany == 0 ? "" : " ") << seqs[i + 1].data;
         howmany++;
         if (howmany == 6)
         {
            howmany = 0;
            fout << endl;
         }
         i++;
      }
      i++;
      if (howmany != 0)
         fout << endl;
      n--;
   }
}
   
string makestring(int digs, int num)
{
   string x;
   do
   {
      digs--;
      x.push_back('0' + (num & 1));
   } while (num >>= 1);

   while (digs-- > 0)
      x.push_back('0');

   reverse(x.begin(), x.end());
   return x;
}

int makenum(string s)
{
   int x = 0;
   for (int i = 0, len = s.length(); i < len; i++)
   {
      x <<= 1;
      x += s[i] - '0';
   }
   return x;
}

void precalc(string s, int slen)
{
   int pos = 2;
   int cnd = 0;
   t[0] = -1;
   t[1] = 0;

   while (pos < slen)
   {
      if (s[pos - 1] == s[cnd])
         t[pos++] = ++cnd;
      else if (cnd > 0)
         cnd = t[cnd];
      else
         t[pos++] = 0;
   }
}

int howmany(string s)
{
   int slen = s.length();
   precalc(s, slen);
   int m = 0, i = 0, matches = 0;

   while (m + i < len)
   {
      if (s[i] == input[m + i])
      {
         if (++i == slen)
         {
            matches++;
            i = 0;
            m++;
            continue;
         }
      }
      else
      {
         m += i - t[i];
         i = max(t[i], 0);
      }
   }

   return matches;
}

void solve()
{
   int freq[13][4096];
   memset(freq, 0, sizeof(freq[0][0]) * 13 * 4096);

   for (int digs = a; digs <= b; digs++)
   {
      int current = makenum(input.substr(0, digs));
      freq[digs][current]++;
      for (int s = digs; s < len; s++)
      {
         if (input[s - digs] == '1')
            current -= ptwo[digs - 1];
         current <<= 1;
         current += input[s] - '0';
         freq[digs][current]++;
      }
      for (int i = 0; i < ptwo[digs]; i++)
      {
         seq newpair;
         newpair.freq = freq[digs][i];
         newpair.number = i;
         newpair.data = makestring(digs, i);
         seqs.push_back(newpair);
      }
   }

   // for (int digs = a; digs <= b; digs++)
   // {
   //    for (int s = 0; s < ptwo[digs]; s++)
   //    {
   //       string sstr = makestring(digs, s);
   //       int freq = howmany(sstr);
   //       seq newpair;
   //       newpair.freq = freq;
   //       newpair.data = sstr;
   //       newpair.number = s;
   //       seqs.push_back(newpair);
   //    }
   // }

   sort(seqs.begin(), seqs.end());
}

int main()
{
   init();
   read();
   solve();
   write();
   return 0;
}
