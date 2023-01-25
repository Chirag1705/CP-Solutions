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
	ll w, d, h;
	cin >> w >> d >> h;

	ll a, b, f, g;
	cin >> a >> b >> f >> g;

	ll ans = 0;
	ll n1 = 0, n2 = 0;

	ll ans1 = f;
	n1 = 0, n2 = g;
	ans1 += h;
	ans1 += abs(n1 - a) + abs(n2 - b);

	ll ans2 = g;
	n1 = f, n2 = 0;
	ans2 += h;
	ans2 += abs(n1 - a) + abs(n2 - b);

	ll ans3 = abs(w - f);
	n1 = w, n2 = g;
	ans3 += h;
	ans3 += abs(n1 - a) + abs(n2 - b);

	ll ans4 = abs(g - d);
	n1 = f, n2 = d;
	ans4 += h;
	ans4 += abs(n1 - a) + abs(n2 - b);

	ans = min({ans1, ans2, ans3, ans4});
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
