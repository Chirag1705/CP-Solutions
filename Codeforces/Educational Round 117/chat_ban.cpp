#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7
 /* Explaination -> https://www.youtube.com/watch?v=jp6ZsskrJZI */
void solve(){
        ll k,x;
        cin >> k >> x;

        ll tot = k*k;
        ll ans = 0;
        if(x>=tot){
            cout << 2*k-1 << endl;
            return;
        }
        
            ll l = 1;
            ll r = 2*k - 1;
            while(l <= r){
                    ll mid = (l+r)/2;
                    ll req = 0;

                    if(mid > k){
                        ll diff = mid - k;
                        ll val = k - diff;
                        req = tot - (val*(val+1))/2;
                    }
                    else{
                        req = mid*(mid-1)/2;
                    }

                    if(x > req){
                        ans = mid;
                        l = mid+1;
                    }
                    else{
                        r = mid - 1;
                    }
            }
        

        cout << ans << endl;
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
