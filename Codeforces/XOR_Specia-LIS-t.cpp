#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;

    ll arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bool ok = false;

    if(n%2==0){
        ok = true;
    }


    

    for(int i = 0; i < n-1; i++){
        if(arr[i] >= arr[i+1])
                ok = true;
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