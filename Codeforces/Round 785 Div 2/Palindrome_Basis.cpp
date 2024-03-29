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

	vt<ll>palindrome;

	palindrome.pb(0);

	for (ll i = 1; i <= 40000; i++) {
		string s1 = to_string(i);
		string s2 = to_string(i);
		reverse(s2.begin(), s2.end());

		if (s1 == s2)
			palindrome.pb(i);
	}

	ll sz = palindrome.size() - 1;

	vt<vt<ll>>dp(40001, vt<ll>(sz, 0));

	for (ll i = 0; i <= sz; i++) {
		dp[0][i] = 1;
	}

	for (ll i = 1; i <= 40000; i++) {
		for (ll j = 1; j <= sz; j++) {
			dp[i][j] = dp[i][j - 1];

			if (i - palindrome[j] >= 0) {
				dp[i][j] = (dp[i][j] + dp[i - palindrome[j]][j]) % mod;
			}
		}
	}

	while (t--) {
		ll n;
		cin >> n;
		cout << dp[n][sz] << "\n";
	}
}

/* vector<int> p;
ll helper(int n, int m, vector<vector<ll>>& dp){
    if(n < 0)
        return 0;
    if(m < 0){
        return n == 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    ll ways1 = helper(n - p[m], m, dp);
    ll ways2 = helper(n, m - 1, dp);
    dp[n][m] = (ways1 + ways2) % MOD;
    return dp[n][m];
}
void solve() {
    int t;
    cin >> t;
    for(int i = 1; i <= 4e4; i++){
        string a = to_string(i);
        string b = a;
        reverse(all(b));
        if(a == b){
            p.pb(i);
        }
    }
    int m = sz(p);
    vector<vector<ll>> dp(4e4 + 1, vector<ll>(m, -1));
    while(t--){
        int n;
        cin >> n;
        cout << helper(n, m - 1, dp) << nline;
    }
} */

int main()
{
	FASTIO;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();
}
