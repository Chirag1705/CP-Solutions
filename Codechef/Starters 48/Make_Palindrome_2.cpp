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
	    
	    string s;
	    cin >> s;
	    
	    ll cnt1 = 0, cnt0 = 0;
	    
	    for(ll i = 0; i < s.size(); i++){
	        if(s[i] == '0')
	            cnt0++;
	       else
	        cnt1++;
	    }
	    
	    	        string s1;

	    if(cnt1 >= cnt0){
	        
	        while(cnt1--)
	            s1 += '1';
	    }
	    else{
	        while(cnt0--)
	            s1 += '0';
	    }
	    
	    cout << s1 << "\n";
	}
	return 0;
}
