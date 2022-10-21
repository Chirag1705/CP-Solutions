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
	ll n;
	cin >> n;

	vt<ll>arr(n), vec;
	// map<ll, ll>m1;
	// set<ll>s1;

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		// if (arr[i] < (i + 1)) {
		// 	m1[arr[i]]++;
		// 	s1.insert(i + 1);
		// }
	}

	// ll tmp = 0, ans = 0;

	// for (auto i : m1)
	// 	cout << i.first << " " << i.second << " ";
	// cout << "\n";

	// for (auto i : s1)
	// 	cout << i << " ";
	// cout << "\n";

	// for (ll i = 1; i <= n; i++) {
	// 	if (m1.find(i) != m1.end()) {
	// 		ans += m1[i] * tmp;
	// 	}

	// 	if (s1.find(i) != s1.end()) {
	// 		tmp++;
	// 	}
	// }

	ll ans = 0;

	for (ll i = 0; i < n; i++) {
		if (arr[i] >= (i + 1))
			continue;

		ans += lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
		vec.pb(i + 1);
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
	cin >> t;
	while (t--)
	{
		solve();
	}
}