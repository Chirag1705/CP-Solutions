#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        
        string s;
        cin >> s;

        ll n = s.size();
        ll ans = n;

        for(ll i = 0; i < n; i++){
            for(ll j = i+1; j < n; j++){
                ll number = (s[i] - '0')*10 + (s[j] - '0');
                if(number%25==0){
                    ans = min(ans, (j-i-1)+(n-1-j));
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