/********************************************************************************
** Form generated from reading UI file 'canvas_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVAS_WINDOW_H
#define UI_CANVAS_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_canvas_window
{
public:

    void setupUi(QDialog *canvas_window)
    {
        if (canvas_window->objectName().isEmpty())
            canvas_window->setObjectName(QString::fromUtf8("canvas_window"));
        canvas_window->resize(400, 300);

        retranslateUi(canvas_window);

        QMetaObject::connectSlotsByName(canvas_window);
    } // setupUi

    void retranslateUi(QDialog *canvas_window)
    {
        canvas_window->setWindowTitle(QApplication::translate("canvas_window", "canvas_window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class canvas_window: public Ui_canvas_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_WINDOW_H
