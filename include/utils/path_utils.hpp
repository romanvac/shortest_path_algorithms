#ifndef PATH_UTILS_HPP
#define PATH_UTILS_HPP

#include <vector>
#include <string>
#include <algorithm>

std::vector<int> restore_path(int start, int end, const std::vector<int>& prev);
void print_path_info(const std::string& label, int start, int end, const std::vector<int>& dist, const std::vector<int>& prev);
std::vector<int> reconstruct_fw_path(int u, int v, const std::vector<std::vector<int>>& next);

#endif  // PATH_UTILS_HPP