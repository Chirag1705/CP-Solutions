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

	if (n < k) {
		cout << "NO" << "\n";
		return;
	}

	if (n % k == 0) {
		cout << "YES" << "\n";
		for (ll i = 1; i <= k; i++) {
			cout << n / k << " ";
		}
		cout << "\n";
		return;
	}

	if (n % 2 == 0) {
		if (k % 2 == 0) {
			if (n - (k - 1) <= 0) {
				cout << "NO" << "\n";
				return;
			}
			cout << "YES" << "\n";
			cout << n - (k - 1) << " ";
			for (ll i = 1; i <= (k - 1); i++)
				cout << "1" << " ";
			cout << "\n";
		}
		else {
			if (n - (k - 1) * 2 <= 0) {
				cout << "NO" << "\n";
				return;
			}
			cout << "YES" << "\n";
			cout << n - (k - 1) * 2 << " ";
			for (ll i = 1; i <= (k - 1); i++)
				cout << "2" << " ";
			cout << "\n";
		}
	}
	else {
		if (k % 2 != 0) {
			if (n - (k - 1) <= 0) {
				cout << "NO" << "\n";
				return;
			}
			cout << "YES" << "\n";
			cout << n - (k - 1) << " ";
			for (ll i = 1; i <= (k - 1); i++)
				cout << "1" << " ";
			cout << "\n";
		}
		else
			cout << "NO" << "\n";
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