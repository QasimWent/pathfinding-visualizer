#ifndef MAINWINDOW_H
#define MAINWINDO_H

#include <QtWidgets>
#include "Grid2D.h"

class MainWindow: public QWidget
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = 0);
    ~MainWindow();
    
private:
    QTableView* tableView;
    Grid2D* myModel;

private slots:
    void handleButton();
};

#endif 
