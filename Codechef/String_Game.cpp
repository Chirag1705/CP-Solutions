#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll n;
        cin >> n;
        
        string s;
        cin >> s;
        
        ll count0 = 0, count1 = 0;
        
        for(ll i = 0; i < n; i++){
            if(s[i]=='1'){
                count1++;
            }
            else{
                count0++;
            }
        }
        
       if(min(count1, count0) == 0){
           cout << "BOB" << endl;
           return;
       }
       if(min(count1, count0) == 1){
           cout << "ALICE" << endl;
           return;
       }
       
       if(n%2==1){
           cout << "ALICE" << endl;
       }
       else{
           cout << "BOB" << endl;
       }
        
        
}

int main()
{
    FASTIO;

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll t;
    cin>>t;
    while(t--)
    {
     solve();
    }
}
