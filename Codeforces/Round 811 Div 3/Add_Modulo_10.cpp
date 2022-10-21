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

	ll cnt = 0;

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] % 10 == 0 or arr[i] % 10 == 5)
			cnt++;
	}

	if (cnt != n and cnt != 0) {
		cout << "No" << "\n";
	}
	else if (cnt == n) {
		for (ll i = 0; i < n; i++) {
			if (arr[i] % 10 == 5)
				arr[i] += 5;
		}

		for (ll i = 0; i < n - 1; i++) {
			if (arr[i] != arr[i + 1]) {
				cout << "No" << "\n";
				return;
			}
		}

		cout << "Yes" << "\n";
		return;
	}
	else {
		for (ll i = 0; i < n; i++) {
			while (arr[i] % 10 != 6) {
				arr[i] += (arr[i] % 10);
			}
		}

		string s = to_string(arr[0]);
		if (sz(s) == 1)
			s = '0';
		else
			s = s.substr(0, sz(s) - 1);
		// cout << s << " ";
		for (ll i = 1; i < n; i++) {
			string s1 = to_string(arr[i]);
			if (sz(s1) == 1)
				s1 = '0';
			else
				s1 = s1.substr(0, sz(s1) - 1);

			// cout << s1 << " ";
			if (stoi(s) % 2 != stoi(s1) % 2) {
				cout << "No" << "\n";
				return;
			}
		}

		cout << "Yes" << "\n";
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