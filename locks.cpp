#include <iostream>
using namespace std;

inline double factorial( int m, int end )
{
	// Initialize return value
	double ret = 1.0;

	// Do: m * (m-1) * (m-2) * ... * (end + 1)
	for( int i = m; i > end; --i )
	{
		ret *= i;
	}

	// Return
	return ret;
}

long long combination( int m, int n )
{
	// Combination formula is: m! / n!(m-n)!

	// If (m-n) is bigger
	if( (m - n) > n )
	{
		// Do (m * (m-1) * ... * (m - n + 1)) / (n!)
		return factorial( m, m - n ) / factorial( n, 0 );
	}
	// If n is bigger or the same as (m-n)
	else
	{
		// Do (m * (m-1) * ... * (n + 1) / (m - n)!
		return factorial( m, n ) / factorial( m - n, 0 );
	}
}

int main()
{
	// Read the number of cases
	int numCases;
	cin >> numCases;
	
	// For each, calculate
	for( int i = 0; i < numCases; ++i )
	{
		int x, y;
		cin >> x >> y;
		cout << combination( x, y - 1 ) << endl;
	}

	// Return
	return 0;
}
