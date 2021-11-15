#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;
    ll arr[n];

    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    ll curr = 0;
    ll ans = arr[0];

    for(ll i = 0; i < n; i++){
        arr[i] -= curr;

        ans = max(ans, arr[i]);

        curr += arr[i];
    }

    cout << ans << endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     ll t;
     cin >> t;

     while(t--){
         solve();
     }

    return 0;
}