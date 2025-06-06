#include "utils.hpp"
#include <algorithm>
#include <cctype>

bool valid_name(const std::string& name) {
    return !name.empty() && std::all_of(name.begin(), name.end(), ::isalpha);
}

bool valid_score(int score) {
    return score >= 0 && score <= 21;
}
