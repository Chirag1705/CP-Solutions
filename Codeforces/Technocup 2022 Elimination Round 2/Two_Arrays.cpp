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
        vt<ll>a(n);
        vt<ll>b(n);

        for(ll i = 0; i < n; i++){
            cin >> a[i];
        }

        for(ll i = 0; i < n; i++){
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());


        for(ll i = 0; i < n; i++){
            if(a[i]!=b[i]){
                a[i] += 1;
            }
        }

        ll cnt = 0;

        for(ll i = 0; i < n; i++){
            if(a[i]==b[i]){
                cnt++;
            }
        }

        if(cnt == n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
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