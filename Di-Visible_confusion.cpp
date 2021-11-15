#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
        ll n;
        cin >> n;

        ll arr[n];

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        bool ok = true;
        
        for(ll i = 1; i <= n; i++){
            bool yeah = false;
            for(ll j = i+1; j >= 2; j--){
                if(arr[i-1]%j){
                    yeah = true;
                    break;
                }
            }
            ok &= yeah;
        }

        if(ok)
        cout << "YES" << "\n";
        else
        cout << "NO" << "\n";

}

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

 int t;
 cin >> t;

 while(t--){
     solve();
 }

return 0;
}