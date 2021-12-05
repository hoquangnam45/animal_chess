#pragma once
class ChessPosition {
    public:
        int m_row;
        int m_col;
        explicit ChessPosition(int row = -1, int col = -1);
        bool operator==(const ChessPosition& b) const = default;
        bool operator!=(const ChessPosition& b) const = default;
        ~ChessPosition();
};
