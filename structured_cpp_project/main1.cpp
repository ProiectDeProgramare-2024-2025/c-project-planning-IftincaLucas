#include "ui.hpp"
#include <iostream>

int main() {
    int option;
    do {
        std::cout << "\nMAIN MENU (main1):\n";
        std::cout << "1. New Match\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
            case 1: new_match(); break;
            case 0: std::cout << "Exiting main1...\n"; break;
            default: std::cout << "Invalid choice.\n"; break;
        }
    } while (option != 0);

    return 0;
}



//g++ -std=c++17 -Iinclude main1.cpp src/ui.cpp src/utils.cpp src/match.cpp src/player.cpp -o main1