#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

ll computeTotient(ll n){
      ll phi[n+1];
      
      for(ll i = 0; i<=n; i++){
            phi[i] = i;
      }
      
      for(ll p = 2; p <= n; p++){
            if(phi[p] == p){
                phi[p] = p-1;
                
                for(ll i = 2*p; i <= n; i+=p){
                      phi[i] = (phi[i]/p) * (p-1);
                }
            }
      }

      return phi[n];
}

void solve(){
        
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
        ll n;
        cin >> n;

        ll sum = n*n - n;
     ll ans = computeTotient(sum);

     cout << ans << endl;
    }
}

// Approach 2

/* Directly use gcd as it is user defined function
Check for coprime with n, if yes then increase the count

int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

*/
