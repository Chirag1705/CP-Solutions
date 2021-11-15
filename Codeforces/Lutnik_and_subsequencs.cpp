#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    ll count = 0;
    ll arr[n];
    unordered_map<ll, ll> m;
    ll k;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        m[arr[i]]++;
    }

    count += m[1];

    if(m[1]!=0){
        k = (ll)(pow(2, m[0]));
        k--;
    }

    k *= m[1];
    count += k;

    cout << count<< "\n";
    
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