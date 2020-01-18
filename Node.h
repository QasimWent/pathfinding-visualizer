#ifndef NODE_H
#define NODE_H

#include <QVector>
#include <QDebug>
#include "Position.h"

class Node
{
friend class Grid2D;
public:
    Node(int g, int h, int f, Position pos = {0, 0}, Node* par = nullptr) : parent(par), position(pos), gCost(g), hCost(h), fCost(f) {}
    Node(Position pos = {0, 0}, Node* par = nullptr) : parent(par), position(pos) {}
    bool operator==(const Node& rhs) const;
    Node& operator=(const Node& rhs);

private:
    Node* parent;
    Position position;
    int gCost = 0;
    int hCost = 0;
    int fCost = 0;
    std::vector<Node> neighbours;
};

#endif 