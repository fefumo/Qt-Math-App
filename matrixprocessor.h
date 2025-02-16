#ifndef MATRIXPROCESSOR_H
#define MATRIXPROCESSOR_H

#include <QObject>

class MainWindow;  // Forward declaration to not use .h file
class MatrixProcessor : public QObject {
    Q_OBJECT

public:
    explicit MatrixProcessor(MainWindow &mainWindow);
    void runJacobiMethod(double);

private:
    MainWindow &mainWindowRef;
};

#endif // MATRIXPROCESSOR_H
