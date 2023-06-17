#include <iostream>
#include <limits>

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

void get_pos(int& x, int &y) {
    std::cin >> x;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    std::cin >> y;

    if (x) {
        --x;
    } 
    if (y) {
        --y;
    }
}


int main() {
    TicBoard board{};

    int x_score{0};
    int y_score{0};

    board.init_board();

    board.in_game = true;

    std::cout << "Tic Tac Toe\n";

    int x{};
    int y{};

    while (board.in_game) {
        std::cout << "\n";

        std::cout << "X choose a tile to place (x, y): ";        
        get_pos(x, y);
        board(x, y, 'X');

        std::cout << board;

        std::cout << "O choose a tile to place (x, y): ";
        get_pos(x, y);
        board(x, y, 'O');

        std::cout << board;

        break;
    }
}