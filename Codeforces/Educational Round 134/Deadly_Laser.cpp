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
	ll n, m, sx, sy, d;
	cin >> n >> m >> sx >> sy >> d;
	sx--, sy--;

	// vt<vt<ll>>grid(n, vt<ll>(m, 0));

	// grid[sx][sy] = 1;

	// for (ll i = 0; i < n; i++) {
	// 	for (ll j = 0; j < m; j++) {
	// 		if (abs(i - sx) + abs(j - sy) <= d and (i == sx or j == sy))
	// 			grid[i][j] = 1;
	// 	}
	// }

	ll x1 = sx + d;
	ll y1 = sy + d;
	ll x2 = sx - d;
	ll y2 = sy - d;

	if ((x2 <= 0 and y2 <= 0) or (x1 >= n - 1 and y1 >= m - 1) or (x1 >= n - 1 and x2 <= 0) or (y1 >= m - 1 and y2 <= 0)) {
		cout << "-1" << "\n";
		return;
	}

	cout << n - 1 + m - 1 << "\n";
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
