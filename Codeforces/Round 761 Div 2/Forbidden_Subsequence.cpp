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
        string s, t;

        cin >> s >> t;

        sort(s.begin(), s.end());
        string s1, s2, s3, s4;

        if(t != "abc"){
            cout << s << "\n";
        }
        else{

            bool ok1 = false, ok2 = false, ok3 = false;

            for(ll i = 0; i < s.size(); i++){
                    if(s[i] == 'a'){
                            s1.pb(s[i]);
                            ok1 = true;
                    }
                    else if(s[i] == 'b'){
                            s2.pb(s[i]);
                            ok2 = true;
                    }
                    else if(s[i] == 'c'){
                            s3.pb(s[i]);
                            ok3 = true;
                    }
                    else    
                            s4.pb(s[i]);
            }

            if(!ok1 or !ok2 or !ok3)
                    cout << s << "\n";
            else
            cout << s1 << s3 << s2 << s4 << "\n";
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
