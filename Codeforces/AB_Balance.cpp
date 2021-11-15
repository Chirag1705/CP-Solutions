#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
   string s;
   cin >> s;

   ll count = 0, count2 = 0;
    

   for(int i = 0; i < s.size(); i++){
       if(s[i] == 'a' and s[i+1] == 'b')
            count++;

        if(s[i] == 'b' and s[i+1] == 'a')
            count2++;
   }

        if(count == count2){
            cout << s << "\n";
        }
    
    else if(count > count2){
            ll index = s.find('a');
            s[index] = 'b';
            cout << s << "\n";
    }

    else{
            ll index = s.find('b');
            s[index] = 'a';
            cout << s << "\n";
    }


        
}

int main(){
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int t;
     cin >> t;

     while(t--){
         solve();
     }

    return 0;
}