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
       QVector<QVector<QLineEdit*>> getMatrixValues() const;

signals:
    void matrixSizeChanged(int);

private slots:
    void changeMatrixSize(int);

private:
    QGridLayout *gridLayout;
    QSpinBox *sizeInput;
    QLabel *titleBar;
    QVector<QVector<QLineEdit*>> matrixCells;
};

#endif // MATRIXINPUTWIDGET_H
