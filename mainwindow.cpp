#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSpinBox>
#include <QSplitter>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "starting application";

    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);

    // Left side (Matrix input widget)
    QWidget *leftWidget = new QWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(leftWidget);
    matrixInputWidget = new MatrixInputWidget(this);

    QLabel *label = new QLabel("Matrix size: ", this);


    QPushButton *calculateButton = new QPushButton("Calculate Determinant", this);

    leftLayout->addWidget(matrixInputWidget);
    leftLayout->addWidget(label);
    leftLayout->addWidget(calculateButton);

    // Right side (Results widget)
    QWidget *rightWidget = new QWidget(this);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);
    resultsWidget = new ResultsWidget(this);
    rightLayout->addWidget(resultsWidget);

    splitter->addWidget(leftWidget);
    splitter->addWidget(rightWidget);

    mainLayout->addWidget(splitter);

    splitter->setStyleSheet("QSplitter::handle { background-color: #b0b0b0; }");

    qDebug() << "initiated every widget. waiting for user actions...";

    connect(calculateButton, SIGNAL(clicked()), this, SLOT(onCalculateButtonClicked()));
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::computeDeterminant(){
    QVector<QVector<QLineEdit*>> matrix = matrixInputWidget->getMatrix();
    double determinant = matrixInputWidget->readValuesAndFindDeterminant(matrix, matrixInputWidget->getSize());
    resultsWidget->setDeterminant(determinant);
}

void MainWindow::onCalculateButtonClicked() {
    computeDeterminant();
}
