#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size())
#define ff first
#define ss second
#define INF 2e18
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

ll func(ll i, ll j, vector<vector<ll>>grid, ll n, ll m) {

	if (grid[i][j] == 1)
		return 0;
	if (i == n and j == m)
		return 1;
	if (i > n or j > m or i < 0 or j < 0)
		return 0;

	ll ans = 0;

	ans += func(i + 1, j, grid, n, m);
	ans += func(i, j + 1, grid, n, m);
	ans += func(i - 1, j, grid, n, m);
	ans += func(i, j - 1, grid, n, m);

	return ans;
}
void solve() {
	ll n;
	cin >> n;

	vt<ll>a(n), b(n);

	for (ll i = 0; i < n; i++)
		cin >> a[i];

	for (ll i = 0; i < n; i++)
		cin >> b[i];

	for (ll i = 0; i < n; i++) {
		auto it = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		cout << b[it] - a[i] << " ";
	}
	cout << "\n";

	a.pb(INF);
	ll j = 0;

	for (ll i = 0; i < n; i++) {
		if (b[i] < a[i + 1]) {
			while (j <= i) {
				cout << b[i] - a[j] << " ";
				j++;
			}
		}
	}
	cout << "\n";
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
