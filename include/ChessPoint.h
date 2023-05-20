struct ChessPoint
{
    int x, y;

    ChessPoint(int _x, int _y) : x(_x), y(_y) {}

    friend bool operator==(const ChessPoint& p1, const ChessPoint& p2);

    friend bool operator!=(const ChessPoint& p1, const ChessPoint& p2);

    friend ChessPoint operator+(const ChessPoint& p1, const ChessPoint& p2);
};