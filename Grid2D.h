#ifndef GRID2D_H
#define GRID2D_H

#include <QAbstractTableModel>
#include <QVector>
#include "Node.h"
#include "GridConfig.h"

class Grid2D : public QAbstractTableModel
{
    Q_OBJECT

public:
    Grid2D(QObject* parent = nullptr);
    ~Grid2D();
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override; 
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    
public slots:
    void aStar();
    
private:
    QVector<QVector<int>> grid = {
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    QVector<Node*> openSet{new Node()};
    QVector<Node*> closedSet;
    QVector<Node> path;
    Node* endNode = new Node(GridConfig::getEndPosition());

    void delay(int millisecondsWait);
    void clearSets();
};

#endif 
