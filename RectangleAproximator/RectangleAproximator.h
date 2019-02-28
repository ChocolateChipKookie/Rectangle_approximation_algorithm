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

private slots:
	void on_sourceFileButton_clicked();
	void on_startButton_clicked();
	void on_saveConfigButton_clicked();
	void on_loadConfigButton_clicked();
};
