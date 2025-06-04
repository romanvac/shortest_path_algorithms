#include <queue>

#include "graph.hpp"

void dijkstra_heap(int V, int start, const std::vector<Edge>& edges, std::vector<int>& dist, std::vector<int>& prev) {
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    for (const auto& e : edges) {
        adj[e.from].emplace_back(e.to, e.weight);
    }

    dist.assign(V, INF);
    prev.assign(V, -1);
    dist[start] = 0;

    using P = std::pair<int, int>; // (dist, vertex)
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0, start);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
}