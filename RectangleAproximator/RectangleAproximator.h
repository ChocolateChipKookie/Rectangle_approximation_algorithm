#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RectangleAproximator.h"
#include <qvalidator.h>

class RectangleAproximator : public QMainWindow
{
	Q_OBJECT

public:
	RectangleAproximator(QWidget *parent = Q_NULLPTR);
	~RectangleAproximator();

private:
	Ui::RectangleAproximatorClass ui;


	std::wstring src_file;
	std::wstring dest_file;

private slots:

	void on_sourceFileButton_clicked();
	void on_startButton_clicked();
};
