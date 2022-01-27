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
        ll n;
        cin >> n;

        vt<ll>arr(n);

        vt<ll>first, second;

        for(ll i = 0; i < n; i++){
                cin >> arr[i];

                if(i%2==0)
                    first.pb(arr[i]);
                else    
                    second.pb(arr[i]);
        }

        ll val1 = 0;

        for(ll i = 0; i < first.size(); i++){
                val1 = __gcd(val1, first[i]);
        }

        ll val2 = 0;

        for(ll i = 0; i < second.size(); i++){
                val2 = __gcd(val2, second[i]);
        }

        bool ans1 = true, ans2 = true;

        for(ll i = 0; i < first.size(); i++){
                    if(first[i]%val2==0){
                        ans1 = false;
                    }
        }

        for(ll i = 0; i < second.size(); i++){
                    if(second[i]%val1==0){
                        ans2 = false;
                    }
        }

        if(!ans1 and !ans2)
            cout << "0" << "\n";
        else if(!ans1)
            cout << val1 << "\n";
        else    
            cout << val2 << "\n";
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