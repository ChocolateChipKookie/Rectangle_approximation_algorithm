#include "canvas_window.h"
#include <QtCore>
#include <QtGui>

canvas_window::canvas_window(genetic_algorithm& ga, QWidget *parent)
	:	QDialog(parent),
		ga_(ga),
		closed_(false),
		stat_dialog_state_(true),
		image_(0, 0)
{
	setupUi(this);
	//Enabling minimization
	this->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
	
	//Starting the repainter thread
	repainter_ = std::thread(repaint_daemon, this);

	//Deciding zoom, and setting size of window
	//Zoom = highest whole multiple of window dimensions, where width and height are smaller than 1000
	dimensions& dim = ga.get_goal_image().dimensions_;
	zoom_ = 1000 / (dim.width > dim.height ? dim.width : dim.height);
	this->setFixedSize(ga.get_goal_image().dimensions_.width * zoom_, ga.get_goal_image().dimensions_.height * zoom_);

	//All resources needed for drawing to window
	pixels_ = new QRgb[width()*height()];
	image_ = image(width(), height());
	q_image_ = QImage(reinterpret_cast<uchar*>(pixels_), width(), height(), QImage::Format_RGB32);

	//Creating stat dialog
	stat_dialog_ = new stat_dialog(ga, this);
	stat_dialog_->show();
}

canvas_window::~canvas_window()
{
	delete[] best_solution_;
	delete[] stat_dialog_;
	delete[] pixels_;

	closed_ = true;
	repainter_.join();
}

void canvas_window::paintEvent(QPaintEvent* event)
{
	//Ignore painting if there is no best solution
	if (ga_.best_solution == nullptr)return;
	
	{
		//Lock mutex, so solution doesn't get deleted while the copying takes place
		std::lock_guard<std::mutex> lg(ga_.best_solution_mutex);

		//Delete and copy the solution
		delete best_solution_;
		best_solution_ = new rectangle_solution(*ga_.best_solution);
	}

	//Draw the best solution
	image_.draw_solution(*best_solution_, zoom_);

	//Painting pixel by pixel
	QPainter painter(this);
	for (int x = 0; x < width(); ++x) {
		for (int y = 0; y < height(); ++y) {
			pixels_[x + y * width()] = QRgb(
				//R
				(image_.data_[x + y * width()].at(0) << 16) +
				//G
				(image_.data_[x + y * width()].at(1) << 8) +
				//B
				(image_.data_[x + y * width()].at(2))
			);
		}
	}

	painter.drawImage(0, 0, q_image_);
	stat_dialog_->update_stats();
}

void canvas_window::repaint_daemon(canvas_window* window)
{
	while(!window->closed_)
	{
		window->update();
		Sleep(30);
	}
}

void canvas_window::mouseDoubleClickEvent(QMouseEvent* event)
{
	if(stat_dialog_state_)
	{
		stat_dialog_->hide();
	}
	else
	{
		stat_dialog_->show();
	}
	stat_dialog_state_ = !stat_dialog_state_;
}

