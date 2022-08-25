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

vt<ll>z_func(string s)
{
	ll n = s.size(), L = -1, R = -1;
	vt<ll>z(n);
	z[0] = n;
	for (ll i = 1; i < n; i++) {
		if (i <= R)
			z[i] = min(z[i - L], R - i + 1);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			z[i]++;
		if (i + z[i] - 1 > R) {
			L = i;
			R = i + z[i] - 1;
		}
	}
	return z;
}

void solve() {
	ll n;
	string s;
	cin >> n;
	cin >> s;
	string str1, str2;
	string rev = s;
	reverse(rev.begin(), rev.end());
	str1 = s + '?' + rev;
	str2 = rev + '?' + s;
	vt<ll>v_pref, v_suff;
	v_pref = z_func(str1);
	v_suff = z_func(str2);

	// for (ll i = 0; i < n; i++)
	// 	cout << v_pref[i] << " " << v_suff[i] << " ";
	// cout << "\n";

	vector<bool>found(n, false);
	for (ll i = 0; i <= n - 1; i++)
	{
		if (v_suff[i] == n - i)
		{
			found[i] = true;
		}
	}
	ll min_len = n;
	for (ll i = 0; i <= n - 1; i++)
	{
		if (v_pref[i] == n - i and found[n - i])
		{

			min_len = min(min_len, n - i);
		}
	}
	string add = "";
	for (ll i = 1; i <= min_len; i++)
	{
		add += s[i - 1];
	}
	// reverse(add.begin(), add.end());
	cout << add << "\n";
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
	for (ll i = 1; i <= t ; i++)
	{
		cout << "Case #" << i << ":" << " ";
		solve();
	}
}
