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
        ll n;
        char c;

        cin >> n >> c;

        string s;
        cin >> s;

        ll count = 0;

    for(ll i = 0; i < n; i++){
        if(s[i]!=c){
            count++;
        }
    }

    if(count == 0){
        cout << "0" << "\n";
        return;
    }

        for(ll i = 2; i <= n; i++){
            bool ok = true;

            for(ll j = i; j <= n; j+=i){
                if(s[j-1]!=c){
                    ok = false;
                    break;
                }
            }

            if(ok){
                cout << "1" << "\n";
                cout << i << "\n";
                return;
            }
        }

        cout << "2" << "\n" << n << " " << n-1 << "\n";

        
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