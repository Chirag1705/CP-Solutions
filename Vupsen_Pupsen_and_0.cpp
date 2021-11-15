#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n;
    cin >> n;

    vector<ll>v(n+1, 0);
    vector<ll>v1(n+1, 0);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    if(n%2==0){
        for(int i = 1; i <= n; i+=2){
            ll A, B;
            A = v[i];
            B = v[i+1];

            v1[i] = B;
            v1[i+1] = -A;
        }
    }
    
    if(n%2!=0){
        for(int i = 4; i <= n; i+=2){
            ll A, B;
            A = v[i];
            B = v[i+1];

            v1[i] = B;
            v1[i+1] = -A;
        }

        ll A, B, C;
            A = v[1];
            B = v[2];
            C = v[3];

            v1[1] = C;
            v1[2] = C;
            v1[3] = -(A+B);

            if(A+B == 0){
                v1[1] = C;
                v1[2] = -C;
                v1[3] = -2*A;
            }
        
    }

    for(int i = 1; i <= n; i++){
        cout << v1[i] << " ";
    }
    cout << "\n";
    
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