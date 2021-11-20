
#include <bits/stdc++.h>
#define ll int
using namespace std;

int main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n=1000000;
	long long phi[n+1];
	for (int i=1; i<=n; i++)
		phi[i] = i; // indicates not evaluated yet
					// and initializes for product
					// formula.

	// Compute other Phi values
	for (int p=2; p<=n; p++)
	{
		// If phi[p] is not computed already,
		// then number p is prime
		if (phi[p] == p)
		{
			// Phi of a prime number p is
			// always equal to p-1.
			phi[p] = p-1;

			// Update phi values of all
			// multiples of p
			for (int i = 2*p; i<=n; i += p)
			{
			// Add contribution of p to its
			// multiple i by multiplying with
			// (1 - 1/p)
			phi[i] = (phi[i]/p) * (p-1);
			}
		}
	}

	// Print precomputed phi values
	ll arr[1000009];
	
	for (int i=1; i<=n; i++)
	arr[i]=phi[i] ;
    int t;
    cin>>t;
    v:
    while(t--)
    {
    ll q;
    cin >> q;
    q=q*q-q;
    if (q<=1)
    cout<<"0\n";
    else
cout<<arr[q]<<"\n";
}
}

// Approach 2

/* Directly use gcd as it is user defined function
Check for coprime with n, if yes then increase the count

int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}

*/
