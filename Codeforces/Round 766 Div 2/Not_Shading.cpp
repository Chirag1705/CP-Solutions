#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7
// #define mod 1e9 + 7
const ll mod = 1e9 + 7;

ll inv(ll i) {
    if (i == 1) 
    return 1; 
    
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
    }

ll pwr(ll a, ll b) {
    a %= mod; 
    ll res = 1; 

    while (b > 0) {
        if (b & 1) 
            res = res * a % mod; 
        a = a * a % mod; 
        b >>= 1;
    } 
        return res;
}

ll mod_add(ll a, ll b) {
    a = a % mod; 
    b = b % mod; 
    
    return (((a + b) % mod) + mod) % mod;
}


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
            ll n, m, r, c;

            cin >> n >> m;
            cin >> r >> c;

            r--, c--;

            char arr[n][m];
            bool found = false;
            ll cnt = 0;

            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < m; j++){
                    cin >> arr[i][j];
                    if(arr[i][j] == 'B'){
                        found = true;
                        cnt++;
                    }
                }
            }

            if(cnt == 0){
                    cout << "-1" << "\n";
                    return;
            }

            if(arr[r][c] == 'B'){
                cout << "0" << "\n";
                return;
            }

            bool found2 = false;

            for(ll i = 0; i < n; i++){
                if(arr[i][c] == 'B'){
                    found2 = true;
                }
            }

            for(ll j = 0; j < m; j++){
                if(arr[r][j] == 'B'){
                    found2 = true;
                }
            }

            if(found2){
                cout << "1" << "\n";
            }
            else
            cout << "2" << "\n";

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
