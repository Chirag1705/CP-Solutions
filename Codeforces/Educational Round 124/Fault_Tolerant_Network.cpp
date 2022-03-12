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
#define set_bits __builtin_popcountll


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

        ll n;
        cin>>n;

        vt<ll>a(n), b(n);

        for(ll i=0;i<n;i++)
            cin >> a[i];

        for(ll i=0;i<n;i++)
            cin>>b[i];

    ll m1=INT_MAX,m2=INT_MAX,m3=INT_MAX,m4=INT_MAX;

    for(ll i=1;i<n;i++)
    {
        m1=min(abs(a[0]-b[i]),m1);
        m2=min(abs(b[0]-a[i]),m2);
    }

    for(ll i=n-2;i>=0;i--)
    {
        m3=min(abs(a[n-1]-b[i]),m3);
        m4=min(abs(b[n-1]-a[i]),m4);
    }
    ll ans = INT_MAX;

    ans = min(ans, abs(a[0]-b[0]) + abs(a[n-1]-b[n-1]));
    ans = min(ans, abs(a[0]-b[n-1]) + abs(a[n-1]-b[0]));
    ans = min(ans, abs(a[0]-b[0]) + m4 + m3);
    ans = min(ans, abs(a[n-1]-b[n-1]) + m1 + m2);
    ans = min(ans, abs(a[0]-b[n-1]) + m2 + m3);
    ans = min(ans, abs(a[n-1]-b[0]) + m1 + m4);
    ans = min(ans, m1 + m2 + m3 + m4);
    
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