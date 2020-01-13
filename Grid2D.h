#ifndef GRID2D_H
#define GRID2D_H

#include <QAbstractTableModel>
#include <QVector>
#include "Node.h"
#include "GridInfo.h"

constexpr size_t ROWS = GridInfo::rows();
constexpr size_t COLS = GridInfo::rows();

class Grid2D : public QAbstractTableModel
{
    Q_OBJECT

public:
    Grid2D(QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override; 
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    void aStar();
    
private:
    mutable Node grid[ROWS][COLS];
    Node start{0, 0};
    Node end{ROWS-1, COLS-1};
    QVector<Node> openSet = {start};
    QVector<Node> closedSet;
};

#endif 