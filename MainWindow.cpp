#include <QTableView>
#include <QPushButton>
#include "MainWindow.h"
#include "Grid2D.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
{
    QVBoxLayout* vbox = new QVBoxLayout();
    QHBoxLayout* hbox = new QHBoxLayout();

    tableView = new QTableView(this);
    QAbstractTableModel* myModel = new Grid2D();
    tableView->setModel(myModel);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QPushButton* traverseBtn = new QPushButton("Traverse", this);

    hbox->addWidget(traverseBtn, 1, Qt::AlignRight);

    vbox->addWidget(tableView);
    vbox->addSpacing(10);
    vbox->addLayout(hbox);

    setLayout(vbox);
} 