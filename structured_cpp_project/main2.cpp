#include "ui.hpp"
#include <iostream>

int main() {
    int option;
    do {
        std::cout << "\nMAIN MENU (main2):\n";
        std::cout << "2. Player Stats\n";
        std::cout << "3. Leaderboard\n";
        std::cout << "4. View All Matches\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
            case 2: players_info(); break;
            case 3: submenu(); break;
            case 4: view_matches(); break;
            case 0: std::cout << "Exiting main2...\n"; break;
            default: std::cout << "Invalid choice.\n"; break;
        }
    } while (option != 0);

    return 0;
}
