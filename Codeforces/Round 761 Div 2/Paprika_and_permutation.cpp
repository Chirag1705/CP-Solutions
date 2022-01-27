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

        set<ll>s;

        vt<ll>rem;

        for(ll i = 1; i <= n; i++)
                s.insert(i);

        for(ll i = 0; i < n; i++){
            ll x;
            cin >> x;

            if(s.count(x))
                    s.erase(x);
            else
                rem.pb(x);
        }

        sort(rem.begin(), rem.end());

        bool verdict = true;
        ll ans = 0;

        for(ll i = 0; i < rem.size(); i++){
                ll index = rem[i];

                ll max_pos = (index-1)/2;

                auto it = s.begin();
                ll pos = *it;

                if(pos > max_pos){
                    verdict = false;
                    break;
                }
                else{
                    s.erase(pos);
                    ans++;
                }
        }

        if(!verdict)
            cout << "-1" << "\n";
        else
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