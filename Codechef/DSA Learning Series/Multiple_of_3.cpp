#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Youtube -> https://www.youtube.com/watch?v=dga_HStGF3Q&t=8773s
int main() {
        
        ll t;
        cin >> t;
        
        while(t--){
        ll k;
        cin >> k;
        
        ll d1, d2;
        cin >> d1 >> d2;
        
        ll sum_two_num = d1+d2;
    
        
        if (k == 2){
        if (sum_two_num % 3 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    else{
        ll temp = ((2*sum_two_num)%10) + ((4*sum_two_num)%10) + ((8*sum_two_num)%10) + ((6*sum_two_num)%10);
        ll cycles = (k-3)/4;
        ll sum = sum_two_num + (sum_two_num%10) + (temp * 1LL * cycles);
        ll left_over = (k-3) - (cycles*4);
        ll power = 2;
        
        for(ll i = 1; i <= left_over; i++){
            sum += ((power*sum_two_num))%10;
            power = (power*2)%10;
        }
        
        if(sum%3==0){
        cout <<"YES\n";
    }
    else{
        cout << "NO\n";
    }
    }
    
    
        
        }  
        
	return 0;
}
