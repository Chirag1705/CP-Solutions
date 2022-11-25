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

	if (m[1] == 0) {
		cout << "0" << "\n";
		return;
	}

	ll i = 2;

	while (1) {
		if (m[1] < 2) {
			if (m[1] == 0)
				cout << i - 2 << "\n";
			else
				cout << i - 1 << "\n";

			return;
		}

		if (m[i])
			m[1]--;
		else {
			bool f = 0;

			for (ll j = i - 1; j > 1; j--) {
				if (m[j] > 1) {
					m[j]--;
					f = 1;
					break;
				}
			}

			if (f)
				m[1]--;
			else
				m[1] -= 2;
		}

		i++;
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
