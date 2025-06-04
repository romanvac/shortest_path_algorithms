#include <vector>

#include "graph.hpp"

void floyd_warshall(int V, const std::vector<Edge>& edges,
                    std::vector<std::vector<int>>& dist,
                    std::vector<std::vector<int>>& next) {
    dist.assign(V, std::vector<int>(V, INF));
    next.assign(V, std::vector<int>(V, -1));

    for (int i = 0; i < V; ++i) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    for (const auto& e : edges) {
        dist[e.from][e.to] = std::min(dist[e.from][e.to], e.weight);
        next[e.from][e.to] = e.to;
    }

    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}
