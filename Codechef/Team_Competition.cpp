#include <iostream>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin >> t;
	
	while(t--){
	   string s;
	   cin >> s;
	   
	   ll A = 0, B = 0, C = 0, D = 0;
	   
	   for(ll i = 0; i < s.size(); i++){
	       if(s[i]=='A'){
	           A++;
	       }
	       else if(s[i]=='B'){
	           B++;
	       }
	       else if(s[i]=='C'){
	           C++;
	       }
	       else{
	           D++;
	       }
	   }
	   
	   if(A >= max(B, max(C, D)))
	        cout << "A" << " ";
	   if(B >= max(C, max(D, A)))
	        cout << "B" << " ";
	   if(C >= max(D, max(A, B)))
	        cout << "C" << " ";
	   if(D >= max(A, max(B, C)))
	        cout << "D" << " ";
	        
	        cout << endl;

	}
	
	
	return 0;
}

/* K = A
if(K < B) K = B
if(K < C) K = C
if(K < D) K = D

if(K == A) cout << A
if(K == B) cout << B
if(K == C) cout << C
if(K == D) cout << D
*/ 
