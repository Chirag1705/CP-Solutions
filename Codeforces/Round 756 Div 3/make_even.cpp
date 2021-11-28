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
        string s;
        cin >> s;

        ll ans = 0;

        if(s[s.size()-1]%2==0){
            cout << "0" << endl;
            return;
        }
         bool ok = false; 

        for(ll i = 0; i < s.size(); i++){
            if(s[i]%2==0){
                ok = true;
                break;
            }
        }

        if(ok){
        if(s[0]%2==0){
            cout << "1" << endl;
        }
        else{
            cout << "2" << endl;
        }
    }
        else{
            cout << "-1" << endl;
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
