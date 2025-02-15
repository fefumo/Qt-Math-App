#ifndef MATRIXINPUTWIDGET_H
#define MATRIXINPUTWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>
#include <QLineEdit>

class MatrixInputWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixInputWidget(QWidget *parent = nullptr);
    QVector<QVector<double>> getMatrixValues() const;
    QVector<QVector<QLineEdit*>> getMatrix();
    int getSize();
    double readValuesAndFindDeterminant(QVector<QVector<QLineEdit*>>&, int);

signals:
    void matrixSizeChanged(int);

private slots:
    void changeMatrixSize(int);

private:
    QGridLayout *gridLayout;
    QSpinBox *sizeInput;
    QVector<QVector<QLineEdit*>> matrixCells;
};

#endif // MATRIXINPUTWIDGET_H
