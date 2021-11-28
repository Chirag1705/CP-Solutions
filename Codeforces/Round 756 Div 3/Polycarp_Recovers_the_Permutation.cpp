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

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        if(n==1){
            cout << arr[0] << endl;
            return;
        }

        if(arr[0] != n and arr[n-1] != n){
            cout << "-1" << endl;
            return;
        }
        else{
            for(ll i = n-1; i >= 0; i--){
                cout << arr[i] << " ";
            }
        }
            cout << endl;
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