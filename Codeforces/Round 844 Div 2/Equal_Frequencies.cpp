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
	ll n;
	cin >> n;

	string s;
	cin >> s;

	unordered_map<char, int>freq;
	unordered_map<char, vector<int>>loc;

	for (ll i = 0; i < n; i++) {
		freq[s[i]]++;
		loc[s[i]].pb(i);
	}

	string tmp = "abcdefghijklmnopqrstuvwxyz";
	sort(tmp.begin(), tmp.end(), [&](char& a, char& b) {
		return freq[a] > freq[b];
	});

	ll pos = 0, diff = INT_MAX, perChar = 0;

	for (ll i = 1; i <= 26; i++) {
		if (n % i != 0)
			continue;

		ll numberperChars = n / i;

		vector<ll>changes(26, 0);

		for (ll j = 0; j < i; j++) {
			changes[j] = abs(freq[tmp[j]] - numberperChars);
		}

		for (ll j = i; j < 26; j++) {
			changes[j] = freq[tmp[j]];
		}

		ll totchanges = accumulate(changes.begin(), changes.end(), 0);

		if (totchanges < diff) {
			diff = totchanges;
			pos = i;
			perChar = numberperChars;
		}
	}

	if (diff == 0) {
		cout << "0" << "\n" << s << "\n";
		return;
	}

	string res = s;
	ll i = 0, j = pos - 1, k = 25;

	while (k >= pos) {
		if (freq[tmp[k]] != 0) {
			ll idx = loc[tmp[k]].back();
			loc[tmp[k]].pop_back();
			res[idx] = tmp[j];
			freq[tmp[k]]--;
			freq[tmp[j]]++;
			if (freq[tmp[k]] == 0)
				k--;
			if (freq[tmp[j]] == perChar)
				j--;
		}
		else
			k--;
	}
	// cout << j << " ";
	while (i < j) {
		if (freq[tmp[i]] == perChar)
			i++;
		else if (freq[tmp[j]] == perChar)
			j--;
		else {
			ll idx = loc[tmp[i]].back();
			loc[tmp[i]].pop_back();
			res[idx] = tmp[j];
			freq[tmp[i]]--;
			freq[tmp[j]]++;
			if (freq[tmp[i]] == perChar)
				i++;
			if (freq[tmp[j]] == perChar)
				j--;
		}
	}

	cout << diff / 2 << "\n";
	cout << res << "\n";
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
