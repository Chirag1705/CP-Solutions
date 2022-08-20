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
	ll n, k, b, s;
	cin >> n >> k >> b >> s;

	if (b == 0 and s == 0) {
		for (ll i = 0; i < n; i++)
			cout << "0" << " ";
		cout << "\n";
		return;
	}

	ll big1 = k * (b + 1) - 1;
	ll big2 = k * b;
	// cout << big1 << " " << big2 << " ";
	if (big1 >= s and s >= big2) {
		for (ll i = 0; i < n - 1; i++)
			cout << "0" << " ";
		cout << s << "\n";

		return;
	}

	if (k * b > s) {
		cout << "-1" << "\n";
		return;
	}

	ll temp = s - (k * (b + 1) - 1);
	ll temp1 = (n - 1) * (k - 1);

	if (temp <= temp1) {
		s -= (k * (b + 1) - 1);
		for (ll i = 0; i < n - 1; i++) {
			if (s == 0) {
				cout << "0" << " ";
			}
			else {
				if (s >= (k - 1)) {
					cout << (k - 1) << " ";
					s -= (k - 1);
				}
				else {
					cout << s << " ";
					s = 0;
				}
			}
		}
		cout << (k * (b + 1) - 1) << " ";

		cout << "\n";
	}
	else
		cout << "-1" << "\n";
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
