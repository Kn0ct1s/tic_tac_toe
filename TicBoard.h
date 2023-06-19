#ifndef TIC_BOARD_H
#define TIC_BOARD_H

#include <iostream>

struct Player {
    char piece{};
    int points{};
};

class TicBoard {
    private:
        char m_board[3][3]{};
    
    public:
        TicBoard() = default;

        void init_board();
        void place_piece(const Player& player);

        bool game_won(Player& player);

        friend std::ostream& operator<<(std::ostream& out, const TicBoard& board);

};
#endif