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
	void paintEvent(QPaintEvent* event) override;
	rectangle_solution* best_solution_{ nullptr };
	
	static void repaint_daemon(canvas_window* window);
	std::thread repainter_;

	genetic_algorithm& ga_;
	bool closed_;

	unsigned zoom_;
	bool stat_dialog_state_;
	stat_dialog* stat_dialog_;

	QRgb* pixels_;
	image image_;
	QImage q_image_;

private slots:
	void mouseDoubleClickEvent(QMouseEvent* event) override;
};
