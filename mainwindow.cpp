#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSpinBox>
#include <QSplitter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    //create main horizontal
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    //left side
    matrixInputWidget = new MatrixInputWidget(this);
    mainLayout->addWidget(matrixInputWidget);

    //right side
    resultsWidget = new ResultsWidget(this);
    mainLayout->addWidget(resultsWidget);

    //make them even
    //mainLayout->setStretch(0,1);
    //mainLayout->setStretch(1,1);

    QSplitter *splitter = new QSplitter(Qt::Horizontal);
    splitter->addWidget(matrixInputWidget);
    splitter->addWidget(resultsWidget);
    mainLayout->addWidget(splitter);

    splitter->setStyleSheet("QSplitter::handle { background-color: #b0b0b0; }");


    //setCentralWidget(splitter);

}

MainWindow::~MainWindow()
{
    delete ui;
}
