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
	string s;
	cin >> s;

	vt<pair<ll, ll>>vec;

	ll x = s[0] - '0';
	ll y = s[sz(s) - 1] - '0';

	cout << abs(y - x) << " ";
	if (x > y) {
		for (ll i = 1; i < sz(s) - 1; i++) {
			if (s[i] - '0' <= x and s[i] - '0' >= y)
				vec.pb({s[i] - '0', i + 1});
		}

		cout << sz(vec) + 2 << "\n";

		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());

		cout << "1" << " ";

		for (auto i : vec)
			cout << i.second << " ";

		cout << sz(s) << "\n";
	}
	else {
		for (ll i = 1; i < sz(s) - 1; i++) {
			if (s[i] - '0' >= x and s[i] - '0' <= y)
				vec.pb({s[i] - '0', i + 1});
		}

		cout << sz(vec) + 2 << "\n";

		sort(vec.begin(), vec.end());

		cout << "1" << " ";

		for (auto i : vec)
			cout << i.second << " ";

		cout << sz(s) << "\n";
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
