////////////////////////////////////////////////////////////////////////////////
// Floyd Warshall - All pairs shortest paths
////////////////////////////////////////////////////////////////////////////////
#define INF INT_MAX // From climits.h, LLONG_MAX or ULLONG_MAX for 64bit ints
int W[N][N]; // Diagonals should be zero, unconnected should be high value (INF)
// Notes: 1 time we had to run it twice?
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
