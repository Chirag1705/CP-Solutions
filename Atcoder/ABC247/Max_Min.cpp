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

ll func(vt<ll>&vec, ll x, ll y) {
	ll l = 0, r = 0, cnt_x = 0, cnt_y = 0, res = 0;

	while (l != sz(vec)) {
		while (r != sz(vec) and (cnt_x == 0 or cnt_y == 0)) {
			if (vec[r] == x)
				cnt_x++;

			if (vec[r] == y)
				cnt_y++;

			r++;
		}

		if (cnt_x > 0 and cnt_y > 0)
			res += sz(vec) - r + 1;

		if (vec[l] == x)
			cnt_x--;

		if (vec[l] == y)
			cnt_y--;

		l++;
	}

	return res;
}

void solve() {

	ll n, x, y;
	cin >> n >> x >> y;

	vt<ll>arr(n);

	for (ll i = 0; i < n; i++)
		cin >> arr[i];

	ll i = 0, res = 0;

	while (i < n) {

		vt<ll>vec;

		while (i < n and arr[i] <= x and arr[i] >= y) {
			vec.pb(arr[i]);
			i++;
		}

		if (vec.size())
			res += func(vec, x, y);
		else
			i++;
	}

	cout << res << "\n";
}

int main()
{
	FASTIO;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// ll t;
	// cin >> t;
	// while (t--)
	// {
	solve();
	// }
}
