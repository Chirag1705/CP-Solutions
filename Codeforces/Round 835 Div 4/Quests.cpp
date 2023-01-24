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
	ll n, c, d;
	cin >> n >> c >> d;

	vt<ll>arr(n), pref_sum(n);

	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	ll sum = 0, j = 0;

	for (ll i = n - 1; i >= 0; i--) {
		sum += arr[i];
		pref_sum[j] = sum;
		j++;
	}

	if (d * arr[n - 1] < c) {
		cout << "Impossible" << "\n";
		return;
	}

	if (pref_sum[min(n - 1, d - 1)] >= c) {
		cout << "Infinity" << "\n";
		return;
	}

	ll l = 0, r = d;
	ll ans = 0;

	while (l <= r) {
		ll k = (l + r) / 2;

		ll tmp = k + 1;
		ll tmp1 = d / tmp;
		ll tmp2 = min(d % tmp, n);
		ll s = pref_sum[min(tmp - 1, n - 1)];
		s = tmp1 * s;

		if (tmp2 != 0)
			s += pref_sum[min(tmp2 - 1, n - 1)];

		if (s >= c) {
			ans = max(k, ans);
			l = k + 1;
		}
		else
			r = k - 1;
	}

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

