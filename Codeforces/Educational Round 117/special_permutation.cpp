#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll n, a, b;
        cin >> n >> a >> b;

        if((a > (n/2 + 1)) or (b < n/2) or (a <= n/2 and b <= n/2) or (a > n/2 and b > n/2)){
            cout << "-1";
        }
        else{
            cout << a << " ";
            for(ll i = n; i >= 1; i--){
                if( i!= a and i!=b ){
                    cout << i << " ";
                }
            }
            cout << b << " ";
        }

        cout << endl;


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