#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
typedef unsigned long long ull;

/* 
   MAX N = 68 nCr may overflow after this
   If you have to do things like 90 choose 10, use the formula
*/
vector<vector<ull> > buildnCr(int N = 68)
{
    vector<vector<ull> > nCr(N+1, vector<ull>(N+1));
    //Precompute n choose n and n choose 0
    for(int i = 0; i <= N; i++) nCr[i][0] = nCr[i][i] = 1;
    //Use Pascal's identity to build nCr
    for(int n = 1; n <= N; n++)
	for(int r = 1; r <= n; r++)
	    nCr[n][r] = nCr[n-1][r] + nCr[n-1][r-1];
    return nCr;
}

/*
  This is only accurate through about N=62 for some reason.
 */
ull C(int n, int r) {
    ull ans=1;
    // Use the Multiplicative formula to calculate nCr
    for(ull i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}


// Testing
int main()
{
    vector<vector<ull> > ncr = buildnCr();
    for(int n = 1; n <= 62; n++)
	for(int r = 0; r <= n; r++)
	    assert(C(n,r) == ncr[n][r]);
    return 0;
}
