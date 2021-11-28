#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

ll cnt1(string& s1){
    ll cnt = 0;
    for(ll i = 0; i < s1.size(); i++){
        if(s1[i] == '1')
            cnt++;
    }
    return cnt;
}

bool cmp(string& s1, string& s2){
        ll cnts1 = cnt1(s1);
        ll cnts2 = cnt1(s2);

        return cnts1 < cnts2;
}

void solve(){

        ll n, m;
        cin >> n >> m;

        vt<string>v(n);

        for(ll i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end(), cmp);
        
        ll ans = 0, ones = 0;

        for(ll i = 0; i < n; i++){
            string s = v[i];
                for(ll i = 0; i < m; i++){
                        if(s[i]=='1'){
                            ones++;
                        }
                        else{
                            ans += ones;
                        }
                }
        }

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