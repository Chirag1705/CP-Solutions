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

	string t;
	cin >> t;

	vector<ll>edge1(26, -1), edge2(26, -1);

	auto get_path = [&](ll c) {
		ll len = 0;
		ll cur = c;

		while (edge1[cur] != -1)
			len++, cur = edge1[cur];

		return make_pair(cur, len);
	};

	vector<ll>vec(n);

	for (ll i = 0; i < n; i++)
		vec[i] = t[i] - 'a';

	for (ll i = 0; i < n; i++) {
		if (edge1[vec[i]] == -1) {
			for (ll c = 0; c < 26; c++) {
				if (edge2[c] == -1) {
					pair<ll, ll>var = get_path(c);
					if (var.ff != vec[i] || var.ss == 25) {
						edge1[vec[i]] = c;
						edge2[c] = vec[i];
						break;
					}
				}
			}
		}

		vec[i] = edge1[vec[i]];
	}

	for (ll i = 0; i < n; i++)
		t[i] = vec[i] + 'a';

	cout << t << "\n";
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
