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

ll mod_sub(ll a, ll b, ll m = mod){
    a = a%m;
    b = b%m;

    return((a - b) + m)%m;
}

// another binpow method
ll pw(ll a, ll b, ll m){
    if(b == 0)
        return 1;
    
    if(b%2==0){
        ll t = pw(a, b/2, m);
        return (1LL * t * t % m);
    }
    else{
        ll t = pw(a, (b-1)/2, m);
        t = (1LL * t * t)%m;
        return (1LL * a * t % m);
    }
}

ll mod_div(ll a, ll b, ll m = mod){
    a = a%m;

    ll inv_b = pw(b, m-2, m);
    // inverse of b = b^m-2%m, only for prime m

    ll res = a*inv_b % m;

    return res;
}

// binary exponentiation
// binpow
// O(log(b))
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
// binpow again
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



void solve(){
        ll n, m;
        cin >> n;
        vt<ll>v1(n);

        for(ll i = 0; i < n; i++){
            cin >> v1[i];
        }

        cin >> m;
        vt<ll>v2(m);

        for(ll i = 0; i < m; i++){
            cin >> v2[i];
        }

//         ll sum = 0;

//         vt<ll>par1, par2;
//         par1.pb(0);
//         par2.pb(0);

//         for(ll i = 0; i < n; i++){
//             sum += v1[i];
//             par1.pb(sum);
//         }
// // can use partial_function instead of calculating prefix sum in this manner
//         sum = 0;

//         for(ll i = 0; i < m; i++){
//             sum += v2[i];
//             par2.pb(sum);
//         }

//         cout << *max_element(par1.begin(), par1.end()) + *max_element(par2.begin(), par2.end()) << "\n";

// --> Another Dp Approach ->

        vt<vt<ll>>dp(n+1, vt<ll>(m+1, 0));

        ll ans = 0;
        dp[0][0] = 0;

        for(ll i = 0; i < n+1; i++){
            for(ll j = 0; j < m+1; j++){

                if(i < n)
                    dp[i+1][j] = dp[i][j] + v1[i];
                

                if(j < m)
                    dp[i][j+1] = dp[i][j] + v2[j];

                ans = max(ans, dp[i][j]);
            }   
        }

        cout << ans << "\n";


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
