#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7
#define mod 1e9 + 7


ll mod_mul(ll a, ll b, ll m = mod){
    a = a%m;
    b = b%m;

    return (((a * b) % m) + m) % m;
}

ll modulo(ll a, ll b, ll n = mod){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

void solve(){
        ll n, h;
        cin >> n >> h;

        vt<ll>arr(n);

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll l = 0, r = 1e18+10;
        ll mid;

        while(r > l+1){
            mid = (r+l)/2;

            bool ok = false;

            ll hit = 0;

            for(ll i = 1; i < n; i++){
                hit += min(arr[i] - arr[i-1], mid);
            }
            hit += mid;

            if(hit >= h)
                ok = true;

            if(ok)
                r = mid;
            else 
                l = mid;
        }

        cout << r << "\n";
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