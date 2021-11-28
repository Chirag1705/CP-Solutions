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

        vt<ll>a(n), b(n);

        for(ll i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }

        ll l = 1, r = n+1;
        ll mid;

        while(r > l+1){
            mid = (l+r)/2;
            bool ok = false;
            ll j = 0;

            for(ll i = 0; i < n; i++){
                if(b[i] >= j and a[i] >= mid - j - 1){
                        j++;
                }
            }

            if(j >= mid)
                ok = true;

            if(ok){
                l = mid;
            }
            else{
                r = mid;
            }
        }

        cout << l << endl;
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