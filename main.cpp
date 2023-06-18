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
        bool in_game{false};

        // constructor
        TicBoard() = default;

        // forward declarations
        char& operator()(int row, int col);
        void operator()(int row, int col, char player);

        void place_piece(Player player);
        bool game_won(Player x, Player o);

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

void TicBoard::operator()(int row, int col, char player) {
    m_board[row][col] = player;
}

// REFACTOR
std::ostream& operator<<(std::ostream& out, const TicBoard& board) {
    for (auto& row : board.m_board) {
        for (auto& column : row) {
            out << column << '\t';
        }
        out << '\n';
    }
    return out;
}

void TicBoard::place_piece(Player player) {
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
        } else if (m_board[--x][--y] != '.') {
            std::cout << "invalid position, try again\n\n";
            continue;
        } else {
            m_board[--x][--y] = player.piece;
            break;
        }
    }
}

bool TicBoard::game_won(Player x, Player o) {
    return false;
}


int main() {
    TicBoard board{};
    
    Player x{'x', 0};
    Player o{'o', 0};

    board.init_board();

    board.in_game = true;

    std::cout << "Tic Tac Toe\n";

    while (board.in_game) {
        std::cout << "\n";

        std::cout << board;
        board.place_piece(x);

        std::cout << board;
        board.place_piece(o);

        break;
    }
}