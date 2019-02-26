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
	this->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
	repainter_ = std::thread(repaint_daemon, this);

	stat_dialog_ = new stat_dialog(ga, this);

	stat_dialog_->show();

	dimensions& dim = ga.get_goal_image().dimensions_;
	const auto a = dim.width > dim.height ? dim.width : dim.height;
	zoom_ = 1000 / a;
	this->setFixedSize(dim.width * zoom_, dim.height * zoom_);

	this->setFixedSize(ga.get_goal_image().dimensions_.width * zoom_, ga.get_goal_image().dimensions_.height * zoom_);

	pixels_ = new QRgb[width()*height()];
	image_ = image(width(), height());
	
	q_image_ = QImage(reinterpret_cast<uchar*>(pixels_), width(), height(), QImage::Format_RGB32);
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

	if (ga_.best_solution == nullptr)return;

	{
		std::lock_guard<std::mutex> lg(ga_.best_solution_mutex);

		delete[] best_solution_;
		best_solution_ = new rectangle_solution(*ga_.best_solution);

		image_.draw_solution(*best_solution_, zoom_);
	}
	QPainter painter(this);

	for (int x = 0; x < width(); ++x) {
		for (int y = 0; y < height(); ++y) {
			pixels_[x + y * width()] = QRgb(
				(image_.data_[x + y * width()].at(0) << 16) +
				(image_.data_[x + y * width()].at(1) << 8) +
				(image_.data_[x + y * width()].at(2))
			);
		}
	}

	painter.drawImage(0, 0, q_image_);
	stat_dialog_->update_stats();
}

void canvas_window::repaint_daemon(canvas_window* window)
{
	QEvent repaint(QEvent::UpdateRequest);
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

