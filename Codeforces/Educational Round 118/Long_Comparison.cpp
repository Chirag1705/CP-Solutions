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
         string x1, x2;
         ll p1, p2;

        cin >> x1 >> p1;
        cin >> x2 >> p2;

        while(x1.length() > 0 and x1.back() == '0'){
            x1.pop_back();
            p1++;
        }
        while(x2.length() > 0 and x2.back() == '0'){
            x2.pop_back();
            p2++;
        }

        ll ans1 = x1.size() + p1;
        ll ans2 = x2.size() + p2;

        if(ans1 > ans2){
            cout << ">" << "\n";
        }
        else if(ans1 < ans2){
            cout << "<" << "\n";
        }
        else{
            if(x1 > x2){
                cout << ">" << "\n";
            }
            else if(x1 < x2){
                cout << "<" << "\n";
            }
            else{
                cout << "=" << "\n";
            }
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