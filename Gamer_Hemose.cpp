#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll n, h;
        cin >> n >> h;

        vector<ll>arr(n);

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        ll ans;
        ll x = arr[n-1], y = arr[n-2];

        if(h%(x+y) == 0){
            ans = 2*(h/(x+y));
        }

        else if(h%(x+y) <= x){
            ans = 2*(h/(x+y)) + 1;
        }

        else{
            ans = 2*(h/(x+y)) + 2;
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