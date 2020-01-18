#include "Node.h"

bool Node::operator==(const Node& rhs) const
{
    if (this->position == rhs.position)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node& Node::operator=(const Node& rhs)
{
    gCost = rhs.gCost;
    hCost = rhs.hCost;
    fCost = rhs.fCost;

    position = rhs.position;
    if (rhs.parent != nullptr)
    {
        parent = new Node();
        *parent = *(rhs.parent);
    }

    return *this;
}
