#include "resultswidget.h"
#include <qboxlayout.h>

ResultsWidget::ResultsWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    titleLabel = new QLabel("Results", this);
    layout->addWidget(titleLabel);

    resultBox = new QTextEdit(this);
    resultBox->setReadOnly(true);
    resultBox->setPlaceholderText("Results will be displayed here...");
    layout->addWidget(resultBox);
}

void ResultsWidget::setResultText(const QString& text){
    resultBox->setText(text);
}
