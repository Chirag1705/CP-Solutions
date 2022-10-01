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
