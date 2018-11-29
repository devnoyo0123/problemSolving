#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <sstream>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <time.h>
#include <random>
#include <stdlib.h>

#define DEBUG

using namespace std;

int calc1(int *parms) {
   static int a, b, op;
   a = parms[0]; op = parms[1]; b = parms[2];

   switch (op) {
   case '+':
      return a + b;
   case '-':
      return a - b;
   case '*':
      return a * b;
   default:
      break;
   }
   return 0;
}

int calc2(string &str, int start, int end) {
   int parms[3];
   int idx = 0;

   for (int i = start; i <= end; i++) {
      if (str[i] == 0) continue;

      switch (str[i]) {
      case '(':
      {
         int tmp_start, tmp_end,tmp_idx;
         tmp_start = i + 1;
         tmp_idx = tmp_start;
         while (str[tmp_idx] != ')') { tmp_idx++; }
         tmp_end = tmp_idx - 1;

         parms[idx++] = calc2(str, tmp_start, tmp_end);
         i = tmp_idx;
         break;
      }
      case '+':
      case '-':
      case '*':
         parms[idx++] = str[i]; break;
      case '0':       case '1':      case '2':      case '3':
      case '4':      case '5':      case '6':      case '7':
      case '8':      case '9':
         parms[idx++] = str[i] - '0'; break;
      }
      
      if (idx == 3) {
         idx = 1;
         parms[0] = calc1(parms);
      }
   }
   return parms[0];
}

void print(string &str,int &ret) {
   for (auto &iter : str) {
      if (iter == 0) continue;
      cout << iter;
   }
   cout << " = " << ret << endl;
}

int MAX;
void solve(string &str, int idx) {
   if (idx >= str.size()) {
      int ret = calc2(str, 0, str.size() - 1);
      MAX = max(ret, MAX);
#ifdef DEBUG
      print(str,ret);
#endif
      return;
   }

   str[idx] = '(';
   for (int i = idx + 6; i < str.size(); i += 4) {
      str[i] = ')';
      solve(str, i+2);
      str[i] = 0;
   }
   str[idx] = 0;

   solve(str, idx + 4);
}



int main(void) {
   std::ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   freopen("input.txt", "r", stdin);

   int T;
   cin >> T;

   for (int tc = 1; tc <= T; tc++) {
      int N;
      cin >> N;
      string str;
      str.resize(2 * N + 1,0);
      for (int i = 1; i < str.size(); i += 2) {
         cin >> str[i];
      }
      MAX = -10000000000;
      solve(str, 0);
      cout << "#" << tc << " " << MAX << endl;
   }

   return 0;
}