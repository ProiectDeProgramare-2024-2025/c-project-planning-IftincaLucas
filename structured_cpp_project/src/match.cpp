#include "match.hpp"
#include <fstream>
#include <sstream>

Match::Match(std::string p1, int s1, std::string p2, int s2)
    : pl1_name(p1), pl1_score(s1), pl2_name(p2), pl2_score(s2) {}

bool Match::isValid() const {
    return (pl1_score == 21 && pl2_score < 21) || (pl2_score == 21 && pl1_score < 21);
}

void Match::writeToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);
    if (!file) throw std::runtime_error("Could not open file.");
    file << pl1_name << "," << pl1_score << "," << pl2_name << "," << pl2_score << "\n";
}

std::vector<Match> Match::readAll(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Could not open file.");
    std::vector<Match> matches;
    std::string p1, p2;
    int s1, s2;
    while (file >> std::ws && std::getline(file, p1, ',') && file >> s1 && file.get() && std::getline(file, p2, ',') && file >> s2) {
        matches.emplace_back(p1, s1, p2, s2);
    }
    return matches;
}

