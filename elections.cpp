#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll a, b, c;
        cin >> a >> b >> c;

        ll a1 = max(a, max(b, c) + 1);
    // or we can do max(0, max(b, c) + 1 - a)
        cout << a1 - a << " ";

        ll a2 = max(b , max(c, a) + 1);
        cout << a2 - b << " ";

        ll a3 = max(c, max(a, b) + 1);
        cout << a3 - c << endl;
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