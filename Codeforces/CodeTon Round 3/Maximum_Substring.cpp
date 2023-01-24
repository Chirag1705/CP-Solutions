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

ll inf = 1e18;

void solve() {
	ll n;
	cin >> n;

	string s;
	cin >> s;

	ll cnt1 = 0, cnt0 = 0;

	for (ll i = 0; i < n; i++) {
		if (s[i] == '0')
			cnt0++;
		else
			cnt1++;
	}

	if (cnt0 == 0) {
		cout << cnt1*cnt1 << "\n";
		return;
	}

	if (cnt1 == 0) {
		cout << cnt0*cnt0 << "\n";
		return;
	}

	ll ans = cnt1 * cnt0;

	ll maxcnt1 = 0, maxcnt0 = 0;
	ll tmp = 0;
	bool f = 0;

	for (ll i = 0; i < n - 1; i++) {
		if (f && s[i] == s[i + 1] && s[i] == '1')
			tmp++;
		else if (!f && s[i] == s[i + 1] && s[i] == '1') {
			f = 1;
			tmp = 2;
		}
		else {
			maxcnt1 = max(maxcnt1, tmp);
			tmp = 0;
			f = 0;
		}
	}

	maxcnt1 = max(maxcnt1, tmp);
	f = 0;
	tmp = 0;

	for (ll i = 0; i < n - 1; i++) {
		if (f && s[i] == s[i + 1] && s[i] == '0')
			tmp++;
		else if (!f && s[i] == s[i + 1] && s[i] == '0') {
			f = 1;
			tmp = 2;
		}
		else {
			maxcnt0 = max(maxcnt0, tmp);
			tmp = 0;
			f = 0;
		}
	}

	maxcnt0 = max(maxcnt0, tmp);

	ans = max({ans, maxcnt0 * maxcnt0, maxcnt1 * maxcnt1});

	cout << ans << "\n";
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

