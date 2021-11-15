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

        ll ans = 1e9;

        for(ll i = 0; i < n; i++){
            vt<ll>f(3);
            f[s[i] - 'a']++;

            for(ll j = i+1; j < min(n, i+7); j++){
                f[s[j] - 'a']++;

                if(f[0] > f[1] and f[0] > f[2])
                    ans = min(ans, j-i+1);
            }
        }

        if(ans == 1e9)
            cout << "-1" << endl;
        else
            cout << ans << endl;
        
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