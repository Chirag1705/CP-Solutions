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

	vt<bool>vec(sz(s), 0);

	if (sz(s) == 1) {
		cout << s << "\n";
		return;
	}

	ll i = sz(s) - 1;
	ll j = sz(s) - 2;

	while (j >= 0) {
		if (s[j] <= s[i]) {
			i = j;
			j = i - 1;
		}
		else {
			vec[j] = 1;
			j--;
		}
	}

	string s1;
	string s2;

	for (ll i = 0; i < sz(s); i++) {
		if (vec[i] == 0)
			s2 += s[i];
		else {
			s1 += to_string(min(9, s[i] - '0' + 1));
		}
	}

	if (sz(s2) == 0) {
		cout << s1 << "\n";
		return;
	}

	if (sz(s1) == 0) {
		cout << s2 << "\n";
		return;
	}


	sort(s1.begin(), s1.end());

	ll k = -1;

	for (ll i = sz(s2) - 1; i >= 0; i--) {
		if (s2[i] - '0' >= s1[0] - '0') {
			s1 += s2[i];
			k = i;
		}
		else
			break;
	}

	sort(s1.begin(), s1.end());

	if (k == -1)
		cout << s2 + s1 << "\n";
	else
		cout << s2.substr(0, k) + s1 << "\n";
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
