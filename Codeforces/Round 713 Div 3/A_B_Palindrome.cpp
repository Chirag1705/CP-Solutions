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
	ll a, b;
	cin >> a >> b;

	string s;
	cin >> s;

	// if (s.size() == 1) {
	// 	if (a and s[0] == '?')
	// 		cout << "0" << "\n";
	// 	else if (b and s[0] == '?')
	// 		cout << "1" << "\n";
	// 	else if (s[0] == '0' and a)
	// 		cout << s << "\n";
	// 	else if (s[0] == '1' and b)
	// 		cout << s << "\n";
	// 	else
	// 		cout << "-1" << "\n";

	// 	return;
	// }

	ll i = 0, j = s.size() - 1;
	ll cnt = 0;

	while (j >= i) {
		if (s[i] == s[j]) {
			if (s[i] == '?') {
				if (i == j)
					cnt++;
				else
					cnt += 2;
			}
			else if (s[i] == '1') {
				if (i == j)
					b--;
				else
					b -= 2;
			}
			else if (s[i] == '0') {
				if (i == j)
					a--;
				else
					a -= 2;
			}
		}
		else if ((s[i] == '?' and s[j] == '1') or (s[j] == '?' and s[i] == '1')) {
			if (b >= 2) {
				b -= 2;
				if (s[i] == '?')
					s[i] = '1';
				else
					s[j] = '1';
			}
			else {
				cout << "-1" << "\n";
				return;
			}
		}
		else if ((s[i] == '?' and s[j] == '0') or (s[j] == '?' and s[i] == '0')) {
			if (a >= 2) {
				a -= 2;
				if (s[i] == '?')
					s[i] = '0';
				else
					s[j] = '0';
			}
			else {
				cout << "-1" << "\n";
				return;
			}
		}
		else if (s[i] != s[j] and s[i] != '?' and s[j] != '?') {
			cout << "-1" << "\n";
			return;
		}
		i++;
		j--;
	}

	if (a + b == cnt) {
		ll j = s.size() - 1, i = 0;
		if (cnt % 2 == 0 and a % 2 == 0 and b % 2 == 0) {
			while (j >= i) {
				if (s[i] == s[j] and s[i] == '?') {
					if (i != j) {
						if (a >= 2) {
							a -= 2;
							s[i] = s[j] = '0';
						}
						else {
							b -= 2;
							s[i] = s[j] = '1';
						}
					}
					else {
						if (a) {
							a--;
							s[i] = s[j] = '0';
						}
						else {
							b--;
							s[i] = s[j] = '1';
						}

					}
				}
				i++;
				j--;
			}
		}
		else if ((cnt % 2 == 1 and a % 2 == 0 and b % 2 == 1) or (cnt % 2 == 1 and a % 2 == 1 and b % 2 == 0)) {
			ll j = s.size() - 1, i = 0;
			while (j >= i) {
				if (s[i] == s[j] and s[i] == '?') {
					if (i != j) {
						if (a >= 2) {
							a -= 2;
							s[i] = s[j] = '0';
						}
						else {
							b -= 2;
							s[i] = s[j] = '1';
						}
					}
					else {
						if (a) {
							a--;
							s[i] = s[j] = '0';
						}
						else {
							b--;
							s[i] = s[j] = '1';
						}

					}
				}
				i++;
				j--;
			}
		}

		if (a == 0 and b == 0)
			cout << s << "\n";
		else
			cout << "-1" << "\n";

		return;
	}

	cout << "-1" << "\n";

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