#include <bits/stdc++.h>
using namespace std;
#define N 10000001
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     vector<int> p(N);
     for (int i = 2; i < N; i++)
     {
          p[i] = 1 - p[i];
          if (p[i])
          {
               for (int j = 2 * i; j < N; j += i)
               {
                    p[j] = 1;
               }
          }
          p[i] += p[i - 1];
     }
     int t;
     cin >> t;
     while (t--)
     {
          int x, y;
          cin >> x >> y;
          cout << y - x - p[y] + p[x + 1] << "\n";
     }
     return 0;
}