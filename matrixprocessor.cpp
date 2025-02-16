#include "matrixprocessor.h"
#include "mainwindow.h"

MatrixProcessor::MatrixProcessor(MainWindow &mainWindow) : mainWindowRef(mainWindow)
{}

void MatrixProcessor::runJacobiMethod(double e) {
    // Dummy Jacobi method result
    QString result = "Jacobi Method Completed Successfully!";

    // Update the resultsWidget in MainWindow
    mainWindowRef.resultsWidget->setResultText(result);
    qDebug() << "Updated resultsWidget with Jacobi Method result.";
}
