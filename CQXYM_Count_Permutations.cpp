#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

#define mod 1000000007

void solve(){
        ll n;
        cin >> n;

        ll f[100001];

        f[1] = 1;

        for(register ll i = 2; i < 100001; i++){
            f[i] = ((i << 1) - 1) * f[i-1]%mod * (i << 1)%mod;
        }

        cout << f[n] << endl;
        
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