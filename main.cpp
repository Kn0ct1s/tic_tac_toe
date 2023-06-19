#include <iostream>
#include <limits>

struct Player {
    char piece{};
    int points{};
};

class TicBoard {
    private:
        char m_board[3][3]{};

    public:

        // constructor
        TicBoard() = default;

        // forward declarations
        void place_piece(const Player& player);
        bool game_won(Player& player);

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

void TicBoard::place_piece(const Player& player) {
    // for holding spot to place piece
    int x{};
    int y{};
    while (true) {
        std::cout << player.piece << " choose where to place peice (x, y): ";
        std::cin >> x;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        std::cin >> y;

        if (x <= 0 || x >= 4 || y <= 0 || y >= 4) {
            std::cout << "invalid range, please enter number between 1 & 3\n\n";
            continue;
        } else if (m_board[x - 1][y - 1] != '.') {
            std::cout << "invalid position, try again\n\n";
            continue;
        } else {
            m_board[--x][--y] = player.piece;
            break;
        }
    }
}

bool TicBoard::game_won(Player& player) {
    // check horizontal
    for (int row{ 0 }, col{ 1 }; row < 3; ++row) {
        if (m_board[row][col] == player.piece && m_board[row][col - 1] == player.piece &&
            m_board[row][col + 1] == player.piece) {
                ++player.points;
                return true;
        }
    }

    // check vertical
    for (int row { 1 }, col{ 0 }; col < 3; ++col) {
        if (m_board[row][col] == player.piece && m_board[row - 1][col] == player.piece &&
            m_board[row + 1][col] == player.piece) {
                ++player.points;
                return true;
            }
    }

    // check diagonal
    int row{ 1 };
    int col{ 1 };
    if (m_board[row][col] == player.piece &&
        m_board[row - 1][col - 1] == player.piece &&
        m_board[row + 1][col + 1] == player.piece) {
            ++player.points;
            return true;
    } else if (m_board[row][col] == player.piece &&
            m_board[row + 1][col - 1] == player.piece &&
            m_board[row - 1][col + 1] == player.piece) {
                ++player.points;
                return true;
            }

    return false;
}

std::ostream& operator<<(std::ostream& out, const TicBoard& board) {
    out << '\n';
    for (auto& row : board.m_board) {
        out << "---------------------\n";
        for (auto& column : row) {
            out << "| " << column << " |" << '\t';
        }
        out << '\n';
    }
    out << "---------------------\n";
    return out;
}

int main() {
    TicBoard board{};
    
    Player x{'X', 0};
    Player o{'O', 0};

    board.init_board();

    while (true) {
        std::cout << "\tTic Tac Toe\n\n";
        std::cout << "X points: " << x.points << "\t" << "O points: " << o.points;

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
                    std::cout << "X Scored: " << x.points << '\n';
                    std::cout << "O Scored: " << o.points << '\n';
                    exit(0);
            }
            break;
        }
    }
}