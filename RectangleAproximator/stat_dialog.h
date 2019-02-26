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

	void update_stats() const;
private:
	genetic_algorithm& ga_;

private slots:
	void on_saveButton_clicked();
};
