#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
        ll n, l, r, k;
        cin >> n >> l >> r >> k;

        vt<ll>arr(n);

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        ll sum = 0;
        ll count = 0;


        for(ll i = 0; i < n; i++){
            if(arr[i] >= l and arr[i] <= r and sum+arr[i]<=k){
                sum += arr[i];
                count++;
            }
        }

        cout << count << "\n";
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