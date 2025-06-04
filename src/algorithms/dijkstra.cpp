#include "graph.hpp"

void dijkstra(int V, int start, const std::vector<Edge>& edges, std::vector<int>& dist, std::vector<int>& prev) {
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    for (const auto& e : edges) {
        adj[e.from].emplace_back(e.to, e.weight);
    }

    dist.assign(V, INF);
    prev.assign(V, -1);
    std::vector<bool> visited(V, false);
    dist[start] = 0;

    for (int i = 0; i < V; ++i) {
        int u = -1;
        for (int j = 0; j < V; ++j)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;

        if (dist[u] == INF)
            break;
        visited[u] = true;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
        }
    }
}
