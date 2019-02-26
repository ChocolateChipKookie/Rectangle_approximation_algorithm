/********************************************************************************
** Form generated from reading UI file 'stat_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STAT_DIALOG_H
#define UI_STAT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_stat_dialog
{
public:
    QLabel *relativeErrorResultLabel;
    QLabel *iterationCounterLabel;
    QLabel *iterationLabel;
    QLabel *fitnessLabel;
    QLabel *relativeErrorLabel;
    QLabel *fitnessResultLabel;
    QLabel *rectangleLabel;
    QLabel *rectangleConuterLabel;
    QPushButton *saveButton;
    QLabel *zoomLabel;
    QLineEdit *zoomLineEdit;

    void setupUi(QDialog *stat_dialog)
    {
        if (stat_dialog->objectName().isEmpty())
            stat_dialog->setObjectName(QString::fromUtf8("stat_dialog"));
        stat_dialog->resize(329, 218);
        relativeErrorResultLabel = new QLabel(stat_dialog);
        relativeErrorResultLabel->setObjectName(QString::fromUtf8("relativeErrorResultLabel"));
        relativeErrorResultLabel->setGeometry(QRect(150, 130, 171, 31));
        QFont font;
        font.setPointSize(12);
        relativeErrorResultLabel->setFont(font);
        iterationCounterLabel = new QLabel(stat_dialog);
        iterationCounterLabel->setObjectName(QString::fromUtf8("iterationCounterLabel"));
        iterationCounterLabel->setGeometry(QRect(150, 50, 171, 31));
        iterationCounterLabel->setFont(font);
        iterationLabel = new QLabel(stat_dialog);
        iterationLabel->setObjectName(QString::fromUtf8("iterationLabel"));
        iterationLabel->setGeometry(QRect(10, 50, 111, 31));
        iterationLabel->setFont(font);
        fitnessLabel = new QLabel(stat_dialog);
        fitnessLabel->setObjectName(QString::fromUtf8("fitnessLabel"));
        fitnessLabel->setGeometry(QRect(10, 90, 111, 31));
        fitnessLabel->setFont(font);
        relativeErrorLabel = new QLabel(stat_dialog);
        relativeErrorLabel->setObjectName(QString::fromUtf8("relativeErrorLabel"));
        relativeErrorLabel->setGeometry(QRect(10, 130, 131, 31));
        relativeErrorLabel->setFont(font);
        fitnessResultLabel = new QLabel(stat_dialog);
        fitnessResultLabel->setObjectName(QString::fromUtf8("fitnessResultLabel"));
        fitnessResultLabel->setGeometry(QRect(150, 90, 171, 31));
        fitnessResultLabel->setFont(font);
        rectangleLabel = new QLabel(stat_dialog);
        rectangleLabel->setObjectName(QString::fromUtf8("rectangleLabel"));
        rectangleLabel->setGeometry(QRect(10, 10, 131, 31));
        rectangleLabel->setFont(font);
        rectangleConuterLabel = new QLabel(stat_dialog);
        rectangleConuterLabel->setObjectName(QString::fromUtf8("rectangleConuterLabel"));
        rectangleConuterLabel->setGeometry(QRect(150, 10, 171, 31));
        rectangleConuterLabel->setFont(font);
        saveButton = new QPushButton(stat_dialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(10, 170, 131, 41));
        zoomLabel = new QLabel(stat_dialog);
        zoomLabel->setObjectName(QString::fromUtf8("zoomLabel"));
        zoomLabel->setGeometry(QRect(160, 170, 61, 41));
        zoomLabel->setFont(font);
        zoomLineEdit = new QLineEdit(stat_dialog);
        zoomLineEdit->setObjectName(QString::fromUtf8("zoomLineEdit"));
        zoomLineEdit->setGeometry(QRect(230, 171, 91, 41));

        retranslateUi(stat_dialog);

        QMetaObject::connectSlotsByName(stat_dialog);
    } // setupUi

    void retranslateUi(QDialog *stat_dialog)
    {
        stat_dialog->setWindowTitle(QApplication::translate("stat_dialog", "stat_dialog", nullptr));
        relativeErrorResultLabel->setText(QApplication::translate("stat_dialog", "0", nullptr));
        iterationCounterLabel->setText(QApplication::translate("stat_dialog", "0", nullptr));
        iterationLabel->setText(QApplication::translate("stat_dialog", "Iteration:", nullptr));
        fitnessLabel->setText(QApplication::translate("stat_dialog", "Fitness:", nullptr));
        relativeErrorLabel->setText(QApplication::translate("stat_dialog", "Relative error:", nullptr));
        fitnessResultLabel->setText(QApplication::translate("stat_dialog", "0", nullptr));
        rectangleLabel->setText(QApplication::translate("stat_dialog", "Rectangles:", nullptr));
        rectangleConuterLabel->setText(QApplication::translate("stat_dialog", "0", nullptr));
        saveButton->setText(QApplication::translate("stat_dialog", "Save", nullptr));
        zoomLabel->setText(QApplication::translate("stat_dialog", "Zoom:", nullptr));
        zoomLineEdit->setText(QApplication::translate("stat_dialog", "4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class stat_dialog: public Ui_stat_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STAT_DIALOG_H
