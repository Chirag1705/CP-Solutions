#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

 /* Nice Explaination -> https://www.youtube.com/watch?v=gY-r7L-GVFE */

void solve(){
        ll a, b, x;
        cin >> a >> b >> x;

        if(x > a and x > b){
            cout << "NO" << endl;
            return;
        }

        if(a > b){
            swap(a, b);
        }

        while(a){
            if(a==x or b==x){
                cout << "YES" << endl;
                return;
            }

            if(x > a and x < b and x%a == b%a){
                cout << "YES" << endl;
                return;
            }

            b = b%a;
            swap(a, b);
        }

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