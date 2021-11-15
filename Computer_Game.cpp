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

    string s[2];
    
    bool ok = true;


    for(ll i = 0; i < 2; i++){
        cin >> s[i];
    }

    for(ll i = 1; i < n; i++){
            if(s[0][i] == '1' and s[1][i] == '1' ){
                ok = false;
                break;
            }
    }


    if(ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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