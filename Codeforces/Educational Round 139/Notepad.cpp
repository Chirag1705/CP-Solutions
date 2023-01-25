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

	string s;
	cin >> s;

	map<string, ll>mp;

	string s1;

	for (ll i = 0; i < 2; i++) {
		s1 += s[i];
	}
	mp[s1]++;

	for (ll i = 2; i < n; i++) {
		string s2;
		for (ll k = i; k < min(n, i + 2); k++) {
			s2 += s[k];
		}
		if (sz(s2) == 2)
			mp[s2]++;
		if (mp[s2] > 1) {
			cout << "YES" << "\n";
			return;
		}
		else {
			mp[s2] = 0;
			string s3;
			for (ll k = i; k > i - 2; k--) {
				s3 += s[k];
			}
			reverse(s3.begin(), s3.end());
			mp[s3]++;
		}
	}

	cout << "NO" << "\n";
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
