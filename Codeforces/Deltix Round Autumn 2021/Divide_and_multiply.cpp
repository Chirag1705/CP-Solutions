#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7
#define mod 1e9 + 7


ll mod_mul(ll a, ll b, ll m = mod){
    a = a%m;
    b = b%m;

    return (((a * b) % m) + m) % m;
}

ll modulo(ll a, ll b, ll n = mod){
    ll x=1, y=a; 
    while (b > 0) {
        if (b%2 == 1) {
            x = (x*y) % n; // multiplying with base
        }
        y = (y*y) % n; // squaring the base
        b /= 2;
    }
    return x % n;
}

void solve(){
    //     ll n;
    //     cin >> n;

    //     vt<ll>arr(n);

    //     for(ll i = 0; i < n; i++){
    //         cin >> arr[i];
    //     }

    //    ll s=1,A=0;
    //    ll y = 0;

	// 	for(ll i = 0;i<n;i++)
	// 	{
	// 		while(arr[i]%2==0)
	// 			s*=2,arr[i]/=2;
	// 		y=max(y,arr[i]),A+=arr[i];
	// 	}
	// 	cout<<A+(s-1)*y<<'\n';

    ll n;
    cin >> n;

    vt<ll>arr(n);

    for(ll i = 0; i < n; i++){
            cin >> arr[i];
    }

    ll vec = 0;

    for(ll i = 0; i < n; i++){
        while(arr[i]%2==0){
            arr[i] /= 2;
            vec++;
        }
    }

    ll ans = 0;

    sort(arr.begin(), arr.end());

    for(ll i = 0; i < vec; i++){
        arr.back() *= 2;
    }

    for(ll i = 0; i < n; i++){
        ans += arr[i];
    }

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
