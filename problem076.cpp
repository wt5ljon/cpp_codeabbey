// Problem 76: Pawn Move Validator
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

const int boardSpaces{ 64 };

void print(char* board, std::ostringstream& out) {
    out << "  +-----------------+\n";
    for (int i{ 0 }; i < boardSpaces; ++i) {
        int row{ i/8 + 1 };
        if (i % 8 == 0)
            out << row << " | ";
        out << board[i] << ' ';
        if (i % 8 == 7)
            out << "|\n";
    } 
    out << "  +-----------------+\n";
    out << "    a b c d e f g h\n";
}

void resetBoard(char* board) {
    // set up a new board
    int blackPieces[8]{ 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r' };
    int whitePieces[8]{ 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };
    for (int i{ 0 }; i < boardSpaces; ++i) {
        if (i <= 7)
            board[i] = blackPieces[i];
        else if (i >= 8 && i <= 15)
            board[i] = 'p';
        else if (i >= 48 && i <= 55)
            board[i] = 'P';
        else if (i >= 56 && i <= 63)
            board[i] = whitePieces[i - 56];
        else
            board[i] = '-';
    }
}

int convertToIndex(const std::string& pos) {
    return (8*(8-static_cast<int>(pos[1]-'0')))+static_cast<int>(pos[0]-'a');
}

char getPiece(char* board, const std::string& pos) {
    return board[convertToIndex(pos)];
}

bool checkPawnMove(char* board, const std::string& from, const std::string& to) {
    char fromPiece{ getPiece(board, from) };
    int fromIndex{ convertToIndex(from) };
    int distance{};
    std::string str{};
    if (fromPiece == 'P') {
        // handle white pawn 'P'
        distance = convertToIndex(from) - convertToIndex(to);
        // check for move two spaces ahead
        if (fromIndex >= 48 && fromIndex <= 55 && distance == 16 && board[fromIndex-8] == '-' && board[fromIndex-16] == '-')
            return true;
        // check for move one space ahead
        if (distance == 8 && board[fromIndex-8] == '-')
            return true;
        str = "prnbqk";
        // check for capture diagonal to right
        if (distance == 7 && fromIndex % 8 != 7 && str.find(getPiece(board, to)) != std::string::npos)
            return true;
        // check for capture diagonal to left
        if (distance == 9 && fromIndex % 8 != 0 && str.find(getPiece(board, to)) != std::string::npos)
            return true;
    } else {
        // handle black pawn 'p'
        distance = convertToIndex(to) - convertToIndex(from);
        // check for move two spaces ahead
        if (fromIndex >= 8 && fromIndex <= 15 && distance == 16 && board[fromIndex+8] == '-' && board[fromIndex+16] == '-')
            return true;
        // check for move one space ahead
        if (distance == 8 && board[fromIndex+8] == '-')
            return true;
        str = "PRNBQK";
        // check for capture diagonal to right
        if (distance == 7 && fromIndex % 8 != 7 && str.find(getPiece(board, to)) != std::string::npos)
            return true;
        // check for capture diagonal to left
        if (distance == 9 && fromIndex % 8 != 0 && str.find(getPiece(board, to)) != std::string::npos)
            return true;
    }
    return false;
}

int main() {
    char board[boardSpaces];
    
    int testcases{};
    std::cin >> testcases;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ostringstream out{};
    std::string line{};
    for (int testcase{ 0 }; testcase < testcases; ++testcase) {
        resetBoard(board);
        getline(std::cin, line);
        std::istringstream in{ line };
        
        std::string move{};
        int moveCount{ 0 };
        bool validMove{ true };
        while (in >> move) {
            ++moveCount;
            std::string from{ move.substr(0,2) };
            std::string to{ move.substr(2,2) };
            char chessPiece{ getPiece(board, from) };
            if (chessPiece == 'P' || chessPiece == 'p' ) {
                validMove = checkPawnMove(board, from, to);
                if (!validMove)
                    break;    
            }
            // move piece
            board[convertToIndex(to)] = board[convertToIndex(from)];
            board[convertToIndex(from)] = '-';
        }
        if (validMove)
            out << "0 ";
        else
            out << moveCount << ' ';
    }

    std::cout << out.str() << '\n';

    return 0;
}