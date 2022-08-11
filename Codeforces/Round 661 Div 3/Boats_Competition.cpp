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

	vt<ll>arr(n);

	map<ll, ll>m;

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		m[arr[i]]++;
	}

	// sort(arr.begin(), arr.end());

	// ll x = arr[0] + arr[1];
	// ll y = arr[n - 2] + arr[n - 1];
	ll ans = INT_MIN;

	for (ll i = 2; i <= 2 * n; i++) {
		map<ll, ll>m1 = m;
		ll cnt = 0;
		for (ll j = 0; j < n; j++) {
			if (arr[j] >= i)
				continue;

			if ((arr[j] != i / 2) or ((arr[j] == i / 2) and (i % 2 != 0))) {
				if (m1[i - arr[j]] >= 1 and m1[arr[j]] >= 1) {
					m1[arr[j]]--, m1[i - arr[j]]--;
					cnt++;
				}
			}
			else if ((arr[j] == i / 2) and (i % 2 == 0)) {
				if (m1[arr[j]] >= 2) {
					m1[arr[j]] -= 2;
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
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
