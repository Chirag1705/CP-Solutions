#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll n, k;
        cin >> n >> k;

        vt<ll>arr(n);
        vt<ll>v;

        cin >> arr[0];
        v.pb(arr[0]);

        for(ll i = 1; i < n; i++){
                cin >> arr[i];

                if(arr[i]!=arr[i-1])
                    v.pb(arr[i]);
        }

        if(k <= 2){
            for(ll i = 0; i < k; i++){
                cout << "0" << " ";
            }
            cout << "\n";
            return;
        }

        if(k==n){
            for(ll i = 0; i < k; i++){
                cout << n-2 << endl;
            }
            cout << "\n";
            return;
        }

        ll p = 1;

        while(p <= k){
                ll cnt = 0, f = 1, b = 0;

                for(ll i = 0; i < v.size(); i++){
                    if(v[i] == p){
                        continue;
                    }

                    if(f){
                        b = v[i];
                        f = 0;
                        continue;
                    }

                    if(b != v[i]){
                        b = v[i];
                        cnt++;
                    }
                }

                p++;
                cout << cnt << " ";
        }
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
    cin>>t;
    while(t--)
    {
     solve();
    }
}