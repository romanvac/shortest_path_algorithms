#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <limits>

const int INF = std::numeric_limits<int>::max();

struct Edge {
    int from, to, weight;
};

struct Coord {
    int x, y;
};

void bellman_ford(int V, int start, const std::vector<Edge>& edges, std::vector<int>& dist, std::vector<int>& prev);
void dijkstra(int V, int start, const std::vector<Edge>& edges, std::vector<int>& dist, std::vector<int>& prev);
void dijkstra_heap(int V, int start, const std::vector<Edge>& edges, std::vector<int>& dist, std::vector<int>& prev);
void a_star(int V, int start, int goal, const std::vector<Edge>& edges,
            const std::vector<Coord>& coordinates, std::vector<int>& dist, std::vector<int>& prev);
void floyd_warshall(int V, const std::vector<Edge>& edges,
                    std::vector<std::vector<int>>& dist,
                    std::vector<std::vector<int>>& next);


#endif  // GRAPH_HPP