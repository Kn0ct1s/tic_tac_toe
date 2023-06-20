#ifndef TIC_BOARD_H
#define TIC_BOARD_H

#include <iostream>

struct Player {
    // this should either be an X or an O
    char piece{};
    int points{};
};

/************************************************************************
 # TicBoard: This class will be responsable for everything to do with   #
 #           the game board. These are things like making the board     #
 #           and placing pieces on the board. Aswell as checking if the #
 #           games has been won                                         #
 ************************************************************************/
class TicBoard {
    private:
        // the board is a 3x3 grid
        char m_board[3][3]{};
    
    public:
        // set the dots on the board to start with
        TicBoard() {
            init_board();
        }

        // Forward declartsions
        void init_board();
        void place_piece(const Player& player);

        bool game_won(Player& player);

        // friend functions
        friend std::ostream& operator<<(std::ostream& out, const TicBoard& board);

};
#endif