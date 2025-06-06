#include "player.hpp"
#include <algorithm>

Player::Player(std::string n) : name(n), wins(0), matches(0) {}

void Player::incrementWins() { wins++; }
void Player::incrementMatches() { matches++; }

int Player::findIndex(const std::vector<Player>& players, const std::string& name) {
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i].name == name) return i;
    }
    return -1;
}

void Player::sortByWins(std::vector<Player>& players) {
    std::sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.wins > b.wins;
    });
}

void Player::sortByMatches(std::vector<Player>& players) {
    std::sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.matches > b.matches;
    });
}

std::vector<Player> Player::generateFromMatches(const std::vector<Match>& matches) {
    std::vector<Player> players;
    for (const auto& m : matches) {
        int idx1 = findIndex(players, m.pl1_name);
        int idx2 = findIndex(players, m.pl2_name);

        if (idx1 == -1) {
            players.push_back(Player(m.pl1_name));
            idx1 = players.size() - 1;
        }
        if (idx2 == -1) {
            players.push_back(Player(m.pl2_name));
            idx2 = players.size() - 1;
        }

        players[idx1].incrementMatches();
        players[idx2].incrementMatches();

        if (m.pl1_score > m.pl2_score && m.pl1_score == 21) players[idx1].incrementWins();
        else if (m.pl2_score > m.pl1_score && m.pl2_score == 21) players[idx2].incrementWins();
    }
    return players;
}
