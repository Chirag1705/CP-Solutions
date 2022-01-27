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
        vt< pair <ll,ll> > v(n);

        for(ll i = 0; i < n; i++){
            cin >> v[i].first;
            v[i].second = i;
        }

        sort(v.begin(), v.end());

        ll x0 = 0;

        ll sum = 0;

        ll j = 1, k = -1;

        for(ll i = n-1; i >= 0; i--){
            if(i%2==0){
            arr[v[i].second] = x0+j;
                j++;
            }
            else{
            arr[v[i].second] = x0+k;
                k--;
            }
        }

        for(ll i = 0; i < n; i++){
            sum += 2 * abs(x0 - arr[v[i].second]) * v[i].first;
        }

        cout << sum << "\n";

        cout << x0 << " ";


        for(ll i = 0; i < n; i++){
            cout << arr[i] << " ";
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
