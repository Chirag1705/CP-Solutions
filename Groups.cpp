#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
        ll n;
        cin >> n;

        ll v[n][5];

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 5; j++){
                cin >> v[i][j];
            }
        }

        bool ok = false;

        for(ll i = 0; i < 5; i++){
            for(ll j = 0; j < 5; j++){
                if(i!=j){
                ll cnt1 = 0, cnt2 = 0, c = 0;
                for(ll k = 0; k < n; k++){
                        if(v[k][i]==1)
                            cnt1++;
                        if(v[k][j]==1)
                            cnt2++;
                        if(v[k][j]==0 and v[k][i]==0)
                            c++;
                }
                if(cnt1 >= n/2 and cnt2 >= n/2 and c == 0){
                    ok = true;
                    break;
                }
            }
        }
            if(ok)
                break;
        }

        if(ok)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;

    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}