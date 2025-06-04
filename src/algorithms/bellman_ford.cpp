#include <iostream>
#include <vector>
#include <limits>

#include "graph.hpp"

void bellman_ford(int V, int start, const std::vector<Edge>& edges, std::vector<int>& dist, std::vector<int>& prev) {
    dist.assign(V, INF);
    prev.assign(V, -1);
    dist[start] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const auto& e : edges) {
            if (dist[e.from] < INF && dist[e.from] + e.weight < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.weight;
                prev[e.to] = e.from;
            }
        }
    }
}
