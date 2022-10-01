#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size())
#define ff first
#define ss second
// #define mod 1e9 + 7
const ll mod = 1e9 + 7;
#define set_bits __builtin_popcountll

// binpow
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

ll inv(ll i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }

ll mod_add(ll a, ll b) { a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll mod_mul(ll a, ll b, ll m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }

ll mod_sub(ll a, ll b, ll m = mod) { a = a % m; b = b % m; return ((a - b) + m) % m; }

ll mod_div(ll a, ll b, ll m = mod) { a = a % m; ll inv_b = expo(b, m - 2, m); ll res = a * inv_b % m; return res; }

ll power(ll x, ll y, ll p)
{
	unsigned ll res = 1;
	x = x % p;

	while (y > 0)
	{

		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modInverse(ll n, ll p) {
	return power(n, p - 2, p);
}

ll nCrModPFermat(ll n, ll r, ll mod) {
	if (n < r)
		return 0;

	if (r == 0)
		return 1;

	ll fact[n + 1];

	fact[0] = 1;

	for (ll i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}

	return (fact[n] * modInverse(fact[r], mod) % mod * modInverse(fact[n - r], mod) % mod) % mod;
}

void solve() {
	ll n;
	cin >> n;

	ll mod = 998244353;

	vt<pair<ll, ll>>vec(65);

	vec[2].ff = 1;
	vec[2].ss = 0;

	for (ll i = 4; i <= 64; i += 2) {
		vec[i].ff = (nCrModPFermat(i - 1, i / 2, mod) + vec[i - 2].ss) % mod;
		vec[i].ss = (nCrModPFermat(i, i / 2, mod) - vec[i].ff - 1 + mod) % mod;
	}

	cout << vec[n].ff << " " << vec[n].ss << " " << "1" << "\n";
}

int main()
{
	FASTIO;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}

--------------------------------------------------------------------------------------------------------
	
	
// Author : Epsilon573
// If it works, don't touch it.

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

const ll mod  = 998244353;
const ld eps  = 1e-9 ;
const ll maxn = 105;
const ll inf  = 5e18 ;
const ll minf = -inf ;

#define mp make_pair
#define pb push_back
#define endl "\n"

ll fac[maxn],invfact[maxn];

ll power(ll x, ll y) 
{ 
    ll res = 1; 
    x = x % mod; 
  
    while (y > 0) { 
        if (y & 1) 
            res = (res * x) % mod; 
        y = y >> 1; 
        x = (x * x) % mod; 
    } 

    return res; 
} 

ll modInverse(ll n) 
{ 
    return power(n, mod - 2); 
} 
  
void comp()
{
    fac[0] = 1, invfact[0] = 1; 
    
    for (ll i = 1; i < maxn; i++){ 
        fac[i] = (fac[i - 1] * i) % mod;
        invfact[i] = modInverse(fac[i]);
    } 
}

ll NCR(ll n, ll r, ll p=mod) 
{
    if(r < 0 || n < 0)
        assert(false);

    if( n < r ) return 0;

    if (r == 0 || r == n) 
        return 1; 
    
    return ( fac[n] * invfact[r]  % mod) * invfact[n - r] % mod;  
}

void recurse(ll n, vector<vector<ll>>& dp){
    if(n==2)
        return;

    recurse(n-2,dp);

    dp[n][0] = (NCR(n-1,n/2) + dp[n-2][1]) % mod;
    dp[n][1] = (NCR(n-2,n/2) + dp[n-2][0]) % mod;
    dp[n][2] = (dp[n-2][2]) % mod;    


}

bool solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1,vector<ll> (3,-1));

    // base cases
    // alex wins
    dp[2][0] = 1;
    // boris wins
    dp[2][1] = 0;
    // draw
    dp[2][2] = 1;

    recurse(n,dp);
    cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << endl;

    return true;    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifdef EPSILON
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif

    comp();

    ll t=1;
    cin >> t;

    while(t--)
    {
        if(solve())
        {
            // cout << "YES" << endl;
        }
        else
        {
            // cout << "NO" << endl;
        }
    }

    return 0;
} 
