#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7
 
void solve(){
        ll n, m;
        cin >> n >> m;
 
        if(n == 1 and m == 1){
            cout << "0" << endl;
            return;
        }
 
        if(n == 1 or m == 1){
            cout << "1" << endl;
            return;
        }
 
        cout << "2" << endl;
        
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
