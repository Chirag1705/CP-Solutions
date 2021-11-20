#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

ll fact(ll n)
{
   ll res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

ll nCr(ll n, ll r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// or
/* int ncr(int n, int r) 
{
    int ans = 1;
    for (int i = 1; i <= r; i += 1)
    {
        ans *= (n - r + i);
        ans /= i;
    }
    return ans;
} */

void solve(){
        ll n, k;
        cin >> n >> k;

         if(n==1){
            cout<<1<<endl;
            return;
        }

        if(k==1){
            cout << n << endl;
            return;
        }

        ll ans = nCr(n+k-1, n-1);

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
