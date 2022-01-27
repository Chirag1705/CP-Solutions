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
        ll n, a, b;
        cin >> n >> a >> b;

        vt<ll>arr(n+1);

        if(abs(a-b)>1 || (a+b)>n-2){
	cout<<"-1"<<endl;
	return;
}

        for(ll i = 1; i < n+1; i++){
             arr[i] = i;
        }
        

        if(b>a){int i=1;
while(b--){swap(arr[i],arr[i+1]);
i+=2;}}
 
 
 
 
else if(a>b){int j=n;
while(a--){swap(arr[j],arr[j-1]);
j-=2;
}
}


else{int i=2;
while(a--){swap(arr[i],arr[i+1]);
i+=2;
}
}
        

        for(ll i = 1; i < n+1; i++){
            cout << arr[i] << " ";
        }

        cout << "\n";


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
