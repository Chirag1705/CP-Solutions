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
	ll n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	ll rem1 = n - count(s.begin(), s.end(), 'b');
	ll rem2 = n - count(t.begin(), t.end(), 'b');
	vector<pair<char, ll>>s1(rem1), t1(rem2);

	ll j = 0, k = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] != 'b') {
			s1[j].ff = s[i];
			s1[j].ss = i;
			j++;
		}

		if (t[i] != 'b') {
			t1[k].ff = t[i];
			t1[k].ss = i;
			k++;
		}
	}

	if (sz(s1) != sz(t1)) {
		cout << "NO" << "\n";
		return;
	}

	for (ll i = 0; i < sz(s1); i++) {
		if (s1[i].ff != t1[i].ff || (s1[i].ff == 'a' && s1[i].ss > t1[i].ss) || (s1[i].ff == 'c' && s1[i].ss < t1[i].ss)) {
			cout << "NO" << "\n";
			return;
		}
	}

	cout << "YES" << "\n";

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
