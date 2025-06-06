#include <iostream>
#include "match.hpp"
#include "player.hpp"
#include "utils.hpp"
#include "ui.hpp"

// Color macros:
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define PINK    "\033[38;2;255;105;180m"
#define L_BLUE  "\033[38;2;173;216;230m"
#define BLUE    "\033[94m"
#define RESET   "\033[0m"

void header() { std::cout << L_BLUE "\n------------------------\n" RESET; }
void header2() { std::cout << L_BLUE "\n==============================\n" RESET; }
void header3() { std::cout << L_BLUE ".................................\n" RESET; }

void new_match() {
    std::string p1, p2;
    int s1, s2;

    std::cout << "Enter player 1 name:\n";
    std::cin >> p1;
    while (!valid_name(p1)) {
        std::cout << "Invalid name. Try again using only letters!\n";
        std::cin >> p1;
    }

    
    while (true) {
    std::cout << "Enter player 1 score (0-21):\n";
    if (std::cin >> s1) {
        if (valid_score(s1)) break;
        else std::cout << "Score must be between 0 and 21.\n";
    } else {
        std::cout << "Invalid input, please enter a number.\n";
        std::cin.clear();
        // Clear the rest of the line (until newline)
        std::string dummy;
        std::getline(std::cin, dummy);
    }
}


    std::cout << "Enter player 2 name:\n";
    std::cin >> p2;
    while (!valid_name(p2)) {
        std::cout << "Invalid name. Try again using only letters!\n";
        std::cin >> p2;
    }

    
    while (true) {
    std::cout << "Enter player 2 score (0-21):\n";
    if (std::cin >> s2) {
        if (valid_score(s2)) break;
        else std::cout << "Score must be between 0 and 21.\n";
    } else {
        std::cout << "Invalid input, please enter a number.\n";
        std::cin.clear();
        // Clear the rest of the line (until newline)
        std::string dummy;
        std::getline(std::cin, dummy);
    }
}

    Match match(p1, s1, p2, s2);
    while (!match.isValid()) {
        std::cout << RED "\nInvalid score combination. One player must score exactly 21, and the other less.\n" RESET;
        std::cout << "Re-enter scores:\n";
        std::cin >> s1 >> s2;
        match = Match(p1, s1, p2, s2);
    }

    match.writeToFile("match_info.txt");
    std::cout << GREEN "Match saved!" RESET << std::endl;
}

void view_matches() {
    auto matches = Match::readAll("match_info.txt");
    header3();
    std::cout << "Match History:\n\n";
    for (const auto& m : matches) {
        if (m.pl1_score > m.pl2_score)
            std::cout << m.pl1_name << " " << GREEN << m.pl1_score << RESET << " / " << RED << m.pl2_score << RESET << " " << m.pl2_name << "\n";
        else
            std::cout << m.pl1_name << " " << RED << m.pl1_score << RESET << " / " << GREEN << m.pl2_score << RESET << " " << m.pl2_name << "\n";
    }
    header3();
}

void players_info() {
    std::string name;
    std::cout << "\nEnter the name of the player whose statistics you wish to see:\n";
    std::cin >> name;

    auto matches = Match::readAll("match_info.txt");
    int wins = 0, losses = 0, total = 0;

    for (const auto& m : matches) {
        if (m.pl1_name == name) {
            total++;
            if (m.pl1_score > m.pl2_score && m.pl1_score == 21) wins++;
            else losses++;
        } else if (m.pl2_name == name) {
            total++;
            if (m.pl2_score > m.pl1_score && m.pl2_score == 21) wins++;
            else losses++;
        }
    }

    if (total == 0) std::cout << "\nNo matches found for " << name << ".\n";
    else {
        header();
        std::cout << "\nStats for " << name << ":\n";
        std::cout << GREEN "Wins: " << wins << RESET ", " RED "Losses: " << losses << RESET << std::endl;
        std::cout << "Matches played: " << total << std::endl;
        header();
    }
}

void leaderboard_by_wins() {
    auto matches = Match::readAll("match_info.txt");
    auto players = Player::generateFromMatches(matches);
    Player::sortByWins(players);

    header3();
    std::cout << "\nRanking by most wins:\n";
    for (const auto& p : players) {
        std::cout << BLUE << p.name << RESET << " - Wins: " << p.wins << "\n";
    }
    header3();
}

void leaderboard_by_matches() {
    auto matches = Match::readAll("match_info.txt");
    auto players = Player::generateFromMatches(matches);
    Player::sortByMatches(players);

    header3();
    std::cout << "\nRanking by most matches played:\n";
    for (const auto& p : players) {
        std::cout << BLUE << p.name << RESET << " - Matches: " << p.matches << "\n";
    }
    header3();
}

void submenu() {
    int subopt;
    do {
        header2();
        std::cout << "1. Leaderboard by most wins\n";
        std::cout << "2. Leaderboard by most matches played\n";
        std::cout << "0. Back to main menu\n";
        header2();
        std::cout << "\nChoose an option: ";
        std::cin >> subopt;

        switch (subopt) {
            case 1: leaderboard_by_wins(); break;
            case 2: leaderboard_by_matches(); break;
            case 0: std::cout << "Returning to main menu...\n"; break;
            default: std::cout << "Invalid choice!\n"; break;
        }
    } while (subopt != 0);
}

void choice(int option) {
    switch (option) {
        case 1: new_match(); break;
        case 2: players_info(); break;
        case 3: submenu(); break;
        case 4: view_matches(); break;
        case 0: std::cout << "Exiting...\n"; break;
        default: std::cout << "Invalid choice!\n"; break;
    }
}

void main_menu() {
    std::cout << PINK "\nMAIN MENU:\n\n" RESET;
    std::cout << L_BLUE "-----------------------\n" RESET;
    std::cout << "1. New Match\n2. Player Stats\n3. Leaderboard\n4. View All Matches\n0. Exit\n";
    std::cout << L_BLUE "-----------------------\n" RESET;
}
