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
            ll n, k;
            cin >> n >> k;

            vt<ll>arr(n);

            for(ll i = 0; i < n; i++){
                cin >> arr[i];
            }

            vt<ll>pos;
            vt<ll>neg;

            for(ll i = 0; i < n; i++){
                    if(arr[i]>=0)
                        pos.pb(arr[i]);
                    else
                        neg.pb(arr[i]);
            }

            sort(pos.begin(), pos.end());
            sort(neg.begin(), neg.end());
            reverse(neg.begin(), neg.end());

            ll index = 0;

            vt<ll>ans_vec;

            if(pos.size()>0){
                index = pos.size()-1;
                ans_vec.pb(pos[index]);

                index -= k;

                while(index >= 0){
                    ans_vec.pb(pos[index]);
                    index -= k;
                }
            }

            if(neg.size()>0){
                index = neg.size()-1;
                ans_vec.pb(-neg[index]);

                index -= k;

                while(index >= 0){
                    ans_vec.pb(-neg[index]);
                    index -= k;
                }
            }

            ll ans = 0;

            sort(ans_vec.begin(), ans_vec.end());

            for(ll i = 0; i < ans_vec.size()-1; i++){
                ans += ans_vec[i]*2;
            }

            ans += ans_vec[ans_vec.size()-1];

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