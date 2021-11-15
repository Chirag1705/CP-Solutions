#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

const string subseqs[] = {"00", "25", "50", "75"};

ll answer(string&s1, string&s2){
		ll n = s1.size()-1;

		ll ans = 0;
		

		while(n  >= 0 and s1[n] != s2[1]){
			n--;
			ans++;
		}

		if(n < 0) return s1.size();
		n--;

		while(n  >= 0 and s1[n] != s2[0]){
			n--;
			ans++;
		}

			return n < 0 ? s1.size() : ans;


}

void solve(){
		string s;
		cin >> s;

		ll n = s.size();
		ll ans = n;

		for(auto e: subseqs)
			ans = min(ans, answer(s, e));

			cout << ans << endl;
}

int main()
{
    FASTIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
     solve();
    }
}