////////////////////////////////////////////////////////////////////////////////
// Combinatorics
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// N-Choose-R / Pascals Triangle
// Runtime: O(n^2) initialize, O(1) get solution
// Usage: Call initNCR();
//        Access solution with nCr[n][r];
// Notes: Works for n up to 66 on ull
////////////////////////////////////////////////////////////////////
typedef unsigned long long ull;
ull nCr[68][68]; // Answer stored here
void initNCR() {
  for (int i=0; i<68; i++) {
    nCr[i][i] = 1;
    nCr[i][0] = 1;
  }
  for (int i=2; i<68; i++) {
    for (int j=1; j<i; j++) {
      nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
    }
  }
}

////////////////////////////////////////////////////////////////////
// Factorial
// Runtime: O(n) initialize, O(1) get solution
// Usage: Call initFact();
//        Access solution with fact[n];
// Notes: Works for n up to 20 on uint64
//        Works for n up to 12 on uint32
////////////////////////////////////////////////////////////////////
typedef unsigned long long ull;
ull fact[21]; // Answer stored here
void initFact() {
  fact[0] = 1;
  for (int i=1; i<21; i++)
    fact[i] = fact[i-1] * i;
}

////////////////////////////////////////////////////////////////////////////////
// Graphs
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
// Floyd Warshall - All pairs shortest paths
// Runtime: O(n^3) to get all pairs shortest path, O(1) to access
// Usage: Set MAX_N to the maximum number of nodes
//        Set N to number of nodes in graph
//        Fill in adjacency matrix
//        Call floydWarshall();
//        Access with W[src][dst];
// Notes: Diagonals should be 0, unconnected should be INF
//        We had to run this twice once?
////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <climits>
using namespace std;
#define INF INT_MAX
#define MAX_N // Fill in
int N;
int W[MAX_N][MAX_N];
void reset() { // Optional helper
  for (int i=0; i<MAX_N; i++) {
    fill(W[i], W[i]+MAX_N, INT_MAX);
    W[i][i] = 0;
  }
}

void floydWarshall() {
    for (int k=0; k<N; k++) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (W[i][k]==INF || W[k][j]==INF) continue;
                W[i][j] = min(W[i][j], W[i][k]+W[k][j]);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
// Strings
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
// Knuth Morris Pratt - Searches for string w in string s (of length k)
// Runtime: O(k)
// Usage: int ans = KMP(s, w)
//        If w in s, then returns index in s that starts w, else s.length()
////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
using namespace std;

typedef vector<int> vi;
void initKMP(string& w, vi& t)
{
  t = vi(w.length());
  int i = 2, j = 0;
  t[0] = -1; t[1] = 0;
  while(i < w.length()) {
    if(w[i-1] == w[j]) {
      t[i] = j+1; i++; j++;
    } else if(j > 0) {
      j = t[j];
    } else {
      t[i] = 0; i++;
    }
  }
}

int KMP(string& s, string& w)
{
  int m = 0, i = 0;
  vi t;
  initKMP(w, t);
  while(m+i < s.length()) {
    if(w[i] == s[m+i]) {
      i++;
      if(i == w.length()) return m;
    } else {
      m += i-t[i];
      if(i > 0) i = t[i];
    }
  }
  return s.length();
}
