#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define vt vector
#define sz(x) int(x.size()) 
#define N 2e5+7

void solve(){
   ll n;cin>>n;
   vt<ll> a(n);
   for(int i=0;i<n;i++) {
       cin>>a[i];
   }
   string s;cin>>s;
   for(int i=0;i<n;i++){
       if(a[i]<0 && s[i]=='B'){
           cout<<"NO"<<endl;return;
       }
       else if(a[i]>n && a[i]=='R'){
           cout<<"NO"<<endl;return;
       }
   }
    vt<ll> blue,red;
    for(int i=0;i<n;i++)
    if(s[i]=='B') blue.pb(a[i]);
    else red.pb(a[i]);
 
    sort(blue.begin(),blue.end());
    sort(red.begin(),red.end());
    ll i=0,j=0;
    ll cnt = 1;
    bool ok = true;
    while(i<blue.size() && j<red.size()){
        if(blue[i]>=cnt) i++;
        else if(red[j]<=cnt)  j++;
        else{
            ok = false;
            break;
        }
        cnt++;
    }
 
    if(ok==false){
        cout<<"NO"<<endl;return;
    }
 
    while(j<red.size()){
        if(red[j]>cnt){
            ok = false; break;
        }
        cnt++;
        j++;
    }
 
    if(ok==false){
        cout<<"NO"<<endl;return;
    }
 
    while(i<blue.size())
    {
        if(blue[i]<cnt) {
            ok = false; break;
        }
        cnt++;
        i++;
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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