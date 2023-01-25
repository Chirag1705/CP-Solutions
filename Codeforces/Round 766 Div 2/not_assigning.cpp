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

void dfs(int node, vt<ll>&vis, vt<ll>&vec, vt<vt<ll>>&adj) {
	vec.pb(node);
	vis[node] = 1;

	for (auto i : adj[node]) {
		if (!vis[i])
			dfs(i, vis, vec, adj);
	}

}

void solve() {
	ll n;
	cin >> n;

	vt<vt<ll>>adj(n);
	vt<ll>deg(n);
	vt<ll>ans(n - 1);
	map<pair<ll, ll>, ll>m;

	for (ll i = 0; i < n - 1; i++) {
		ll x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
		deg[x]++;
		deg[y]++;
		m[ {x, y}] = i;
		m[ {y, x}] = i;
	}

	for (auto i : deg) {
		if (i >= 3) {
			cout << "-1" << "\n";
			return;
		}
	}

	ll tmp = 0;

	for (ll i = 0; i < n; i++) {
		if (deg[i] == 1) {
			tmp = i;
			break;
		}
	}

	vt<ll>vec, vis(n, 0);

	dfs(tmp, vis, vec, adj);

	// for (auto i : vec)
	// 	cout << i << " ";
	// cout << "\n";
	ll vr = 2;

	for (ll i = 0; i < sz(vec) - 1; i++) {
		ans[m[ {vec[i], vec[i + 1]}]] = vr;
		if (vr == 2)
			vr = 3;
		else
			vr = 2;
	}

	for (auto i : ans)
		cout << i << " ";
	cout << "\n";
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