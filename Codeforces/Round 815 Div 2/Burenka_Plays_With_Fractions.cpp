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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	if (__gcd(a, b) > 1) {
		ll x = __gcd(a, b);
		a /= x;
		b /= x;
	}

	// cout << a << " " << b << " ";
	if (__gcd(c, d) > 1) {
		ll y = __gcd(c, d);
		c /= y;
		d /= y;
	}

	// cout << c << " " << d << " ";

	if ((a == c and b == d) or (a == 0 and c == 0)) {
		cout << "0" << "\n";
		return;
	}

	if (a == 0 or c == 0) {
		cout << "1" << "\n";
		return;
	}

	if ((max(a, c) % min(a, c) == 0) and (max(b, d) % min(b, d) == 0)) {
		if ((a >= c and b <= d) or (a <= c and b >= d)) {
			cout << "1" << "\n";
			return;
		}
	}

	cout << "2" << "\n";
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
