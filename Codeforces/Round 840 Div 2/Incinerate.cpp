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
	ll n, k;
	cin >> n >> k;

	// vt<pair<ll, ll>>p_h(n);
	// ll maxel = INT_MIN;

	// for (ll i = 0; i < n; i++) {
	// 	cin >> p_h[i].ss;
	// 	if (p_h[i].ss > maxel)
	// 		maxel = p_h[i].ss;
	// }

	// for (ll i = 0; i < n; i++)
	// 	cin >> p_h[i].ff;

	// sort(p_h.begin(), p_h.end());

	// ll tot = 0, tmp = k;

	// for (ll i = 0; i < n; i++) {
	// 	if (p_h[i].ss > tot && i != 0)
	// 		tmp -= p_h[i].ff;

	// 	while (p_h[i].ss > tot && tmp > 0) {
	// 		tot += tmp;
	// 		if (p_h[i].ss > tot)
	// 			tmp -= p_h[i].ff;
	// 	}

	// 	if (tot >= maxel) {
	// 		cout << "YES" << "\n";
	// 		return;
	// 	}

	// 	if (tmp <= 0) {
	// 		cout << "NO" << "\n";
	// 		return;
	// 	}
	// }

	// ----> Method 2

	vt<pair<ll, ll>>h_p(n);
	vt<ll>suff(n), h(n);

	for (ll i = 0; i < n; i++) {
		cin >> h_p[i].ff;
	}

	for (ll i = 0; i < n; i++)
		cin >> h_p[i].ss;

	sort(h_p.begin(), h_p.end());

	for (ll i = 0; i < n; i++)
		h[i] = h_p[i].ff;

	suff[n - 1] = h_p[n - 1].ss;

	for (ll i = n - 2; i >= 0; i--)
		suff[i] = min(suff[i + 1], h_p[i].ss);

	// for (auto i : suff)
	// 	cout << i << " ";

	ll tmp = k, tot = 0;
	ll vr = 0;
	while (tmp > 0 && vr < n) {
		tot += tmp;
		vr = upper_bound(h.begin(), h.end(), tot) - h.begin();
		if (vr >= n) {
			cout << "YES" << "\n";
			return;
		}
		tmp -= suff[vr];
	}

	if (tmp <= 0) {
		cout << "NO" << "\n";
		return;
	}

	if (vr >= n) {
		cout << "YES" << "\n";
		return;
	}
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

2nd ->

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
	ll n, k;
	cin >> n >> k;

	vt<pair<ll, ll>>p_h(n);
	ll maxel = INT_MIN;

	for (ll i = 0; i < n; i++) {
		cin >> p_h[i].ss;
		if (p_h[i].ss > maxel)
			maxel = p_h[i].ss;
	}

	for (ll i = 0; i < n; i++)
		cin >> p_h[i].ff;

	sort(p_h.begin(), p_h.end());

	ll tot = 0, tmp = k;

	for (ll i = 0; i < n; i++) {
		if (p_h[i].ss > tot && i != 0)
			tmp -= p_h[i].ff;

		while (p_h[i].ss > tot && tmp > 0) {
			tot += tmp;
			if (p_h[i].ss > tot)
				tmp -= p_h[i].ff;
		}

		if (tot >= maxel) {
			cout << "YES" << "\n";
			return;
		}

		if (tmp <= 0) {
			cout << "NO" << "\n";
			return;
		}
	}
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
