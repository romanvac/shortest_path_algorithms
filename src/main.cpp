#include "graph.hpp"
#include "utils/graph_utils.hpp"
#include "utils/path_utils.hpp"

int main() {
    auto edges = load_graph_from_file("../test_data/large_graph.txt");
    
    int V = get_vertex_count(edges);
    int start = 10000;
    int goal = 9610;
    std::vector<int> dist, prev;

    std::vector<int> result;

    measure_time("Bellman-Ford", [&]() {
        bellman_ford(V, start, edges, dist, prev);
    });
    print_path_info("Bellman-Ford", start, goal, dist, prev);

    measure_time("Dijkstra (simple)", [&]() {
        dijkstra(V, start, edges, dist, prev);
    });
    print_path_info("Dijkstra", start, goal, dist, prev);

    measure_time("Dijkstra (heap)", [&]() {
    dijkstra_heap(V, start, edges, dist, prev);
    });
    print_path_info("Dijkstra (heap)", start, goal, dist, prev);

    auto coords = load_coordinates_from_file("../test_data/a_star_data/coords.txt");
    measure_time("A*", [&]() {
    a_star(V, start, goal, edges, coords, dist, prev);
    });
    print_path_info("A*", start, goal, dist, prev);
    
    std::vector<std::vector<int>> dist_fw, next_fw;

    measure_time("Floyd-Warshall", [&]() {
        floyd_warshall(V, edges, dist_fw, next_fw);
    });
    auto path = reconstruct_fw_path(start, goal, next_fw);
    if (path.empty())
        std::cout << "[Floyd-Warshall] No path from " << start << " to " << goal << "\n";
    else {
        std::cout << "[Floyd-Warshall] Distance: " << dist_fw[start][goal] << ", Path: ";
        for (int v : path) std::cout << v << " ";
        std::cout << "\n";
    }

    return 0;
}