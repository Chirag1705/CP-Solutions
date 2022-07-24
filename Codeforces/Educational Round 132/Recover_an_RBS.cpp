#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size())
#define N 2e5+7
// #define mod 1e9 + 7
const ll mod = 1e9 + 7;
#define set_bits __builtin_popcountll


ll inv(ll i) {
	if (i == 1)
		return 1;

	return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}

ll mod_add(ll a, ll b) {
	a = a % mod;
	b = b % mod;

	return (((a + b) % mod) + mod) % mod;
}


ll mod_mul(ll a, ll b, ll m = mod) {
	a = a % m;
	b = b % m;

	return (((a * b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m = mod) {
	a = a % m;
	b = b % m;

	return ((a - b) + m) % m;
}

// another binpow method
ll pw(ll a, ll b, ll m) {
	if (b == 0)
		return 1;

	if (b % 2 == 0) {
		ll t = pw(a, b / 2, m);
		return (1LL * t * t % m);
	}
	else {
		ll t = pw(a, (b - 1) / 2, m);
		t = (1LL * t * t) % m;
		return (1LL * a * t % m);
	}
}

ll mod_div(ll a, ll b, ll m = mod) {
	a = a % m;

	ll inv_b = pw(b, m - 2, m);
	// inverse of b = b^m-2%m, only for prime m

	ll res = a * inv_b % m;

	return res;
}

// binary exponentiation
// binpow
// O(log(b))
ll modulo(ll a, ll b, ll n = mod) {
	ll x = 1, y = a;
	while (b > 0) {
		if (b % 2 == 1) {
			x = (x * y) % n; // multiplying with base
		}
		y = (y * y) % n; // squaring the base
		b /= 2;
	}
	return x % n;
}
// binpow again
ll pwr(ll a, ll b) {
	a %= mod;
	ll res = 1;

	while (b > 0) {
		if (b & 1)
			res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void func(map<string, ll>&m, string& s, ll j) {
	if (j == sz(s)) {
		bool f = 1;
		for (ll i = 0; i <= (sz(s) - 1) / 2; i++) {
			if (s[i] != s[sz(s) - 1 - i]) {
				f = 0;
				break;
			}
		}

		if (f)
			m[s]++;

		return;
	}

	for (ll i = j; i < sz(s); i++) {
		if (s[i] == '?') {
			s[i] = '(';
			func(m, s, i + 1);
			s[i] = ')';
		}
	}
}

void solve() {

	string s;
	cin >> s;

	ll open = 0, close = 0;

	for (ll i = 0; i < sz(s); i++) {
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
			close++;
	}

	ll openrem = sz(s) / 2 - open, closerem = sz(s) / 2 - close;

	if (openrem == 0 or closerem == 0)
		cout << "YES" << "\n";
	else {
		bool f = 0;

		for (ll i = 0; i < sz(s); i++) {
			if (s[i] != '?')
				continue;

			if (openrem == 1 and !f) {
				closerem--;
				s[i] = ')';
				f = 1;
			}
			else {
				if (openrem > 0) {
					openrem--;
					s[i] = '(';
				}
				else {
					closerem--;
					s[i] = ')';
				}
			}
		}

		ll cnt = 0;

		for (ll i = 0; i < sz(s); i++) {
			if (s[i] == ')')
				cnt--;
			else
				cnt++;

			if (cnt < 0) {
				cout << "YES" << "\n";
				return;
			}
		}

		cout << "NO" << "\n";
	}

// If 2nd optimal approach didnt give a RBS, that means there was an index i with pref[i]<0,
// if you use 3rd optimal approach, pref[i] will just decrease further as you will shift one more )
// i.e. -1  in front of  ( i.e. +1. So pref[i] will still be <0 and thus 3rd optimal and any further arrangement will not give RBS.


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
