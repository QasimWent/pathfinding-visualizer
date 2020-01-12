#include "Grid2D.h"
#include <QBrush>
#include <QString>

Grid2D::Grid2D(QObject* parent) : QAbstractTableModel(parent)
{

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
            return m_grid[row][col];
        case Qt::BackgroundRole:
            if (m_grid[row][col] != 0)
            {
               return QBrush(Qt::gray);
            }
            break;
    }
    return QVariant();
}

bool Grid2D::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role == Qt::EditRole)
    {
        m_grid[index.row()][index.column()] = value.toInt();
        QString result;
	    for(int row= 0; row < ROWS; row++)
	    {
            for(int col= 0; col < COLS; col++)
	        {
	            result += m_grid[row][col] + " ";
	        }
        }
    }
    return true;
}

Qt::ItemFlags Grid2D::flags(const QModelIndex &index) const
{
    if (m_grid[index.row()][index.column()] == 0)
    {
        return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    }
    return Qt::ItemIsEnabled;
}