#include <QBrush>
#include <QThread>
#include <QDebug>
#include <QMutex>
#include <QEventLoop>
#include <QTimer>
#include "Grid2D.h"
#include "GridConfig.h"
#include <cmath>
#include <algorithm>


Grid2D::Grid2D(QObject* parent) : QAbstractTableModel(parent)
{

}

Grid2D::~Grid2D()
{
    delete endNode;
}

int Grid2D::rowCount(const QModelIndex&) const
{
    return GridConfig::getRows();
}

int Grid2D::columnCount(const QModelIndex&) const
{
    return GridConfig::getCols();
}

QVariant Grid2D::data(const QModelIndex& index, int role) const
{
    int row = index.row();
    int col = index.column();

    switch (role)
    {
        case Qt::DisplayRole:
            return "";
        case Qt::BackgroundRole:
            // Paint nodes in shortest path
            for (auto& node: path)
            {
                if (row == node.position.row && col == node.position.col)
                {
                    return QBrush(QColor(52, 152, 219));
                }
            }

            // Paint blocking nodes
            if (grid[row][col] == 1)
            {
                return QBrush(Qt::black);
            }

            // Paint destination node
            if (row == GridConfig::getEndPosition().row && 
                col == GridConfig::getEndPosition().col)
            {
                return QBrush(Qt::gray);
            }

            for (auto& node: openSet)
            {
                if (row == node->position.row && col == node->position.col)
                {
                    return QBrush(QColor(144, 238, 144));
                }
            }

            for (auto& node: closedSet)
            {
                if (row == node->position.row && col == node->position.col)
                {
                    return QBrush(Qt::red);
                }
            }
            
            break;
    }
    return QVariant();
}

int distance(Position p1, Position p2)
{
    int d = (pow(p2.row - p1.row, 2) + pow(p2.col - p1.col, 2));
    return d;
}

void Grid2D::delay(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}

void Grid2D::clearSets()
{
    QModelIndex topLeft = createIndex(GridConfig::getStartPosition().row, 
                                      GridConfig::getStartPosition().col);
    QModelIndex bottomRight = createIndex(GridConfig::getEndPosition().row, 
                                          GridConfig::getEndPosition().col);
    for (auto p: closedSet)
    {
        delete p;
    }
    closedSet.clear();
    openSet.clear();
    emit dataChanged(topLeft, bottomRight, {Qt::BackgroundRole});
}

void Grid2D::aStar()
{
    QModelIndex topLeft = createIndex(GridConfig::getStartPosition().row, 
                                      GridConfig::getStartPosition().col);
    QModelIndex bottomRight = createIndex(GridConfig::getEndPosition().row, 
                                          GridConfig::getEndPosition().col);

    QVector<Node*> neighbours;

    while (openSet.size() != 0)
    {
        Node* currentNode = new Node();
        currentNode = openSet[0];

        int currentIndex = 0;

        for (decltype(openSet.size()) i = 0; i != openSet.size(); ++i)
        {
            if (openSet[i]->fCost < currentNode->fCost)
            {
                currentNode = openSet[i];
                currentIndex = i;
            }
        }

        openSet.erase(openSet.begin() + currentIndex);
        emit dataChanged(topLeft, bottomRight, {Qt::BackgroundRole});
        delay(100);

        closedSet.push_back(currentNode);
        emit dataChanged(topLeft, bottomRight, {Qt::BackgroundRole});
        delay(100);

        if (*currentNode == *endNode)
        {
            Node* node = currentNode;
            while (node != nullptr)
            {
                path.push_back(*node);
                emit dataChanged(topLeft, bottomRight, {Qt::BackgroundRole});
                delay(100);

                node = node->parent;
            }
            std::reverse(path.begin(), path.end());
            for (auto& node: path)
            {
                qDebug() << "(" << node.position.row << ", " << node.position.col
                       << ")";
            }
            clearSets();
            return;
        }

        Position adjacentPositions[] = {
            {0, -1}, {0, 1}, {-1, 0}, {1, 0}, 
            {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
        };

        neighbours.clear();
        for (auto& position: adjacentPositions)
        {
            Position neighbourPosition = {currentNode->position.row + position.row, currentNode->position.col + position.col};

            // Make sure neighbour is in the range (not out of boundaries of grid)
            if (neighbourPosition.row > GridConfig::getRows()-1 || neighbourPosition.row < 0 ||
                neighbourPosition.col > GridConfig::getCols()-1 || neighbourPosition.col < 0)
            {
                continue;
            }

            // Ensure node is not wall (block from traversal)
            if (grid[neighbourPosition.row][neighbourPosition.col] != 0)
            {
                continue;
            }

            // Create the neighbour nod
            Node* neighbourNode = new Node(neighbourPosition, currentNode);

            neighbours.push_back(neighbourNode);
        }

        for (auto& neighbour: neighbours)
        {
            for (auto& closedNode: closedSet)
            {
                if (neighbour == closedNode)
                {
                    continue;
                }
            }

            neighbour->gCost = currentNode->gCost + 1;
            neighbour->hCost = distance(endNode->position, neighbour->position);
            neighbour->fCost = neighbour->gCost + neighbour->hCost;

            for (auto& openNode: openSet)
            {
                if (neighbour == openNode && neighbour->gCost > openNode->gCost)
                {
                    continue;
                }
            }

            openSet.push_back(neighbour);
            emit dataChanged(topLeft, bottomRight, {Qt::BackgroundRole});
        }
    }
}  
