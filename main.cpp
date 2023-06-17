#include <iostream>

class TicBoard {
    private:
        char m_board[3][3]{};

    public:
        // constructor
        TicBoard() = default;

        // forward declarations
        char& operator()(int row, int col);

        // friend functions
        friend std::ostream& operator<<(std::ostream& out, const TicBoard& board);

        void init_board() {
            for (auto& row : m_board) {
                for (auto& column : row) {
                    column = '.';
                }
            }
        }

};

char& TicBoard::operator()(int row, int col) {
    return m_board[row][col];
}

std::ostream& operator<<(std::ostream& out, const TicBoard& board) {
    for (auto& row : board.m_board) {
        for (auto& column : row) {
            out << column;
        }
        out << '\n';
    }
    return out;
}

struct Player {
    // either an 'X' or an 'O'
    char side{};
    // unsigned as the player will never be in negetive points
    unsigned int points{};
};




int main() {
    TicBoard board{};

    Player x{'X', 0};
    Player o{'O', 0};

    board.init_board();

    std::cout << board(1, 1);
}