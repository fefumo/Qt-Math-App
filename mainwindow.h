#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include "matrixfilehandler.h"
#include "resultswidget.h"
#include "matrixinputwidget.h"
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onCalculateButtonClicked();

private slots:
    void computeDeterminant();
    void openFileDialog();  // Slot to open the file dialog

private:
    Ui::MainWindow *ui;
    ResultsWidget *resultsWidget;
    MatrixInputWidget *matrixInputWidget;
    QString selectedFile;
    QMessageBox messageBox;
    MatrixFileHandler *matrixFileHandler;
    QLabel *fileLabel;
};

#endif // MAINWINDOW_H
