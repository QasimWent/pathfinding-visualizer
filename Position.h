#ifndef POSITION
#define POSITION

struct Position
{
    int row;
    int col;

    Position() = default;
    Position(int r, int c) : row(r), col(c) {}

    bool operator==(const Position& rhs) const
    {
        if (this->row == rhs.row && this->col == rhs.col)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif