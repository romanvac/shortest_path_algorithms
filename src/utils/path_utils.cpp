#include <iostream>

#include "utils/path_utils.hpp"

std::vector<int> restore_path(int start, int end, const std::vector<int>& prev) {
    std::vector<int> path;
    for (int v = end; v != -1; v = prev[v])
        path.push_back(v);
    std::reverse(path.begin(), path.end());

    if (path[0] != start) return {}; // unreachable
    return path;
}

void print_path_info(const std::string& label, int start, int end, const std::vector<int>& dist, const std::vector<int>& prev) {
    std::vector<int> path = restore_path(start, end, prev);
    std::cout << label << ":\n";
    if (path.empty()) {
        std::cout << "  No path found.\n";
        return;
    }
    std::cout << "  Path: ";
    for (int v : path) std::cout << v << " ";
    std::cout << "\n  Length: " << dist[end] << "\n\n";
}

std::vector<int> reconstruct_fw_path(int u, int v, const std::vector<std::vector<int>>& next) {
    if (next[u][v] == -1) return {};
    std::vector<int> path = {u};
    while (u != v) {
        u = next[u][v];
        path.push_back(u);
    }
    return path;
}