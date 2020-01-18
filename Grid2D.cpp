#include <QBrush>
#include "Grid2D.h"
#include "GridConfig.h"


Grid2D::Grid2D(QObject* parent) : QAbstractTableModel(parent)
{
    
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
            if (grid[row][col] == 1)
            {
                return QBrush(Qt::black);
            }
            for (auto& node: openSet)
            {
                if (row == node->position.row && col == node->position.col)
                {
                    return QBrush(Qt::green);
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

void Grid2D::aStar()
{

}  

void Grid2D::changeGrid()
{
    aStar();
}
