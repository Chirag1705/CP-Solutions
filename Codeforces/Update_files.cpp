#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
        ll n, k;
        cin >> n >> k;
        n--;
        
        ll ans = 0;
        ll current = 1;

        while(n > 0 and current <= k){
            ans++;
            n -= current;
            current = 2*current;
        }

        ans += (n+k-1)/k;

        cout << ans << "\n";

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