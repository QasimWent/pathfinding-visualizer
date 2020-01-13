#include "Node.h"
#include "GridInfo.h"

#include <QDebug>

constexpr size_t rows = GridInfo::rows();
constexpr size_t cols = GridInfo::cols();


void Node::addNeighbours(Node (&grid)[9][9])
{
    if (row < rows - 1)
    {
        neighbours.push_back(grid[row + 1][col]);
    }
    if (row > 0)
    {
        neighbours.push_back(grid[row - 1][col]);
    }
    if (col < cols - 1)
    {
        neighbours.push_back(grid[row][col + 1]);
    }
    if (col > 0)
    {
        neighbours.push_back(grid[row][col - 1]);
    }
}


QDebug operator<<(QDebug out, const Node& node)
{
    out << node.fCost << " " << node.gCost << " " << node.hCost << " (" << node.row << ", " << node.col << ")" << "\n";
    out << "Neighbours: " << "\n";
    for (auto& neighbour: node.neighbours)
    {
        out << "[" << neighbour.row << ", " << neighbour.col << "]\n";
    }
    return out;
}