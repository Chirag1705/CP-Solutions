#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
            ll n;
            cin >> n;

            vt<ll>B(n);
            vt<ll>A(n);

            for(ll i = 0; i < n; i++){
                cin >> B[i];
            }

            A[0LL] = B[0LL];
            

            for(ll i = 1; i <= n-1; i++){
                    if(__gcd(B[i], B[i-1]) != B[i]){
                            cout << "-1" << endl;
                            return;
                    }
                    else{
                        A[i] = B[i];
                    }
            }

            for(ll i = 0; i < n; i++){
                cout << A[i] << " ";
            }
            cout << endl;
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