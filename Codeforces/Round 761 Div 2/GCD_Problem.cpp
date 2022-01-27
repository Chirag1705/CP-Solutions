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

        // (x*c + y*c + c) = n
        // c*(x + y + 1) = n
        // (x+y+1) = n/c

        // observation put c = 1, it will work everytime

       if(n%2==0){
           // n -> even, n-1 -> odd, c = 1 and a = n-1/2 so b = n - 1 - (n-1)/2
           cout << (n-1)/2 << " " << n - (n-1)/2 - 1 << " " << 1 << "\n";
       }
       else{
           // n -> odd, n-1 -> even, c = 1
           // Two cases: if (n-1)/2 -> even , so a = (n-1)/2 - 1 and b = (n-1)/2 + 1
           // 2nd case : if (n-1)/2 -> odd , as o e o e o, multiple of 4, thus gcd can't be 3
           // so a = (n-1)/2 - 2 and b = (n-1)/2 + 2

           if(((n-1)/2)%2==0){
               cout << (n-1)/2 - 1 << " " << (n-1)/2 + 1 << " " << 1 << "\n";
           }
           else{
               cout << (n-1)/2 - 2 << " " << (n-1)/2 + 2 << " " << 1 << "\n";
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