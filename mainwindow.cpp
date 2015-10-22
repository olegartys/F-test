#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QDebug>
#include <iostream>
#include <QChildEvent>
#include <QMessageBox>
#include "fishertablemodel.h"
#include "dragarea.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {

    ui->setupUi(this);

    setWindowIcon(QIcon("/home/olegartys/F-test/icon.ico"));

    area1 = new DragArea(this, "Drag'n'drop\nfile with the\nfirst\nselection");
    area2 = new DragArea(this, "Drag'n'drop\nfile with the\nsecond\nselection");

    ui->horizontalLayout->addWidget(area1);
    ui->horizontalLayout->addWidget(area2);

    ui->fisherTableView->setModel(new FisherTableModel());

    // Stretching table headers
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(area1, SIGNAL(success(QString)), this, SLOT(readSelection1File(QString)));
    connect(area2, SIGNAL(success(QString)), this, SLOT(readSelection2File(QString)));
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
}

void MainWindow::showInfo() {
    double fMeasured = std::max(selection1->getDispersion(), selection2->getDispersion())/
                       std::min(selection1->getDispersion(), selection2->getDispersion());

    double fTable = table.get(std::max(selection1->getElementsCount()-1, selection2->getElementsCount()-1),
                              std::min(selection1->getElementsCount()-1, selection2->getElementsCount()-1));

    QString result;
    if (fMeasured < fTable)
        result = "Selections are equal.";
    else
        result = "Selections are different.";

    QMessageBox::information(this, "Info", QString("F(measured)=%1\nF(table)=%2\n%3")
                             .arg(fMeasured)
                             .arg(fTable)
                             .arg(result));
}

void MainWindow::showAbout() {
    QMessageBox::about(this, "About", "This utility will help you to make F-test for two selections with p=0.05.");
}

void MainWindow::readSelection1File(QString s) {
    QFile f(s);
    if (f.open(QIODevice::ReadOnly)) {
        selection1 = new Selection(&f);
        fillTable(1);

        if (area1->isActive() && area2->isActive()) {
            showInfo();
        }

    } else
        qDebug() << f.errorString();
}

void MainWindow::readSelection2File(QString s) {
    QFile f(s);
    if (f.open(QIODevice::ReadOnly)) {
        selection2 = new Selection(&f);
        fillTable(2);
        if (area1->isActive() && area2->isActive()) {
            showInfo();
        }
    } else
        qDebug() << f.errorString();
}

void MainWindow::fillTable(int selectionNumber) {
    auto* selection = selectionNumber == 1 ? selection1 : selection2;

    auto* item = new QTableWidgetItem(QString::number(selection->getAverage()));
    ui->tableWidget->setItem(0, selectionNumber-1, item);

    item = new QTableWidgetItem(QString::number(selection->getElementsCount()));
    ui->tableWidget->setItem(1, selectionNumber-1, item);

    item = new QTableWidgetItem(QString::number(selection->getDispersion()));
    ui->tableWidget->setItem(2, selectionNumber-1, item);

    item = new QTableWidgetItem(QString::number(selection->getElementsCount()-1));
    ui->tableWidget->setItem(3, selectionNumber-1, item);
}

MainWindow::~MainWindow() {
    delete ui;
}
