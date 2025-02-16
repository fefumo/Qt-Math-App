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

    fileLabel = new QLabel("File Name: ", this);

    QPushButton *calculateButton = new QPushButton("Calculate Determinant", this);

    QPushButton *selectFileButton = new QPushButton("Select File");

    leftLayout->addWidget(matrixInputWidget);
    leftLayout->addWidget(fileLabel);
    leftLayout->addWidget(calculateButton);
    leftLayout->addWidget(selectFileButton);

    // Right side (Results widget)
    QWidget *rightWidget = new QWidget(this);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);
    resultsWidget = new ResultsWidget(this);
    rightLayout->addWidget(resultsWidget);

    splitter->addWidget(leftWidget);
    splitter->addWidget(rightWidget);

    mainLayout->addWidget(splitter);

    splitter->setStyleSheet("QSplitter::handle { background-color: #b0b0b0; }");
    //this->setStyleSheet("background-color: black;");

    qDebug() << "initiated every widget. waiting for user actions...";

    connect(calculateButton, SIGNAL(clicked()), this, SLOT(computeDeterminant()));

    connect(selectFileButton, &QPushButton::clicked, this, &MainWindow::openFileDialog);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::computeDeterminant(){
    QVector<QVector<QLineEdit*>> matrix = matrixInputWidget->getMatrix();
    double determinant = matrixInputWidget->readValuesAndFindDeterminant(matrix, matrixInputWidget->getMatrixSize());
    resultsWidget->setDeterminant(determinant);
}

void MainWindow::onCalculateButtonClicked() {
    computeDeterminant();
}

void MainWindow::openFileDialog()
{
    qDebug() << "Opened file dialog";
    // Open QFileDialog in a separate window for file selection
    selectedFile = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("YAML Files (*.yaml *.yml);;"));

    if (!selectedFile.isEmpty()) {
        // Use MatrixFileHandler to load the matrix
        QVector<QVector<double>> matrixData = matrixFileHandler->loadMatrixFromFile(selectedFile);

        if (matrixData.isEmpty()){
            QMessageBox::critical(this, tr("Matrix"), tr("Matrix is invalid"));
            return;
        }
        // Update the QLabel or QLineEdit with the selected file path
        fileLabel->setText(selectedFile);

        // Optionally, show a message or take any other action
        QMessageBox::information(this, tr("File Loaded"), tr("Matrix loaded successfully from file!"));

        // Update the UI with the loaded matrix data, for example:
        matrixInputWidget->setMatrixValues(matrixData);

    }
}
