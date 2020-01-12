#ifndef GRID2D_H
#define GRID2D_H

#include <QAbstractTableModel>

const size_t COLS = 9;
const size_t ROWS = 9;

class Grid2D : public QAbstractTableModel
{
    Q_OBJECT

public:
    Grid2D(QObject* parent = nullptr);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override; 
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    
private:
    int m_grid[ROWS][COLS] = {0};
};

#endif 