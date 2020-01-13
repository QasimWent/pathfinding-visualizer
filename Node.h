#ifndef NODE_H
#define NODE_H

#include <QVector>
#include <QDebug>

class Node
{
friend class Grid2D;
friend QDebug operator<<(QDebug out, const Node& node);
public:
    int row = 0;
    int col = 0;
    Node() = default;
    Node(int row, int col) : row(row), col(col) {}
    void addNeighbours(Node (&board)[9][9]);
    bool operator==(const Node& rhs) const
    {
        if (this->row == rhs.row && this->col == rhs.col && 
            this->fCost == rhs.fCost && this->hCost == rhs.hCost && this->gCost == rhs.gCost)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    int fCost = 0;
    int hCost = 0;
    int gCost = 0;
    std::vector<Node> neighbours;
};

QDebug operator<<(QDebug out, const Node& node);

#endif 