/********************************************************************************
** Form generated from reading UI file 'RectangleAproximator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLEAPROXIMATOR_H
#define UI_RECTANGLEAPROXIMATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectangleAproximatorClass
{
public:
    QWidget *centralWidget;
    QPushButton *sourceFileButton;
    QPushButton *startButton;
    QLabel *mutationLabel;
    QLabel *swapMutationLabel;
    QLabel *randomRectMutationLabel;
    QLabel *backgroundMutationLabel;
    QLineEdit *lastRectMutationLineEdit;
    QLineEdit *randomMutationLineEdit;
    QLineEdit *backgroundMutationLineEdit;
    QLineEdit *swapMutationLineEdit;
    QLineEdit *srcFileLineEdit;
    QLabel *srcFileLabel;
    QLabel *lastRectMutationLabel;
    QLabel *crossoverLabel;
    QLabel *crossoverLabel_2;
    QLineEdit *crossoverLineEdit;
    QLineEdit *lastRectMutationAlphaLineEdit;
    QLineEdit *lastRectMutationMutationLineEdit;
    QLineEdit *lastRectMutationNewGeneLineEdit;
    QLabel *lastRectMutationAlphaLabel;
    QLabel *lastRectMutationMutationLabel;
    QLabel *lastRectMutationNewGeneLabel;
    QLineEdit *backgroundMutationMutationLineEdit;
    QLabel *backgroundMutationMutationLabel;
    QLabel *backgroundMutationNewGeneLabel;
    QLineEdit *backgroundMutationAlphaLineEdit;
    QLabel *backgroundMutationAlphaLabel;
    QLineEdit *backgroundMutationNewGeneLineEdit;
    QLineEdit *randomMutationMutationLineEdit;
    QLabel *randomMutationMutationLabel;
    QLabel *randomMutationNewGeneLabel;
    QLineEdit *randomMutationAlphaLineEdit;
    QLabel *randomMutationAlphaLabel;
    QLineEdit *randomMutationNewGeneLineEdit;
    QLabel *randomMutationRectanglesLabel;
    QLineEdit *randomMutationRectanglesLineEdit;
    QLabel *swapMutationSwapsLabel;
    QLineEdit *swapMutationSwapsLineEdit;
    QLineEdit *K_numberLineEdit;
    QLabel *K_numberLabel;
    QLabel *selectionLabel;
    QLabel *rectangleIterationLabel;
    QLineEdit *rectangleIterationLineEdit;
    QLabel *rectanglesLabel;
    QLineEdit *rectanglesLineEdit;
    QLineEdit *cleanupLineEdit;
    QLabel *cleanupLabel;
    QLineEdit *lastRectMutationAlphaLineEdit_2;
    QLineEdit *lastRectMutationMutationLineEdit_2;
    QLineEdit *lastRectMutationNewGeneLineEdit_2;
    QLineEdit *backgroundMutationLineEdit_2;
    QLineEdit *backgroundMutationAlphaLineEdit_2;
    QLineEdit *backgroundMutationMutationLineEdit_2;
    QLineEdit *backgroundMutationNewGeneLineEdit_2;
    QLineEdit *randomMutationLineEdit_2;
    QLineEdit *randomMutationRectanglesLineEdit_2;
    QLineEdit *randomMutationAlphaLineEdit_2;
    QLineEdit *randomMutationMutationLineEdit_2;
    QLineEdit *randomMutationNewGeneLineEdit_2;
    QLineEdit *swapMutationLineEdit_2;
    QLineEdit *swapMutationSwapsLineEdit_2;
    QLineEdit *K_numberLineEdit_2;
    QLineEdit *crossoverLineEdit_2;
    QLineEdit *lastRectMutationLineEdit_2;
    QLabel *populationSizeLabel;
    QLineEdit *populationSizeLineEdit;
    QLabel *secondaryMutationLabel;
    QLineEdit *secondaryMutationLineEdit_2;
    QLineEdit *secondaryMutationLineEdit;
    QLineEdit *switchesLineEdit;
    QLabel *switchesLabel;

    void setupUi(QMainWindow *RectangleAproximatorClass)
    {
        if (RectangleAproximatorClass->objectName().isEmpty())
            RectangleAproximatorClass->setObjectName(QString::fromUtf8("RectangleAproximatorClass"));
        RectangleAproximatorClass->resize(510, 1031);
        centralWidget = new QWidget(RectangleAproximatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sourceFileButton = new QPushButton(centralWidget);
        sourceFileButton->setObjectName(QString::fromUtf8("sourceFileButton"));
        sourceFileButton->setGeometry(QRect(470, 10, 31, 31));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(10, 970, 491, 51));
        mutationLabel = new QLabel(centralWidget);
        mutationLabel->setObjectName(QString::fromUtf8("mutationLabel"));
        mutationLabel->setGeometry(QRect(10, 250, 101, 31));
        QFont font;
        font.setPointSize(12);
        mutationLabel->setFont(font);
        swapMutationLabel = new QLabel(centralWidget);
        swapMutationLabel->setObjectName(QString::fromUtf8("swapMutationLabel"));
        swapMutationLabel->setGeometry(QRect(150, 810, 171, 31));
        swapMutationLabel->setFont(font);
        randomRectMutationLabel = new QLabel(centralWidget);
        randomRectMutationLabel->setObjectName(QString::fromUtf8("randomRectMutationLabel"));
        randomRectMutationLabel->setGeometry(QRect(150, 610, 171, 31));
        randomRectMutationLabel->setFont(font);
        backgroundMutationLabel = new QLabel(centralWidget);
        backgroundMutationLabel->setObjectName(QString::fromUtf8("backgroundMutationLabel"));
        backgroundMutationLabel->setGeometry(QRect(150, 450, 171, 31));
        backgroundMutationLabel->setFont(font);
        lastRectMutationLineEdit = new QLineEdit(centralWidget);
        lastRectMutationLineEdit->setObjectName(QString::fromUtf8("lastRectMutationLineEdit"));
        lastRectMutationLineEdit->setGeometry(QRect(350, 290, 71, 31));
        randomMutationLineEdit = new QLineEdit(centralWidget);
        randomMutationLineEdit->setObjectName(QString::fromUtf8("randomMutationLineEdit"));
        randomMutationLineEdit->setGeometry(QRect(350, 610, 71, 31));
        backgroundMutationLineEdit = new QLineEdit(centralWidget);
        backgroundMutationLineEdit->setObjectName(QString::fromUtf8("backgroundMutationLineEdit"));
        backgroundMutationLineEdit->setGeometry(QRect(350, 450, 71, 31));
        swapMutationLineEdit = new QLineEdit(centralWidget);
        swapMutationLineEdit->setObjectName(QString::fromUtf8("swapMutationLineEdit"));
        swapMutationLineEdit->setGeometry(QRect(350, 810, 71, 31));
        srcFileLineEdit = new QLineEdit(centralWidget);
        srcFileLineEdit->setObjectName(QString::fromUtf8("srcFileLineEdit"));
        srcFileLineEdit->setGeometry(QRect(160, 10, 301, 31));
        srcFileLabel = new QLabel(centralWidget);
        srcFileLabel->setObjectName(QString::fromUtf8("srcFileLabel"));
        srcFileLabel->setGeometry(QRect(10, 10, 151, 31));
        srcFileLabel->setFont(font);
        lastRectMutationLabel = new QLabel(centralWidget);
        lastRectMutationLabel->setObjectName(QString::fromUtf8("lastRectMutationLabel"));
        lastRectMutationLabel->setGeometry(QRect(150, 290, 171, 31));
        lastRectMutationLabel->setFont(font);
        crossoverLabel = new QLabel(centralWidget);
        crossoverLabel->setObjectName(QString::fromUtf8("crossoverLabel"));
        crossoverLabel->setGeometry(QRect(10, 890, 101, 31));
        crossoverLabel->setFont(font);
        crossoverLabel_2 = new QLabel(centralWidget);
        crossoverLabel_2->setObjectName(QString::fromUtf8("crossoverLabel_2"));
        crossoverLabel_2->setGeometry(QRect(150, 890, 170, 31));
        crossoverLabel_2->setFont(font);
        crossoverLineEdit = new QLineEdit(centralWidget);
        crossoverLineEdit->setObjectName(QString::fromUtf8("crossoverLineEdit"));
        crossoverLineEdit->setGeometry(QRect(350, 890, 71, 31));
        lastRectMutationAlphaLineEdit = new QLineEdit(centralWidget);
        lastRectMutationAlphaLineEdit->setObjectName(QString::fromUtf8("lastRectMutationAlphaLineEdit"));
        lastRectMutationAlphaLineEdit->setGeometry(QRect(350, 330, 71, 31));
        lastRectMutationMutationLineEdit = new QLineEdit(centralWidget);
        lastRectMutationMutationLineEdit->setObjectName(QString::fromUtf8("lastRectMutationMutationLineEdit"));
        lastRectMutationMutationLineEdit->setGeometry(QRect(350, 370, 71, 31));
        lastRectMutationNewGeneLineEdit = new QLineEdit(centralWidget);
        lastRectMutationNewGeneLineEdit->setObjectName(QString::fromUtf8("lastRectMutationNewGeneLineEdit"));
        lastRectMutationNewGeneLineEdit->setGeometry(QRect(350, 410, 71, 31));
        lastRectMutationAlphaLabel = new QLabel(centralWidget);
        lastRectMutationAlphaLabel->setObjectName(QString::fromUtf8("lastRectMutationAlphaLabel"));
        lastRectMutationAlphaLabel->setGeometry(QRect(200, 330, 141, 31));
        lastRectMutationAlphaLabel->setFont(font);
        lastRectMutationMutationLabel = new QLabel(centralWidget);
        lastRectMutationMutationLabel->setObjectName(QString::fromUtf8("lastRectMutationMutationLabel"));
        lastRectMutationMutationLabel->setGeometry(QRect(200, 370, 141, 31));
        lastRectMutationMutationLabel->setFont(font);
        lastRectMutationNewGeneLabel = new QLabel(centralWidget);
        lastRectMutationNewGeneLabel->setObjectName(QString::fromUtf8("lastRectMutationNewGeneLabel"));
        lastRectMutationNewGeneLabel->setGeometry(QRect(200, 410, 141, 31));
        lastRectMutationNewGeneLabel->setFont(font);
        backgroundMutationMutationLineEdit = new QLineEdit(centralWidget);
        backgroundMutationMutationLineEdit->setObjectName(QString::fromUtf8("backgroundMutationMutationLineEdit"));
        backgroundMutationMutationLineEdit->setGeometry(QRect(350, 530, 71, 31));
        backgroundMutationMutationLabel = new QLabel(centralWidget);
        backgroundMutationMutationLabel->setObjectName(QString::fromUtf8("backgroundMutationMutationLabel"));
        backgroundMutationMutationLabel->setGeometry(QRect(200, 530, 141, 31));
        backgroundMutationMutationLabel->setFont(font);
        backgroundMutationNewGeneLabel = new QLabel(centralWidget);
        backgroundMutationNewGeneLabel->setObjectName(QString::fromUtf8("backgroundMutationNewGeneLabel"));
        backgroundMutationNewGeneLabel->setGeometry(QRect(200, 570, 141, 31));
        backgroundMutationNewGeneLabel->setFont(font);
        backgroundMutationAlphaLineEdit = new QLineEdit(centralWidget);
        backgroundMutationAlphaLineEdit->setObjectName(QString::fromUtf8("backgroundMutationAlphaLineEdit"));
        backgroundMutationAlphaLineEdit->setGeometry(QRect(350, 490, 71, 31));
        backgroundMutationAlphaLabel = new QLabel(centralWidget);
        backgroundMutationAlphaLabel->setObjectName(QString::fromUtf8("backgroundMutationAlphaLabel"));
        backgroundMutationAlphaLabel->setGeometry(QRect(200, 490, 141, 31));
        backgroundMutationAlphaLabel->setFont(font);
        backgroundMutationNewGeneLineEdit = new QLineEdit(centralWidget);
        backgroundMutationNewGeneLineEdit->setObjectName(QString::fromUtf8("backgroundMutationNewGeneLineEdit"));
        backgroundMutationNewGeneLineEdit->setGeometry(QRect(350, 570, 71, 31));
        randomMutationMutationLineEdit = new QLineEdit(centralWidget);
        randomMutationMutationLineEdit->setObjectName(QString::fromUtf8("randomMutationMutationLineEdit"));
        randomMutationMutationLineEdit->setGeometry(QRect(350, 730, 71, 31));
        randomMutationMutationLabel = new QLabel(centralWidget);
        randomMutationMutationLabel->setObjectName(QString::fromUtf8("randomMutationMutationLabel"));
        randomMutationMutationLabel->setGeometry(QRect(200, 730, 141, 31));
        randomMutationMutationLabel->setFont(font);
        randomMutationNewGeneLabel = new QLabel(centralWidget);
        randomMutationNewGeneLabel->setObjectName(QString::fromUtf8("randomMutationNewGeneLabel"));
        randomMutationNewGeneLabel->setGeometry(QRect(200, 770, 141, 31));
        randomMutationNewGeneLabel->setFont(font);
        randomMutationAlphaLineEdit = new QLineEdit(centralWidget);
        randomMutationAlphaLineEdit->setObjectName(QString::fromUtf8("randomMutationAlphaLineEdit"));
        randomMutationAlphaLineEdit->setGeometry(QRect(350, 690, 71, 31));
        randomMutationAlphaLabel = new QLabel(centralWidget);
        randomMutationAlphaLabel->setObjectName(QString::fromUtf8("randomMutationAlphaLabel"));
        randomMutationAlphaLabel->setGeometry(QRect(200, 690, 141, 31));
        randomMutationAlphaLabel->setFont(font);
        randomMutationNewGeneLineEdit = new QLineEdit(centralWidget);
        randomMutationNewGeneLineEdit->setObjectName(QString::fromUtf8("randomMutationNewGeneLineEdit"));
        randomMutationNewGeneLineEdit->setGeometry(QRect(350, 770, 71, 31));
        randomMutationRectanglesLabel = new QLabel(centralWidget);
        randomMutationRectanglesLabel->setObjectName(QString::fromUtf8("randomMutationRectanglesLabel"));
        randomMutationRectanglesLabel->setGeometry(QRect(200, 650, 141, 31));
        randomMutationRectanglesLabel->setFont(font);
        randomMutationRectanglesLineEdit = new QLineEdit(centralWidget);
        randomMutationRectanglesLineEdit->setObjectName(QString::fromUtf8("randomMutationRectanglesLineEdit"));
        randomMutationRectanglesLineEdit->setGeometry(QRect(350, 650, 71, 31));
        swapMutationSwapsLabel = new QLabel(centralWidget);
        swapMutationSwapsLabel->setObjectName(QString::fromUtf8("swapMutationSwapsLabel"));
        swapMutationSwapsLabel->setGeometry(QRect(200, 850, 141, 31));
        swapMutationSwapsLabel->setFont(font);
        swapMutationSwapsLineEdit = new QLineEdit(centralWidget);
        swapMutationSwapsLineEdit->setObjectName(QString::fromUtf8("swapMutationSwapsLineEdit"));
        swapMutationSwapsLineEdit->setGeometry(QRect(350, 850, 71, 31));
        K_numberLineEdit = new QLineEdit(centralWidget);
        K_numberLineEdit->setObjectName(QString::fromUtf8("K_numberLineEdit"));
        K_numberLineEdit->setGeometry(QRect(350, 930, 71, 31));
        K_numberLabel = new QLabel(centralWidget);
        K_numberLabel->setObjectName(QString::fromUtf8("K_numberLabel"));
        K_numberLabel->setGeometry(QRect(150, 930, 171, 31));
        K_numberLabel->setFont(font);
        selectionLabel = new QLabel(centralWidget);
        selectionLabel->setObjectName(QString::fromUtf8("selectionLabel"));
        selectionLabel->setGeometry(QRect(10, 930, 101, 31));
        selectionLabel->setFont(font);
        rectangleIterationLabel = new QLabel(centralWidget);
        rectangleIterationLabel->setObjectName(QString::fromUtf8("rectangleIterationLabel"));
        rectangleIterationLabel->setGeometry(QRect(10, 130, 221, 31));
        rectangleIterationLabel->setFont(font);
        rectangleIterationLineEdit = new QLineEdit(centralWidget);
        rectangleIterationLineEdit->setObjectName(QString::fromUtf8("rectangleIterationLineEdit"));
        rectangleIterationLineEdit->setGeometry(QRect(350, 130, 151, 31));
        rectanglesLabel = new QLabel(centralWidget);
        rectanglesLabel->setObjectName(QString::fromUtf8("rectanglesLabel"));
        rectanglesLabel->setGeometry(QRect(10, 90, 221, 31));
        rectanglesLabel->setFont(font);
        rectanglesLineEdit = new QLineEdit(centralWidget);
        rectanglesLineEdit->setObjectName(QString::fromUtf8("rectanglesLineEdit"));
        rectanglesLineEdit->setGeometry(QRect(350, 90, 151, 31));
        cleanupLineEdit = new QLineEdit(centralWidget);
        cleanupLineEdit->setObjectName(QString::fromUtf8("cleanupLineEdit"));
        cleanupLineEdit->setGeometry(QRect(350, 170, 151, 31));
        cleanupLabel = new QLabel(centralWidget);
        cleanupLabel->setObjectName(QString::fromUtf8("cleanupLabel"));
        cleanupLabel->setGeometry(QRect(10, 170, 221, 31));
        cleanupLabel->setFont(font);
        lastRectMutationAlphaLineEdit_2 = new QLineEdit(centralWidget);
        lastRectMutationAlphaLineEdit_2->setObjectName(QString::fromUtf8("lastRectMutationAlphaLineEdit_2"));
        lastRectMutationAlphaLineEdit_2->setGeometry(QRect(430, 330, 71, 31));
        lastRectMutationMutationLineEdit_2 = new QLineEdit(centralWidget);
        lastRectMutationMutationLineEdit_2->setObjectName(QString::fromUtf8("lastRectMutationMutationLineEdit_2"));
        lastRectMutationMutationLineEdit_2->setGeometry(QRect(430, 370, 71, 31));
        lastRectMutationNewGeneLineEdit_2 = new QLineEdit(centralWidget);
        lastRectMutationNewGeneLineEdit_2->setObjectName(QString::fromUtf8("lastRectMutationNewGeneLineEdit_2"));
        lastRectMutationNewGeneLineEdit_2->setGeometry(QRect(430, 410, 71, 31));
        backgroundMutationLineEdit_2 = new QLineEdit(centralWidget);
        backgroundMutationLineEdit_2->setObjectName(QString::fromUtf8("backgroundMutationLineEdit_2"));
        backgroundMutationLineEdit_2->setGeometry(QRect(430, 450, 71, 31));
        backgroundMutationAlphaLineEdit_2 = new QLineEdit(centralWidget);
        backgroundMutationAlphaLineEdit_2->setObjectName(QString::fromUtf8("backgroundMutationAlphaLineEdit_2"));
        backgroundMutationAlphaLineEdit_2->setGeometry(QRect(430, 490, 71, 31));
        backgroundMutationMutationLineEdit_2 = new QLineEdit(centralWidget);
        backgroundMutationMutationLineEdit_2->setObjectName(QString::fromUtf8("backgroundMutationMutationLineEdit_2"));
        backgroundMutationMutationLineEdit_2->setGeometry(QRect(430, 530, 71, 31));
        backgroundMutationNewGeneLineEdit_2 = new QLineEdit(centralWidget);
        backgroundMutationNewGeneLineEdit_2->setObjectName(QString::fromUtf8("backgroundMutationNewGeneLineEdit_2"));
        backgroundMutationNewGeneLineEdit_2->setGeometry(QRect(430, 570, 71, 31));
        randomMutationLineEdit_2 = new QLineEdit(centralWidget);
        randomMutationLineEdit_2->setObjectName(QString::fromUtf8("randomMutationLineEdit_2"));
        randomMutationLineEdit_2->setGeometry(QRect(430, 610, 71, 31));
        randomMutationRectanglesLineEdit_2 = new QLineEdit(centralWidget);
        randomMutationRectanglesLineEdit_2->setObjectName(QString::fromUtf8("randomMutationRectanglesLineEdit_2"));
        randomMutationRectanglesLineEdit_2->setGeometry(QRect(430, 650, 71, 31));
        randomMutationAlphaLineEdit_2 = new QLineEdit(centralWidget);
        randomMutationAlphaLineEdit_2->setObjectName(QString::fromUtf8("randomMutationAlphaLineEdit_2"));
        randomMutationAlphaLineEdit_2->setGeometry(QRect(430, 690, 71, 31));
        randomMutationMutationLineEdit_2 = new QLineEdit(centralWidget);
        randomMutationMutationLineEdit_2->setObjectName(QString::fromUtf8("randomMutationMutationLineEdit_2"));
        randomMutationMutationLineEdit_2->setGeometry(QRect(430, 730, 71, 31));
        randomMutationNewGeneLineEdit_2 = new QLineEdit(centralWidget);
        randomMutationNewGeneLineEdit_2->setObjectName(QString::fromUtf8("randomMutationNewGeneLineEdit_2"));
        randomMutationNewGeneLineEdit_2->setGeometry(QRect(430, 770, 71, 31));
        swapMutationLineEdit_2 = new QLineEdit(centralWidget);
        swapMutationLineEdit_2->setObjectName(QString::fromUtf8("swapMutationLineEdit_2"));
        swapMutationLineEdit_2->setGeometry(QRect(430, 810, 71, 31));
        swapMutationSwapsLineEdit_2 = new QLineEdit(centralWidget);
        swapMutationSwapsLineEdit_2->setObjectName(QString::fromUtf8("swapMutationSwapsLineEdit_2"));
        swapMutationSwapsLineEdit_2->setGeometry(QRect(430, 850, 71, 31));
        K_numberLineEdit_2 = new QLineEdit(centralWidget);
        K_numberLineEdit_2->setObjectName(QString::fromUtf8("K_numberLineEdit_2"));
        K_numberLineEdit_2->setGeometry(QRect(430, 930, 71, 31));
        crossoverLineEdit_2 = new QLineEdit(centralWidget);
        crossoverLineEdit_2->setObjectName(QString::fromUtf8("crossoverLineEdit_2"));
        crossoverLineEdit_2->setGeometry(QRect(430, 890, 71, 31));
        lastRectMutationLineEdit_2 = new QLineEdit(centralWidget);
        lastRectMutationLineEdit_2->setObjectName(QString::fromUtf8("lastRectMutationLineEdit_2"));
        lastRectMutationLineEdit_2->setGeometry(QRect(430, 290, 71, 31));
        populationSizeLabel = new QLabel(centralWidget);
        populationSizeLabel->setObjectName(QString::fromUtf8("populationSizeLabel"));
        populationSizeLabel->setGeometry(QRect(10, 50, 221, 31));
        populationSizeLabel->setFont(font);
        populationSizeLineEdit = new QLineEdit(centralWidget);
        populationSizeLineEdit->setObjectName(QString::fromUtf8("populationSizeLineEdit"));
        populationSizeLineEdit->setGeometry(QRect(350, 50, 151, 31));
        secondaryMutationLabel = new QLabel(centralWidget);
        secondaryMutationLabel->setObjectName(QString::fromUtf8("secondaryMutationLabel"));
        secondaryMutationLabel->setGeometry(QRect(150, 250, 191, 31));
        secondaryMutationLabel->setFont(font);
        secondaryMutationLineEdit_2 = new QLineEdit(centralWidget);
        secondaryMutationLineEdit_2->setObjectName(QString::fromUtf8("secondaryMutationLineEdit_2"));
        secondaryMutationLineEdit_2->setGeometry(QRect(430, 250, 71, 31));
        secondaryMutationLineEdit = new QLineEdit(centralWidget);
        secondaryMutationLineEdit->setObjectName(QString::fromUtf8("secondaryMutationLineEdit"));
        secondaryMutationLineEdit->setGeometry(QRect(350, 250, 71, 31));
        switchesLineEdit = new QLineEdit(centralWidget);
        switchesLineEdit->setObjectName(QString::fromUtf8("switchesLineEdit"));
        switchesLineEdit->setGeometry(QRect(350, 210, 151, 31));
        switchesLabel = new QLabel(centralWidget);
        switchesLabel->setObjectName(QString::fromUtf8("switchesLabel"));
        switchesLabel->setGeometry(QRect(10, 210, 221, 31));
        switchesLabel->setFont(font);
        RectangleAproximatorClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(srcFileLineEdit, sourceFileButton);
        QWidget::setTabOrder(sourceFileButton, populationSizeLineEdit);
        QWidget::setTabOrder(populationSizeLineEdit, rectanglesLineEdit);
        QWidget::setTabOrder(rectanglesLineEdit, rectangleIterationLineEdit);
        QWidget::setTabOrder(rectangleIterationLineEdit, cleanupLineEdit);
        QWidget::setTabOrder(cleanupLineEdit, switchesLineEdit);
        QWidget::setTabOrder(switchesLineEdit, secondaryMutationLineEdit);
        QWidget::setTabOrder(secondaryMutationLineEdit, secondaryMutationLineEdit_2);
        QWidget::setTabOrder(secondaryMutationLineEdit_2, lastRectMutationLineEdit);
        QWidget::setTabOrder(lastRectMutationLineEdit, lastRectMutationLineEdit_2);
        QWidget::setTabOrder(lastRectMutationLineEdit_2, lastRectMutationAlphaLineEdit);
        QWidget::setTabOrder(lastRectMutationAlphaLineEdit, lastRectMutationAlphaLineEdit_2);
        QWidget::setTabOrder(lastRectMutationAlphaLineEdit_2, lastRectMutationMutationLineEdit);
        QWidget::setTabOrder(lastRectMutationMutationLineEdit, lastRectMutationMutationLineEdit_2);
        QWidget::setTabOrder(lastRectMutationMutationLineEdit_2, lastRectMutationNewGeneLineEdit);
        QWidget::setTabOrder(lastRectMutationNewGeneLineEdit, lastRectMutationNewGeneLineEdit_2);
        QWidget::setTabOrder(lastRectMutationNewGeneLineEdit_2, backgroundMutationLineEdit);
        QWidget::setTabOrder(backgroundMutationLineEdit, backgroundMutationLineEdit_2);
        QWidget::setTabOrder(backgroundMutationLineEdit_2, backgroundMutationAlphaLineEdit);
        QWidget::setTabOrder(backgroundMutationAlphaLineEdit, backgroundMutationAlphaLineEdit_2);
        QWidget::setTabOrder(backgroundMutationAlphaLineEdit_2, backgroundMutationMutationLineEdit);
        QWidget::setTabOrder(backgroundMutationMutationLineEdit, backgroundMutationMutationLineEdit_2);
        QWidget::setTabOrder(backgroundMutationMutationLineEdit_2, backgroundMutationNewGeneLineEdit);
        QWidget::setTabOrder(backgroundMutationNewGeneLineEdit, backgroundMutationNewGeneLineEdit_2);
        QWidget::setTabOrder(backgroundMutationNewGeneLineEdit_2, randomMutationLineEdit);
        QWidget::setTabOrder(randomMutationLineEdit, randomMutationLineEdit_2);
        QWidget::setTabOrder(randomMutationLineEdit_2, randomMutationRectanglesLineEdit);
        QWidget::setTabOrder(randomMutationRectanglesLineEdit, randomMutationRectanglesLineEdit_2);
        QWidget::setTabOrder(randomMutationRectanglesLineEdit_2, randomMutationAlphaLineEdit);
        QWidget::setTabOrder(randomMutationAlphaLineEdit, randomMutationAlphaLineEdit_2);
        QWidget::setTabOrder(randomMutationAlphaLineEdit_2, randomMutationMutationLineEdit);
        QWidget::setTabOrder(randomMutationMutationLineEdit, randomMutationMutationLineEdit_2);
        QWidget::setTabOrder(randomMutationMutationLineEdit_2, randomMutationNewGeneLineEdit);
        QWidget::setTabOrder(randomMutationNewGeneLineEdit, randomMutationNewGeneLineEdit_2);
        QWidget::setTabOrder(randomMutationNewGeneLineEdit_2, swapMutationLineEdit);
        QWidget::setTabOrder(swapMutationLineEdit, swapMutationLineEdit_2);
        QWidget::setTabOrder(swapMutationLineEdit_2, swapMutationSwapsLineEdit);
        QWidget::setTabOrder(swapMutationSwapsLineEdit, swapMutationSwapsLineEdit_2);
        QWidget::setTabOrder(swapMutationSwapsLineEdit_2, crossoverLineEdit);
        QWidget::setTabOrder(crossoverLineEdit, crossoverLineEdit_2);
        QWidget::setTabOrder(crossoverLineEdit_2, K_numberLineEdit);
        QWidget::setTabOrder(K_numberLineEdit, K_numberLineEdit_2);
        QWidget::setTabOrder(K_numberLineEdit_2, startButton);

        retranslateUi(RectangleAproximatorClass);

        QMetaObject::connectSlotsByName(RectangleAproximatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *RectangleAproximatorClass)
    {
        RectangleAproximatorClass->setWindowTitle(QApplication::translate("RectangleAproximatorClass", "RectangleAproximator", nullptr));
        sourceFileButton->setText(QApplication::translate("RectangleAproximatorClass", "...", nullptr));
        startButton->setText(QApplication::translate("RectangleAproximatorClass", "Start", nullptr));
        mutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Mutations:", nullptr));
        swapMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Swap rectangles:", nullptr));
        randomRectMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Random rectangle:", nullptr));
        backgroundMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Background:", nullptr));
        lastRectMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.75", nullptr));
        randomMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.2", nullptr));
        backgroundMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.05", nullptr));
        swapMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0", nullptr));
        srcFileLineEdit->setText(QString());
        srcFileLineEdit->setPlaceholderText(QApplication::translate("RectangleAproximatorClass", " Select file", nullptr));
        srcFileLabel->setText(QApplication::translate("RectangleAproximatorClass", "Source file:", nullptr));
        lastRectMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Last rectangle:", nullptr));
        crossoverLabel->setText(QApplication::translate("RectangleAproximatorClass", "Crossovers:", nullptr));
        crossoverLabel_2->setText(QApplication::translate("RectangleAproximatorClass", "Crossover chance:", nullptr));
        crossoverLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.1", nullptr));
        lastRectMutationAlphaLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.35", nullptr));
        lastRectMutationMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.25", nullptr));
        lastRectMutationNewGeneLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.05", nullptr));
        lastRectMutationAlphaLabel->setText(QApplication::translate("RectangleAproximatorClass", "Alpha:", nullptr));
        lastRectMutationMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Mutation:", nullptr));
        lastRectMutationNewGeneLabel->setText(QApplication::translate("RectangleAproximatorClass", "New gene:", nullptr));
        backgroundMutationMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.3", nullptr));
        backgroundMutationMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Mutation:", nullptr));
        backgroundMutationNewGeneLabel->setText(QApplication::translate("RectangleAproximatorClass", "New gene:", nullptr));
        backgroundMutationAlphaLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.3", nullptr));
        backgroundMutationAlphaLabel->setText(QApplication::translate("RectangleAproximatorClass", "Alpha:", nullptr));
        backgroundMutationNewGeneLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.05", nullptr));
        randomMutationMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.2", nullptr));
        randomMutationMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Mutation:", nullptr));
        randomMutationNewGeneLabel->setText(QApplication::translate("RectangleAproximatorClass", "New gene:", nullptr));
        randomMutationAlphaLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.2", nullptr));
        randomMutationAlphaLabel->setText(QApplication::translate("RectangleAproximatorClass", "Alpha:", nullptr));
        randomMutationNewGeneLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.1", nullptr));
        randomMutationRectanglesLabel->setText(QApplication::translate("RectangleAproximatorClass", "Rectangles:", nullptr));
        randomMutationRectanglesLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "1", nullptr));
        swapMutationSwapsLabel->setText(QApplication::translate("RectangleAproximatorClass", "Swaps:", nullptr));
        swapMutationSwapsLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "1", nullptr));
        K_numberLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "7", nullptr));
        K_numberLabel->setText(QApplication::translate("RectangleAproximatorClass", "K-number:", nullptr));
        selectionLabel->setText(QApplication::translate("RectangleAproximatorClass", "Selection:", nullptr));
        rectangleIterationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Iterations per rectangle:", nullptr));
        rectangleIterationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "50", nullptr));
        rectanglesLabel->setText(QApplication::translate("RectangleAproximatorClass", "Rectangles:", nullptr));
        rectanglesLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "500", nullptr));
        cleanupLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "500", nullptr));
        cleanupLabel->setText(QApplication::translate("RectangleAproximatorClass", "Cleanup iterations:", nullptr));
        lastRectMutationAlphaLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        lastRectMutationMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        lastRectMutationNewGeneLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        backgroundMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        backgroundMutationAlphaLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        backgroundMutationMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        backgroundMutationNewGeneLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        randomMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.8", nullptr));
        randomMutationRectanglesLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "1", nullptr));
        randomMutationAlphaLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.15", nullptr));
        randomMutationMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.25", nullptr));
        randomMutationNewGeneLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.4", nullptr));
        swapMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.2", nullptr));
        swapMutationSwapsLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "2", nullptr));
        K_numberLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "15", nullptr));
        crossoverLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.3", nullptr));
        lastRectMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.0", nullptr));
        populationSizeLabel->setText(QApplication::translate("RectangleAproximatorClass", "Population size:", nullptr));
        populationSizeLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "100", nullptr));
        secondaryMutationLabel->setText(QApplication::translate("RectangleAproximatorClass", "Secondary mutation:", nullptr));
        secondaryMutationLineEdit_2->setText(QApplication::translate("RectangleAproximatorClass", "0.5", nullptr));
        secondaryMutationLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "0.5", nullptr));
        switchesLineEdit->setText(QApplication::translate("RectangleAproximatorClass", "25", nullptr));
        switchesLabel->setText(QApplication::translate("RectangleAproximatorClass", "Switches after:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RectangleAproximatorClass: public Ui_RectangleAproximatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLEAPROXIMATOR_H
