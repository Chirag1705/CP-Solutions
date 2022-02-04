#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main(){
    ll t;
    
    cin >> t;
    
    while(t--){
        ll n, k;
        cin >> n >> k;
        
        bool ok = false;
        
        if(((n%2 == 1) and ((n/2)+1 >= k)) or ((n%2 == 0) and ((n/2) >= k))){
            
                ok = true;
        }
        
        char ch[41][41];
        
        for(ll i = 1; i <=n ; i++){
            for(ll j = 1; j <=n; j++){
                ch[i][j] = '.';
            }
        }
        
        ll x = 1;
        
        while(k--){
            ch[x][x] = 'R';
            x += 2;
        }
        
        if(ok){
            for(ll i = 1; i <= n; i++){
                for(ll j = 1; j <= n; j++){
                    cout << ch[i][j] << "";
                }
                cout << "\n";
            }
        }
        else{
            cout << "-1" << "\n";
        }
    }
    
    
    
}
