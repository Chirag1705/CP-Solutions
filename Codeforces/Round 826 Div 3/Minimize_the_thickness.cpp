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

	vt<ll>arr(n), pref_sum(n);

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0)
			pref_sum[i] = arr[i];
		else
			pref_sum[i] = arr[i] + pref_sum[i - 1];
	}

	ll minthick = n;

	for (ll i = 0; i < n; i++) {
		ll lastnum = pref_sum[i];
		ll tmp = i + 1;
		ll allele = i + 1;
		ll lastele = i;
		for (ll j = i + 1; j < n; j++) {
			if (pref_sum[j] - lastnum == pref_sum[i]) {
				lastnum = pref_sum[j];
				allele += (j - lastele);
				tmp = max(tmp, j - lastele);
				lastele = j;
			}
		}
		// cout << allele << " ";
		if (allele == n) {
			minthick = min(minthick, tmp);
		}
	}

	cout << minthick << "\n";
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
