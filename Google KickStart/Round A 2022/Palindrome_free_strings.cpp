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

bool notPalindrome(string a) {
	string b = a;
	reverse(b.begin(), b.end());
	if (b != a)
		return 1;
	else
		return 0;
}
int helper(string prev, int index, string& s, map<pair<int, string>, int>& dp) {
	if (index == sz(s)) {
		return 1;
	}
	if (dp.find({index, prev}) != dp.end()) {
		return dp[ {index, prev}];
	}
	string x1 = prev.substr(1, 4);
	string x2 = prev.substr(1, 4);
	x1 += "0";
	x2 += "1";
	int ans = 0;
	if (s[index] == '?') {
		if (notPalindrome(x1) && notPalindrome(prev + "0"))
			ans += helper(x1, index + 1, s, dp);
		if (notPalindrome(x2) && notPalindrome(prev + "1"))
			ans += helper(x2, index + 1, s, dp);
	} else if (s[index] == '1') {
		if (notPalindrome(x2) && notPalindrome(prev + "1"))
			ans += helper(x2, index + 1, s, dp);
	} else {
		if (notPalindrome(x1) && notPalindrome(prev + "0"))
			ans += helper(x1, index + 1, s, dp);
	}
	dp[ {index, prev}] = ans;
	return ans;
}



void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<pair<int, string>, int> dp;

	if (helper("?????", 0, s, dp))
		cout << "POSSIBLE" << "\n";
	else
		cout << "IMPOSSIBLE" << "\n";
}

int main()
{
	FASTIO;

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	ll t;
	cin >> t;
	for (ll i = 0; i < t; i++)
	{
		cout << "Case #" << i + 1 << ":" << " ";
		solve();
	}
}