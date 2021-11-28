#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){

    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll cntb = 0, cntw = 0;
    char ch = s[0];

    for(ll i = 0; i < n; i++){
        if(s[i]==ch)
            continue;
        else{
            if(ch == 'B')
                cntb++;
            else
                cntw++;

            ch = s[i];
        }
    }

    if(ch == 'B')
        cntb++;
    else
        cntw++;

    cout << min(cntb, cntw) << "\n";

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