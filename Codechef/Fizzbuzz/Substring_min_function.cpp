#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

ll tot(ll num){
    return (num*(num+1))/2;
}

void solve(){
        ll n, m;
        cin >> n >> m;

        ll num_zeroes = n - m;

        ll num_parts = m+1;

        ll length = (n - m)/(m+1);

        ll rem_zeroes = num_zeroes - (length * num_parts);

        ll ans = rem_zeroes*tot(length+1) + (num_parts-rem_zeroes)*tot(length);

        cout << ans << "\n";
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