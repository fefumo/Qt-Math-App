#include "matrixinputwidget.h"

MatrixInputWidget::MatrixInputWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // title label
    titleBar = new QLabel("Matrix", this);

    // spinbox for matrix size
    sizeInput = new QSpinBox(this);
    sizeInput->setRange(2,20);
    sizeInput->setMinimum(2);
    sizeInput->setMaximum(20);
    sizeInput->setValue(3); // default size

    // add the gridlayout
    gridLayout = new QGridLayout();
    layout->addLayout(gridLayout);

    // make the callback work
    connect (sizeInput, SIGNAL(valueChanged(int)), this, SLOT(changeMatrixSize(int)));

    // initialize default matrix
    changeMatrixSize(sizeInput->minimum());
}

void MatrixInputWidget::changeMatrixSize(int size){
    for (auto &row : matrixCells){
        for (auto *cell : row){
            gridLayout->removeWidget(cell);
            delete cell;
        }
    }

    // Clear and resize the matrixCells container for the new size
    matrixCells.clear();
    matrixCells.resize(size);


    for (int i = 0; i < size; i++){
        matrixCells[i].resize(size);
        for(int j = 0; j < size; j++){
            QLineEdit *cell = new QLineEdit();
            gridLayout->addWidget(cell, i, j);  // Add the new cell to the grid layout
            matrixCells[i][j] = cell;
        }
    }

    emit matrixSizeChanged(size);
}

 QVector<QVector<QLineEdit*>> MatrixInputWidget::getMatrixValues() const {
    return matrixCells;
}
