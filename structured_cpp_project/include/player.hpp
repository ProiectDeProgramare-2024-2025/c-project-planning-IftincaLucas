#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "match.hpp"

class Player {
public:
    std::string name;
    int wins = 0;
    int matches = 0;

    Player(std::string n = "");
    void incrementWins();
    void incrementMatches();
    void loadStatsFromMatches(const std::vector<Match>& matches);

    static int findIndex(const std::vector<Player>& players, const std::string& name);
    static void sortByWins(std::vector<Player>& players);
    static void sortByMatches(std::vector<Player>& players);
    static std::vector<Player> generateFromMatches(const std::vector<Match>& matches);
};

#endif


