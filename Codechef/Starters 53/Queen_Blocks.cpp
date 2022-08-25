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
	ll x, y;
	cin >> x >> y;

	vt<vt<ll>>chess(8, vt<ll>(8, 0));
	bool f = 0;


	if (x == 1 and y == 1 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x][y + 1] = 2;
		f = 1;
	}

	if (x == 8 and y == 1 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 3][y] = 2;
		f = 1;
	}

	if (x == 1 and y == 8 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x][y - 3] = 2;
		f = 1;
	}

	if (x == 8 and y == 8 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 2][y - 3] = 2;
		f = 1;
	}

	if (x == 2 and y == 2 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 2][y + 1] = 2;
		chess[x + 2][y - 2] = 2;
		f = 1;
	}

	if (x == 7 and y == 2 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x][y + 1] = 2;
		chess[x - 4][y - 2] = 2;
		f = 1;
	}

	if (x == 2 and y == 7 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 2][y - 3] = 2;
		chess[x + 2][y] = 2;
		f = 1;
	}

	if (y == 7 and x == 7 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 4][y] = 2;
		chess[x][y - 3] = 2;
		f = 1;
	}

	if (x == 1 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x + 1][y - 2] = 2;
		chess[x + 1][y] = 2;
		f = 1;
	}

	if (x == 8 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 3][y - 2] = 2;
		chess[x - 3][y] = 2;
		f = 1;
	}

	if (y == 1 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 2][y + 1] = 2;
		chess[x][y + 1] = 2;
		f = 1;
	}

	if (y == 8 and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 2][y - 3] = 2;
		chess[x][y - 3] = 2;
		f = 1;
	}

	if ((y == 2 or y == 7) and !f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 3][y - 2] = 2;
		chess[x + 1][y] = 2;
		f = 1;
	}

	if (!f) {
		chess[x - 1][y - 1] = 1;
		chess[x - 2][y + 1] = 2;
		chess[x][y - 3] = 2;
		f = 1;
	}

	for (ll i = 0; i < 8; i++) {
		for (ll j = 0; j < 8; j++) {
			cout << chess[i][j] << " ";
		}
		cout << "\n";
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
