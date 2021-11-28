#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        
        ll a, b;
        cin >> a >> b;

        if((a+b)%2==1){
            cout << "-1" << " " << "-1" << endl;
        }
        else{
            

            ll x = a/2LL;
            ll y = b/2LL;

            if(a%2==1 and b%2==1){
                    cout << x << " " << y+1 << endl;
            }
            else{
                cout << x << " " << y << endl;
            }

            
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