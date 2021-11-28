#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

ll solve2(vt<ll>& arr){
    vt<ll>b;
    ll ele = 0;

        for(ll i = 0; i < arr.size(); i++){
            if(arr[i] != arr[arr.size()-i-1]){
                ele = arr[i];
                break;
            }
        }

        for(auto x : arr){
                if(x != ele){
                    b.push_back(x);
                }
        }

        

        for(ll i = 0; i < b.size(); i++){
            if(b[i] != b[b.size() - i - 1]){
                return false;
            }
        }
        return true;
}

void solve(){
        ll n;
        cin >> n;

        vt<ll>arr(n);
        

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        bool ans = solve2(arr);

        if(!ans){
            reverse(arr.begin(), arr.end());
            ans = solve2(arr);
        }

        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;


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