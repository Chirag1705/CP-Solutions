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

void solve() {
	ll n, m;
	cin >> n >> m;

	vt<ll>a(n);

	for (ll i = 0; i < n; i++)
		cin >> a[i];

	ll k;
	cin >> k;

	vt<ll>b(k);

	for (ll i = 0; i < k; i++)
		cin >> b[i];

	vt<pair<ll, ll>>a1, b1;

	ll ele = a[0], cnt = 1;
	while (ele % m == 0) {
		ele = ele / m;
		cnt *= m;
	}
	a1.pb({ele, cnt});
	for (ll i = 1; i < n; i++) {
		ll ele = a[i], cnt = 1;
		while (ele % m == 0) {
			ele = ele / m;
			cnt *= m;
		}
		if (ele == a1.back().ff)
			a1.back().ss += cnt;
		else
			a1.pb({ele, cnt});

	}

	ele = b[0], cnt = 1;
	while (ele % m == 0) {
		ele = ele / m;
		cnt *= m;
	}
	b1.pb({ele, cnt});
	for (ll i = 1; i < k; i++) {
		ll ele = b[i], cnt = 1;
		while (ele % m == 0) {
			ele = ele / m;
			cnt *= m;
		}
		if (ele == b1.back().ff)
			b1.back().ss += cnt;
		else
			b1.pb({ele, cnt});
	}

	if (a1 == b1)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
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
