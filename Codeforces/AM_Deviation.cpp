#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        vt<ll>arr(3);

        for(ll i=0; i < 3; i++){
                cin >> arr[i];
        } 

        if((arr[0]+arr[1]+arr[2])%3==0){
            cout << "0" << endl;
        }
        else{
            cout << "1" << endl;
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