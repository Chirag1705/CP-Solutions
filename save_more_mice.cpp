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

        vt<ll>v(k);

        for(ll i = 0; i < k; i++){
                cin >> v[i];
        }

        sort(v.begin(), v.end());

        ll l = 0, j = k-1, r = v[j];
        ll count = 0;

        while(l < r){
            ll a = n - r;
            count++;
            j--;

            if(j < 0)
                break;

            l += a;
            r = v[j];
            
        }

        cout << count << endl;
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