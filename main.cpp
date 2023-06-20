#include <iostream>
#include <limits>

#include "TicBoard.h"

int main() {
    TicBoard board{};
    
    // both players
    Player x{'X', 0};
    Player o{'O', 0};

    while (true) {
        std::cout << "\tTic Tac Toe\n\n";
        std::cout << "X points: " << x.points << "\t" << "O points: " << o.points;

        // main game loop
        while (true) {
            std::cout << board;

            board.place_piece(x);
            std::cout << board;
            if (board.game_won(x)) {
                std::cout << "X won!\n\n";
                break;
            }

            board.place_piece(o);
            std::cout << board;
            if (board.game_won(o)) {
                std::cout << "O won!\n\n";
                break;
            }
        }

        // check if they want to play again
        while (true) {
            std::cout << "Play again? (y/n): ";
            char ans{};
            std::cin >> ans;

            switch (ans) {
                case 'y': {
                    board.init_board();
                    break;
                }
                case 'n':
                    std::cout << "\nX Scored: " << x.points << '\n';
                    std::cout << "O Scored: " << o.points << '\n';
                    exit(0);
                default:
                    std::cout << "Invalid input, try again\n\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
            }
            break;
        }
    }
}