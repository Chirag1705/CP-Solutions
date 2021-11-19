1st Approach :

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
      
      if(n%2)
        n++;
       
      if(n>6)
         cout << 5 * n/2 << endl;
      else
         cout << "15" << endl;
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


2nd Approach :

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
      
      ll x = 0, y = 0, z = 0;
      
      if(n <= 6)
          x = 1;
          
      else if(n%10==9){
          z = n/10;
          z = z+1;
      }
      
      else if(n%10==8){
          z = n/10;
          y = 1;
      }
      
      else if(n%10==7){
          z = n/10;
          y = 1;
      }
      
      else if(n%10 == 6){
          z = n/10;
          x = 1;
      }
      
      else if(n%10 == 5){
          z = n/10;
          x = 1;
      }
      
      else if(n%10 == 4){
          n = n-14;
          z = n/10;
          x = 1;
          y = 1;
      }
      
      else if(n %10 ==3)
	    {
	        n=n-13;
	        z=n/10;
	        x=1;
	        y=1;
	    }
      
	     else if(n %10 ==2)
	    {
	        n=n-12;
	        z=n/10;
	        x=2;
	       
	    }
      
	    else if(n %10 ==1)
	    {
	        n=n-11;
	        z=n/10;
	        x=2;
	    }
      
	     else if(n %10 ==0)
	    {
	        z=n/10;
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
