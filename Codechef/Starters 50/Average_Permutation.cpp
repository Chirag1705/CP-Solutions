#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	ll t;
	cin >> t;
	
	while(t--){
	    ll n;
	    cin >> n;
	    
	   if(n%2 == 0){
	       ll i = n, j = 1;
	    while(i >= 2){
	        cout << i << " ";
	        i -= 2;
	    }
	    
	    while(j <= n-1){
	        cout << j << " ";
	        j += 2;
	    }
	   }
	   else{
	       ll i = n, j = 2;
	       while(i >= 1){
	        cout << i << " ";
	        i -= 2;
	    }
	    
	    while(j <= n-1){
	        cout << j << " ";
	        j += 2;
	    }
	   }
	   cout << "\n";
	}
	return 0;
}
