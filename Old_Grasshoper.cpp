#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll x, n;
    cin >> x >> n;

    ll rem = n%4;
    ll q = n/4;
    ll ans = 0;

    

        if(x%2==0){
            if(rem==0)
                ans = x ;
            else if(rem==1)
                ans = x + -(1+4*q);
            else if(rem==2)
                ans = x + 1;
            else
                ans = x + 4*(1+q);
        }
        else{
            if(rem==0)
                ans = x ;
            else if(rem==1)
                ans = x + (1+4*q);
            else if(rem==2)
                ans = x - 1;
            else
                ans = x - 4*(1+q);
        }
        
    

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

     ll t;
     cin >> t;

     while(t--){
         solve();
     }

    return 0;
}