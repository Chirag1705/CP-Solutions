#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7
// #define mod 1e9 + 7
const ll mod = 1e18 + 7;
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
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;

        ll ans = 1e19;
        ll diff = 0;


        if(b - n >= y)
            ans = min(ans, (b-n)*a);
        else{
            diff = n;
            diff -= (b-y);
            if(a - diff >= x)
                ans = min(ans, (b - (b-y))*(a-diff));
            else
                ans = min(ans, (b - (b-y))*(a - (a-x)));
        }

        if(a - n >= x)
            ans = min(ans, (a - n)*b);
        else{
            diff = n;
            diff -= (a-x);
            if(b - diff >= y)
                ans = min(ans, (a - (a-x))*(b-diff));
            else
                ans = min(ans, (a - (a-x))*(b - (b-y)));
        }
        
        cout << ans << "\n";

}

/* Another Approach ->
 int a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		long long ans = 1e18;
		for (int i = 0; i < 2; ++i) {
			int da = min(n, a - x);
			int db = min(n - da, b - y);
			ans = min(ans, (a - da) * 1ll * (b - db));
			swap(a, b);
			swap(x, y);
		}
		cout << ans << endl; */

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
