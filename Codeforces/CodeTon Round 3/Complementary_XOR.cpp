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

ll inf = 1e18;

void solve() {
	ll n;
	cin >> n;

	string s1, s2;
	cin >> s1 >> s2;

	ll opp = 0, eq = 0;

	for (ll i = 0; i < n; i++) {
		if (s1[i] == s2[i])
			eq++;
		else
			opp++;
	}

	if (eq != n && opp != n)
		cout << "NO" << "\n";
	else {
		cout << "YES" << "\n";

		ll f_cnt1 = count(s1.begin(), s1.end(), '1');
		ll s_cnt1 = count(s2.begin(), s2.end(), '1');

		if (opp == n) {
			s1 = s2;

			if (s_cnt1 == n) {
				cout << "3" << "\n";
				cout << "1" << " " << n << "\n";
				cout << "1" << " " << n - 1 << "\n";
				cout << n << " " << n << "\n";
			}
			else if (s_cnt1 == 0) {
				cout << "1" << "\n";
				cout << "1" << " " << n << "\n";
			}
			else {

				if (s_cnt1 % 2 == 1) {
					cout << s_cnt1 + 4 << "\n";
					cout << "1" << " " << n << "\n";

					for (ll i = 0; i < n; i++) {
						if (s1[i] == '1')
							cout << i + 1 << " " << i + 1 << "\n";
					}

					cout << "1" << " " << n << "\n";
					cout << "1" << " " << n - 1 << "\n";
					cout << n << " " << n << "\n";
				}
				else {
					cout << s_cnt1 + 1 << "\n";
					cout << "1" << " " << n << "\n";

					for (ll i = 0; i < n; i++) {
						if (s1[i] == '1')
							cout << i + 1 << " " << i + 1 << "\n";
					}
				}
			}
		}
		else {
			if (f_cnt1 == n) {
				cout << "2" << "\n";
				cout << "1" << " " << n - 1 << "\n";
				cout << n << " " << n << "\n";
			}
			else if (f_cnt1 == 0) {
				cout << "0" << "\n";
			}
			else {
				if (f_cnt1 % 2 == 1) {
					cout << f_cnt1 + 3 << "\n";
					for (ll i = 0; i < n; i++) {
						if (s1[i] == '1')
							cout << i + 1 << " " << i + 1 << "\n";
					}

					cout << "1" << " " << n << "\n";
					cout << "1" << " " << n - 1 << "\n";
					cout << n << " " << n << "\n";
				}
				else {
					cout << f_cnt1 << "\n";
					for (ll i = 0; i < n; i++) {
						if (s1[i] == '1')
							cout << i + 1 << " " << i + 1 << "\n";
					}
				}
			}
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

