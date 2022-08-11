#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define all(x) (x).begin(),(x).end()
#define ss second
#define ff first
template<typename T, typename T1>T amax(T &a, T1 b) {if (b > a)a = b; return a;}
template<typename T, typename T1>T amin(T &a, T1 b) {if (b < a)a = b; return a;}

struct segtree
{
	ll siz;
	vector<ll> v;
	ll NEUTRAL_ELEMENT = INT_MIN;
	void init(ll n)
	{
		siz = 1;
		while (siz < n) siz *= 2;
		v.resize(2 * siz, 0);
	}

	void build(vector<ll>&a, ll x, ll lx, ll rx)
	{
		if (rx - lx == 1)
		{
			if (lx < a.size()) v[x] = a[lx];
			return;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		v[x] = max(v[2 * x + 1], v[2 * x + 2]);
	}

	void build(vector<ll> &a)
	{
		build(a, 0, 0, siz);
	}

	void set(ll i, ll val, ll x, ll lx, ll rx)
	{
		if (rx - lx == 1)
		{
			v[x] = val;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m) set(i, val, 2 * x + 1, lx, m);
		else set(i, val , 2 * x + 2 , m, rx);
		v[x] = max(v[2 * x + 1], v[2 * x + 2]);
	}

	void  set(ll i, ll x)
	{
		set(i, x, 0, 0, siz);
	}

	ll calc(ll l, ll r, ll x, ll lx, ll rx)
	{
		if (lx >= r || rx <= l) return NEUTRAL_ELEMENT;
		if (lx >= l && rx <= r) return v[x];
		ll m = (lx + rx) / 2;
		ll s1 = calc(l, r, 2 * x + 1, lx, m);
		ll s2 = calc(l, r, 2 * x + 2, m, rx);
		return max(s1, s2);
	}

	ll calc(ll l, ll r)
	{
		return calc(l, r, 0, 0, siz);
	}
};

int main()
{
	FASTIO;
	ll n, m;
	cin >> n >> m;
	vector<ll> a(m);
	for (ll i = 0; i < m; i++) cin >> a[i];
	segtree st;
	st.init(m);
	st.build(a);
	ll q;
	cin >> q;
	for (ll i = 0; i < q; i++)
	{
		ll x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		x1--;
		x2--;
		y1--;
		y2--;
		ll temp = min(y1, y2);
		y2 = max(y1, y2);
		y1 = temp;

		ll h = st.calc(y1, y2 + 1);
		// cout<<y1<<" "<<y2<<" " <<h<<"\n";
		ll h1 = (x1 + 1) + k * ((n - x1 - 1) / k);
		if (h >= h1)
		{
			cout << "NO\n";
		}
		else
		{
			if (abs(x1 - x2) % k != 0 || abs(y1 - y2) % k != 0) cout << "NO\n";
			else cout << "YES\n";
		}
	}

}
