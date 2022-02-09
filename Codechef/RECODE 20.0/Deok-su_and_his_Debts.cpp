#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        string s;
        cin >> s;

        ll ans = 1e9;
        ll count = 0;
        ll i = 0;

        while(i < s.size()-3){

          if(s[i]=='c' and s[i+1]=='c' and s[i+2] == '+' and s[i+3] == '+'){
                            count++;
                            s.erase(s.begin()+(i+2));
                            i = 0;
                }
          


        if(s[i]=='+' and s[i+1]=='c' and s[i+2] == '+' and s[i+3] == '+'){
                            count++;
                            s.erase(s.begin()+(i+1));
                            i=0;
                }
                i++;
        }
}

int main()
{
    FASTIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
     solve();
    }
}