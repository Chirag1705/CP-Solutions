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

ll inf = 1e18;

void solve() {
	ll n;
	cin >> n;

	vt<pair<ll, ll>>vec(n);

	for (ll i = 0; i < n; i++) {
		cin >> vec[i].ff >> vec[i].ss;

		if (vec[i].ss > vec[i].ff)
			swap(vec[i].ff, vec[i].ss);
	}

	if (n == 1) {
		cout << 2 * vec[0].ff + 2 * vec[0].ss << "\n";
		return;
	}

	sort(vec.begin(), vec.end());

	auto tmp = vec[1];

	for (ll i = 1; i < n - 1; i++) {
		vec[i] = vec[i + 1];
	}

	vec[n - 1] = tmp;

	// for (ll i = 0; i < n; i++)
	// 	cout << vec[i].ff << " " << vec[i].ss << "\n";

	ll sum = 0;

	for (ll i = 0; i < n; i++) {
		if (i == 0 || i == n - 1)
			sum += vec[i].ff;

		sum += 2 * vec[i].ss;
	}

	for (ll i = 1; i < n; i++) {
		sum += abs(vec[i].ff - vec[i - 1].ff);
	}

	cout << sum << "\n";
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

