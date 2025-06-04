#ifndef GRAP_UTILS_HPP
#define GRAP_UTILS_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "graph.hpp"

std::vector<Edge> load_graph_from_file(const std::string& filename);
std::vector<Coord> load_coordinates_from_file(const std::string& filename);
int get_vertex_count(const std::vector<Edge>& edges);

template<typename Func>
void measure_time(const std::string& label, Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << label << " took " << duration.count() << " [microsec]\n";
}


#endif  // GRAP_UTILS_HPP