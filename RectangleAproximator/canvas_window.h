#pragma once

#include <QDialog>
#include "ui_canvas_window.h"
#include "rectangle_solution.h"
#include "genetic_algorithm.h"
#include "stat_dialog.h"

class canvas_window : public QDialog, public Ui::canvas_window
{
	Q_OBJECT

public:
	canvas_window(genetic_algorithm& ga, QWidget *parent = Q_NULLPTR);
	~canvas_window();

private:
	//Paints the best current best solution to the dialog
	void paintEvent(QPaintEvent* event) override;
	
	//When double clicked, toggles stat_dialog
	void mouseDoubleClickEvent(QMouseEvent* event) override;

	//Dialog and toggle state
	bool stat_dialog_state_;
	stat_dialog* stat_dialog_;

	//Temporary best solution used for time saving
	rectangle_solution* best_solution_{ nullptr };
	
	//Invokes update() every 30 ms, until closed gets set to true
	static void repaint_daemon(canvas_window* window);
	std::thread repainter_;
	bool closed_;

	//Drawing util
	QRgb* pixels_;
	image image_;
	QImage q_image_;
	unsigned zoom_;

	//Genetic algorithm
	genetic_algorithm& ga_;
};
