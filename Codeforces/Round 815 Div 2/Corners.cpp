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
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > '0') {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

ll inv(ll i) { if (i == 1) return 1; return (mod - ((mod / i) * inv(mod % i)) % mod) % mod; }

ll mod_add(ll a, ll b) { a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}

ll mod_mul(ll a, ll b, ll m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }

ll mod_sub(ll a, ll b, ll m = mod) { a = a % m; b = b % m; return ((a - b) + m) % m; }

ll mod_div(ll a, ll b, ll m = mod) { a = a % m; ll inv_b = expo(b, m - 2, m); ll res = a * inv_b % m; return res; }

void solve() {
	ll n, m;
	cin >> n >> m;

	vt<string>v(n);

	for (ll i = 0; i < n; i++) {
		cin >> v[i];
	}

	bool f = 0;

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (v[i][j] == '0') {
				if (i == 0 and j == 0) {
					if (v[i + 1][j] == '0' or v[i][j + 1] == '0' or v[i + 1][j + 1] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (i == n - 1 and j == 0) {
					if (v[i - 1][j] == '0' or v[i][j + 1] == '0' or v[i - 1][j + 1] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (i == 0 and j == m - 1) {
					if (v[i + 1][j] == '0' or v[i][j - 1] == '0' or v[i + 1][j - 1] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (i == n - 1 and j == m - 1) {
					if (v[i - 1][j] == '0' or v[i][j - 1] == '0' or v[i - 1][j - 1] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (i == 0) {
					if (v[i][j - 1] == '0' or v[i][j + 1] == '0' or v[i + 1][j - 1] == '0' or v[i + 1][j + 1] == '0' or v[i + 1][j] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (i == n - 1) {
					if (v[i][j - 1] == '0' or v[i][j + 1] == '0' or v[i - 1][j - 1] == '0' or v[i - 1][j + 1] == '0' or v[i - 1][j] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (j == 0) {
					if (v[i - 1][j] == '0' or v[i + 1][j] == '0' or v[i - 1][j + 1] == '0' or v[i + 1][j + 1] == '0' or v[i][j + 1] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (j == m - 1) {
					if (v[i - 1][j] == '0' or v[i + 1][j] == '0' or v[i + 1][j - 1] == '0' or v[i - 1][j - 1] == '0' or v[i][j - 1] == '0') {
						f = 1;
						break;
					}
					continue;
				}

				if (v[i - 1][j] == '0' or v[i + 1][j] == '0' or v[i - 1][j + 1] == '0' or v[i + 1][j + 1] == '0' or v[i][j + 1] == '0' or v[i + 1][j - 1] == '0' or v[i - 1][j - 1] == '0' or v[i][j - 1] == '0') {
					f = 1;
					break;
				}
			}
		}
		if (f)
			break;
	}

	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (v[i][j] == '1')
				cnt++;
		}
	}

	// cout << cnt << " ";

	if (cnt == n * m) {
		cout << cnt - 2 << "\n";
		return;
	}

	if (f)
		cout << cnt << "\n";
	else
		cout << cnt - 1 << "\n";
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
