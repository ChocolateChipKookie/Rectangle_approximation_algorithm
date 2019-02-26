/********************************************************************************
** Form generated from reading UI file 'canvas.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_canvas
{
public:

	void setupUi(QDialog *canvas)
	{
		if (canvas->objectName().isEmpty())
			canvas->setObjectName(QString::fromUtf8("canvas"));
		canvas->resize(400, 300);

		retranslateUi(canvas);

		QMetaObject::connectSlotsByName(canvas);
	} // setupUi

	void retranslateUi(QDialog *canvas)
	{
		canvas->setWindowTitle(QApplication::translate("canvas", "Dialog", nullptr));
	} // retranslateUi

};

namespace Ui {
	class canvas : public Ui_canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
