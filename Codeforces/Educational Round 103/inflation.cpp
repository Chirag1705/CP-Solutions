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

	vt<ll>arr(n);

	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	// ll x = 0, sum = arr[0];

	// for (ll i = 1; i < n; i++) {
	// 	x = max(x, (100 * 1ll * arr[i] - k * sum + (k - 1)) / k);
	// 	sum += arr[i];
	// }

	// cout << x << "\n";

	// ----> Another Method

	ll tot = arr[0];
	ll sum = 0;

	for (ll i = 1; i < n; i++) {
		ll ans = 0;
		ll vr = arr[i] * 100;
		ll tmp1 = vr / tot;
		ll tmp2 = vr % tot;
		if ((tmp1 < k) || (tmp1 == k && tmp2 == 0)) {
			tot += arr[i];
			continue;
		}

		if ((vr - tot * k) % k == 0)
			ans += (vr - tot * k) / k;
		else
			ans += (vr - tot * k) / k + 1;

		tot += arr[i];
		tot += ans;
		sum += ans;
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