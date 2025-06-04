#include "utils/graph_utils.hpp"

std::vector<Edge> load_graph_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Failed to open graph file");

    int V, E;
    file >> V >> E;
    std::vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        file >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    return edges;
}

std::vector<Coord> load_coordinates_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Failed to open coordinate file");

    std::vector<Coord> coords;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int x, y;
        if (iss >> x >> y) {
            coords.push_back({x, y});
        }
    }
    return coords;
}

int get_vertex_count(const std::vector<Edge>& edges) {
    int max_vertex = 0;
    for (const auto& e : edges) {
        max_vertex = std::max({max_vertex, e.from, e.to});
    }
    return max_vertex + 1;
}