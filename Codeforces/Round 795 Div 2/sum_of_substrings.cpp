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

	string s;
	cin >> s;

	ll tmp = k;

	if (s[n - 1] != '1') {
		ll ind = -1;
		for (ll i = n - 2; i >= 0; i--) {
			if (s[i] == '1') {
				ind = i;
				break;
			}
		}

		if (ind > -1 && (n - 1 - ind) <= tmp) {
			swap(s[ind], s[n - 1]);
			tmp -= n - 1 - ind;
		}
	}
	// cout << tmp << " ";
	// cout << s << " ";

	if (s[0] != '1') {
		ll ind = -1;
		for (ll i = 1; i < n - 1; i++) {
			if (s[i] == '1') {
				ind = i;
				break;
			}
		}

		if (ind > -1 && (ind) <= tmp) {
			swap(s[ind], s[0]);
			tmp -= ind;
		}
	}
	// cout << s << " ";
	for (ll i = 0; i < n - 2; i++) {
		if (s[i] == '0' && s[i + 1] == '1' && s[i + 2] == '1' && tmp >= 1) {
			swap(s[i], s[i + 1]);
			tmp--;
		}
		else if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && tmp >= 1) {
			swap(s[i + 1], s[i + 2]);
			tmp--;
		}
	}

	// cout << s << " ";

	ll sum = 0;

	for (ll i = 0; i < n - 1; i++) {
		if (s[i] == '0' && s[i + 1] == '1')
			sum += 1;
		else if (s[i] == '0' && s[i + 1] == '0')
			sum += 0;
		else if (s[i] == '1' && s[i + 1] == '0')
			sum += 10;
		else
			sum += 11;
	}

	cout << sum << "\n";
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