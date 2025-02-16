#include "matrixfilehandler.h"
#include <fstream>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include "matrixinputwidget.h"

void MatrixFileHandler::saveMatrixToFile(const QVector<QVector<double>>& matrix, const QString& filename) {
    YAML::Emitter out;
    out << YAML::BeginSeq;
    for (const auto& row : matrix) {
        std::vector<double> stdRow(row.begin(), row.end());
        out << YAML::Flow << stdRow;
    }
    out << YAML::EndSeq;

    std::ofstream file(filename.toStdString());
    if (file.is_open()) {
        file << out.c_str();
        file.close();
    }
}


QVector<QVector<double>> MatrixFileHandler::loadMatrixFromFile(const QString& filename) {
    qDebug() << "loading matrix from file...";
    QVector<QVector<double>> matrix;
    YAML::Node file = YAML::LoadFile(filename.toStdString());
    if (!file.IsSequence()) return matrix;

    // Load the matrix
    for (const auto& row : file) {
        QVector<double> rowVector;
        for (const auto& value : row) {
            rowVector.append(value.as<double>());
        }
        matrix.append(rowVector);
    }

    // Check if the matrix is square
    int rowCount = matrix.size();
    bool isSquare = true;

    for (const auto& row : matrix) {
        if (row.size() != rowCount) {
            isSquare = false;
            break;
        }
    }

    if (!isSquare) {
        return QVector<QVector<double>>();  // Return an empty matrix
    }

    qDebug() << "the matrix loaded from file:";
    MatrixInputWidget::debugPrintDoubleArray(matrix, matrix.size());
    return matrix;
}

