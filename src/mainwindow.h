#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "dragarea.h"
#include "selection.h"
#include "fishertable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void readSelection1File(QString);
    void readSelection2File(QString);
    void showAbout();

private:
    Ui::MainWindow *ui;
    DragArea* area1, *area2;
    FisherTable table;

    Selection* selection1, *selection2;

    void fillTable(int selectionNumber);
    void showInfo();

};

#endif // MAINWINDOW_H
