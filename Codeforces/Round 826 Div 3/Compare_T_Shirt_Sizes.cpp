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
	string a, b;
	cin >> a >> b;

	ll vara = 0, varb = 0;

	if (a[sz(a) - 1] == 'M')
		vara = 1;
	else if (a[sz(a) - 1] == 'S')
		vara = 0;
	else
		vara = 2;

	if (b[sz(b) - 1] == 'M')
		varb = 1;
	else if (b[sz(b) - 1] == 'S')
		varb = 0;
	else
		varb = 2;

	if (vara < varb)
		cout << "<" << "\n";
	else if (vara > varb)
		cout << ">" << "\n";
	else {
		if (vara == 1)
			cout << "=" << "\n";
		else if (vara == 0) {
			ll cnt1 = count(a.begin(), a.end(), 'X');
			ll cnt2 = count(b.begin(), b.end(), 'X');

			if (cnt1 > cnt2)
				cout << "<" << "\n";
			else if (cnt1 < cnt2)
				cout << ">" << "\n";
			else
				cout << "=" << "\n";
		}
		else {
			ll cnt1 = count(a.begin(), a.end(), 'X');
			ll cnt2 = count(b.begin(), b.end(), 'X');

			if (cnt1 > cnt2)
				cout << ">" << "\n";
			else if (cnt1 < cnt2)
				cout << "<" << "\n";
			else
				cout << "=" << "\n";
		}
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
