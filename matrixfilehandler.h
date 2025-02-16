#ifndef MATRIXFILEHANDLER_H
#define MATRIXFILEHANDLER_H

#include <QVector>
#include <QString>
#include <yaml-cpp/yaml.h>

class MatrixFileHandler {
public:
    MatrixFileHandler() = default;
    void saveMatrixToFile(const QVector<QVector<double>>& matrix, const QString& filename);
    QVector<QVector<double>> loadMatrixFromFile(const QString& filename);
};

#endif // MATRIXFILEHANDLER_H
