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



void solve() {
	ll t;
	cin >> t;

	for (ll x = 0; x < t; x++) {
		string s;
		cin >> s;

		ll sum = 0;

		for (ll i = 0; i < s.size(); i++) {
			sum += s[i] - '0';
		}

		ll div = 0;

		if (sum % 9 > 0)
			div = 9 - (sum % 9);

		ll ind = 0;
		bool f = 0;

		if (div != 0) {
			for (ll i = 0; i < s.size(); i++) {
				if (div < (s[i] - '0')) {
					s.insert(s.begin() + i, char(div + '0'));
					f = 1;
					break;
				}
			}
		}
		else {
			f = 1;
			s.insert(s.begin() + 1, '0');
		}

		if (f == 0) {
			s.insert(s.begin() + s.size(), char(div + '0'));
		}

		cout << "Case #" << x + 1 << ":" << " ";

		cout << s << "\n";
	}
}

int main()
{
	FASTIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	solve();

}
