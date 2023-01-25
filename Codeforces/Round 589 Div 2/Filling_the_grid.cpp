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

	vt<vt<ll>>grid(n, vt<ll>(m, 0));

	for (ll i = 0; i < n; i++) {
		ll x;
		cin >> x;

		for (ll j = 0; j < x; j++) {
			grid[i][j] = 1;
		}

		if (x != m)
			grid[i][x] = 2;
	}

	for (ll j = 0; j < m; j++) {
		ll x;
		cin >> x;

		for (ll i = 0; i < x; i++) {
			if (grid[i][j] == 2) {
				cout << "0" << "\n";
				return;
			}

			grid[i][j] = 1;
		}

		if (x != n) {
			if (grid[x][j] == 1) {
				cout << "0" << "\n";
				return;
			}
			else
				grid[x][j] = 2;

		}
	}

	ll cnt = 0;

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (grid[i][j] == 0)
				cnt++;
		}
	}

	ll ans = expo(2, cnt, mod);

	cout << ans << "\n";
}

int main()
{
	FASTIO;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ll t;
	// cin >> t;
	// while (t--)
	// {
	solve();
	// }
}
