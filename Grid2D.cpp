#include "Grid2D.h"
#include <QBrush>
#include <QString>
#include <QDebug>

Grid2D::Grid2D(QObject* parent) : QAbstractTableModel(parent)
{
    // Initialize all nodes in grid
    for (size_t i = 0; i != ROWS; ++i)
    {
        for (size_t j = 0; j != COLS; ++j)
        {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].addNeighbours(grid);
            qDebug() << grid[i][j];
        }
    }
}

int Grid2D::rowCount(const QModelIndex&) const
{
    return ROWS;
}

int Grid2D::columnCount(const QModelIndex&) const
{
    return COLS;
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
            for (auto& node: openSet)
            {
                if (row == node.row && col == node.col)
                {
                    return QBrush(Qt::green);
                }
            }
            break;
    }
    return QVariant();
}

void Grid2D::aStar()
{
    // TODO - Implement a* algorithm
}