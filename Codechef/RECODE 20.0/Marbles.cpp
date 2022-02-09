#include<bits/stdc++.h>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll a, b, x;

        cin >> a >> b >> x;

        ll ans = 1e12;
       
       if(a%2==0){
            if(x/a <= 1){
                cout << "1" << endl;
                return;
            }
            else{
                ans = min(ans, (x/a)+1);
            }
       }

       if(b%2==0){
            if(x/b <= 1){
                cout << "1" << endl;
                return;
            }
            else{
                ans = min(ans, (x/b)+1);
            }
       }

       if(a+b == x){
           ans = min(ans, 2LL);
       }

        if(a%2==0 and b%2==0){
            ans = min(ans, x/(a+b)+2);
        }

        if(a%2!=0 and b%2!=0){
            ans = min(ans, x/(a+b)+2);
        }

        cout << ans << endl;

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
