#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
        
        ll n;
        cin >> n;

        vector<ll>v(n);

        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        ll ans = 0;

        for(int i = 1; i <= n; i++){
            ans = max(ans, v[i-1]-i);
        }

        cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}