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

        string s;
        cin >> s;

        double ans = 0;

        for(ll i = 0; i < n-1; i++){
            if(s[i]!=s[i+1]){
                ans += 0.5;
            }
        }

        cout << ceil(ans) << endl;
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

/* Another Approach ->

#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       
       string s;
       cin>>s;
       
       int count=1;
       
       for(int i=1;i<n;i++)
       {
          if(s[i]!=s[i-1])
          {
             count=count+1;
             
          }
       }
       if(count==1)
       {
          cout<<0<<endl;
       }
       else if(count==2)
       {
           cout<<1<<endl;
       }
       else
       {
       cout<<count/2<<endl;
       }
      
       
    }
return 0;
}

*/

/*  Third Approach ->

#include <iostream>
#include<algorithm>
using namespace std;
#define tt long long
int main() {
	tt t;
	cin>>t;
	while(t--)
	{
	     tt n;
        cin>>n;
       string a;
        cin>>a;
       int b[100]={0};
       
       for(tt i=1;i<n;i++)
        {
         if(a[i]!=a[i-1])
        {
          b[a[i-1]]++;
          
        }
      }
       b[a[n-1]]++;
       cout<<min(b['B'],b['W'])<<"\n";
    	}
	return 0;
}

*/