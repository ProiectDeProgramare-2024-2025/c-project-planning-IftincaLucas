
#ifndef MATCH_HPP
#define MATCH_HPP

#include <string>
#include <vector>

class Match {
public:
    std::string pl1_name, pl2_name;
    int pl1_score, pl2_score;

    Match(std::string p1 = "", int s1 = 0, std::string p2 = "", int s2 = 0);
    bool isValid() const;
    void writeToFile(const std::string& filename) const;
    static std::vector<Match> readAll(const std::string& filename);
};

#endif
