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

	vt<ll>arr(n), vec(n);

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll oper = 0;
	ll tmp = n;

	for (ll i = 0; i < n; i++) {
		ll cnt2 = 0;
		while (arr[i] % 2 == 0) {
			cnt2++;
			arr[i] /= 2;
		}
		tmp -= cnt2;

		if (tmp <= 0)
			break;
	}
	// cout << tmp << " " ;
	if (tmp > 0) {
		for (ll i = 0; i < n; i++) {
			ll var = i + 1;
			ll cnt2 = 0;

			while (var % 2 == 0) {
				cnt2++;
				var /= 2;
			}

			vec[i] = cnt2;
		}

		sort(vec.begin(), vec.end(), greater<int>());

		for (ll i = 0; i < n; i++) {
			tmp -= vec[i];
			oper++;

			if (tmp <= 0)
				break;
		}

		if (tmp <= 0)
			cout << oper << "\n";
		else
			cout << "-1" << "\n";
	}
	else
		cout << "0" << "\n";
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
