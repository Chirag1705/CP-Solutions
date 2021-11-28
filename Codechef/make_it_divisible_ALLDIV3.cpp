#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll n;
        cin >> n;

        vt<ll>arr(n);
        map<ll, ll>m;

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        for(ll i = 0; i < n; i++){
            m[arr[i]%3]++;
        }

        ll ans = 0;
        ans += min(m[1], m[2]);
        m[1] = m[1] - ans;
        m[2] = m[2] - ans;

        if(m[1]>0){
            if(m[1]%3==0){
                ans += 2*(m[1]/3);
            }
            else{
                ans = -1;
            }
        }
        else{
            if(m[2]%3==0){
                ans += 2*(m[2]/3);
            }
            else{
                ans = -1;
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