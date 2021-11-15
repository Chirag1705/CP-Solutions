#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}


void solve(){
        ll n;
        cin >> n;

        vector<ll>arr(n);
        ll sum = 0;

        for(ll i  = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        if(!isPrime(sum)){
                cout << n << endl;
                for(ll i = 0; i < n; i++){
                    cout << i+1 << " ";
                }
                cout << endl;
                return;
        }

        ll ind = -1;

        for(ll i = 0; i < n; i++){
            if(arr[i]%2!=0){
                ind = i;
                break;
            }
        }

        for(ll i = 0; i < n; i++){
            cout << n-1 << endl;
            for(ll i = 0; i < n; i++){
                if(i!= ind){
                    cout << i+1 << " ";
                } 
            }
            cout << endl;
            return;
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