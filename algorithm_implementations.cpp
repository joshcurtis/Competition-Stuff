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

////////////////////////////////////////////////////////////////////////////////
// Prim's Algorithm - Minimum Spanning Tree
////////////////////////////////////////////////////////////////////////////////
struct Edge {
    Edge(int dst=0, int w=0, int src=0) : dst(dst), src(src), w(w) {}
    bool operator>(const Edge& other) const {
        return w > other.w;
    }
    int dst, src; // src may be optional
    int w;
};
vector<Edge> graph[N]; // Adjacency list

set<int> S;
priority_queue<Edge, vector<Edge>, greater<Edge> > pq; // need queue and functional
                                                       // greater<Edge> means smallest first
                                                       // I think it's pretty dumb, seems backwards
void enqueue(int node) {
    S.insert(node);
    for (int i=0; i<graph[node].size(); i++) pq.push(graph[node][i]);
}

int prims() {
    int total = 0;
    enqueue(0); // Initial node
    while (S.size() < n) {
        Edge edge = pq.top(); pq.pop();
        if (S.count(edge.dst)>0) continue;
        tot += edge.w;
        enqueue(edge.dst);
    }
    return total;
}
