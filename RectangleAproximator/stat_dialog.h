#pragma once

#include <QDialog>
#include "ui_stat_dialog.h"
#include "genetic_algorithm.h"

class stat_dialog : public QDialog, public Ui::stat_dialog
{
	Q_OBJECT

public:
	stat_dialog(genetic_algorithm& ga, QWidget *parent = Q_NULLPTR);
	~stat_dialog();

	//Updates the stats on the window according to current best solution in genetic_algorithm class
	void update_stats() const;
private:
	//Reference to running genetic algorithm
	genetic_algorithm& ga_;

private slots:
	//Pauses the genetic algorithm and saves the current best 
	void on_saveButton_clicked();
};
