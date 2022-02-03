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

/* ll ma = 1005;
vt<ll>dis(2*ma, INT_MAX);
 
void cost(){
    ll x = 0, y = 0;
 
    dis[1] = 0;
 
    for(ll i = 1; i <= ma; i++){
        for(ll j = 1; j <= i; j++){
            ll form = i + (i/j);
 
            dis[form] = min(dis[form], dis[i]+1);
        }
    }
 
} */

// or

vt<ll>dis(1001, INT_MAX);

void cost(){

    dis[1] = 0;

    for(ll i = 1; i <= 1000; i++){
        for(ll j = i; j >= 1; j--){
            ll form = i + (i/j);

            if(form > 1000)
                break;

            dis[form] = min(dis[form], dis[i]+1);
        }
    }

}


void solve(){
      ll n, k;
      cin >> n >> k;

      vt<ll>b(n), c(n);

      for(ll i = 0; i < n; i++)
        cin >> b[i];

      for(ll i = 0; i < n; i++)
            cin >> c[i];

      cost();

      vt<ll>v(n);

      for(ll i = 0; i < n; i++){
          v[i] = dis[b[i]];
      }
    
      k = min(k, *max_element(v.begin(), v.end())*n);

      vt<vt<ll>>dp(n, vt<ll>(k+1));

      dp[0][0] = 0;
 
      if(v[0] <= k){
          dp[0][v[0]] = c[0];
      }

      for(ll i = 1; i < n; i++){
          for(ll j = 0; j < k+1; j++){
              dp[i][j] = dp[i-1][j];

              if(j >= v[i]){
                  dp[i][j] = max(dp[i][j], c[i] + dp[i-1][j - v[i]]);
              }
          }
      }
      
      ll ans = 0;

      for(ll j = 0; j < k+1; j++){
          ans = max(ans, dp[n-1][j]);
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