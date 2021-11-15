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

    string s1;
    cin >> s1;

    if(is_sorted(s1.begin(), s1.end())){
        cout << "0" << endl;
        return;
    }
    else{
        cout << "1" << endl;
    }

    string s2 = s1;

    vt<ll>arr;

    sort(s2.begin(), s2.end());

    for(ll i = 0; i < n; i++){
        if(s1[i]!=s2[i])
            arr.push_back(i+1);
    }
        cout << arr.size() << " ";

        for(ll i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
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