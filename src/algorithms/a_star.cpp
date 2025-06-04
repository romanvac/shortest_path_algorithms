#include <queue>
#include <cmath>
#include <limits>

#include "graph.hpp"

double heuristic(const Coord& a, const Coord& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

void a_star(int V, int start, int goal, const std::vector<Edge>& edges,
            const std::vector<Coord>& coordinates, std::vector<int>& dist, std::vector<int>& prev) {
    std::vector<std::vector<std::pair<int, int>>> adj(V);
    for (const auto& e : edges) {
        adj[e.from].emplace_back(e.to, e.weight);
    }

    dist.assign(V, INF);
    prev.assign(V, -1);
    dist[start] = 0;

    using P = std::pair<double, int>; // (f_score, vertex)
    std::priority_queue<P, std::vector<P>, std::greater<P>> open_set;
    open_set.push({heuristic(coordinates[start], coordinates[goal]), start});

    std::vector<double> f_score(V, INF);
    f_score[start] = heuristic(coordinates[start], coordinates[goal]);

    while (!open_set.empty()) {
        auto [f, u] = open_set.top(); open_set.pop();

        if (u == goal) return;

        for (auto [v, w] : adj[u]) {
            int tentative_g = dist[u] + w;
            if (tentative_g < dist[v]) {
                dist[v] = tentative_g;
                prev[v] = u;
                double f_new = tentative_g + heuristic(coordinates[v], coordinates[goal]);
                f_score[v] = f_new;
                open_set.push({f_new, v});
            }
        }
    }
}

