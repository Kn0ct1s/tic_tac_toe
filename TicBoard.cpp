#include <iostream>
#include <limits>

#include "TicBoard.h"

/********************************************************
 # init_board: This function puts a dot on each         #
 #             part of the board                        #
 ********************************************************/
void TicBoard::init_board() {
    for (auto& row: m_board) {
        for (auto& col: row) {
            col = '.';
        }
    }
}

/********************************************************
 # place_piece: This function is responsable for        #
 #              getting user input and making sure that #
 #              it is a valid position on the board     #
 ********************************************************/
void TicBoard::place_piece(const Player& player) {
    // these store the x and y positions
    int x{};
    int y{};

    // use a loop so we can handle invalid input
    while (true) {
        std::cout << player.piece << " choose where to place peice (x, y): ";
        std::cin >> x;
        // ignore the ,
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ',');
        std::cin >> y;
        
        // range check
        if (x <= 0 || x >= 4 || y <= 0 || y >= 4) {
            std::cout << "invalid range, please enter number between 1 & 3\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        // make sure that there isn't already a peice at that position
        } else if (m_board[x - 1][y - 1] != '.') {
            std::cout << "invalid position, try again\n\n";
            continue;
        } else {
            m_board[--x][--y] = player.piece;
            break;
        }
    }   
}

/********************************************************
 # game_won: This function is responsable for checking  #
 #           if there are 3 connecting x/o's.           #
 ********************************************************/
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
    
    // if we get to here, they didn't win
    return false;
}

/********************************************************
 # This is just responsable for how to print the board  #
 ********************************************************/
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