#include "stat_dialog.h"
#include <QFileDialog>
#include <QMessageBox>

stat_dialog::stat_dialog(genetic_algorithm& ga, QWidget *parent)
	: QDialog(parent), ga_(ga)
{
	setupUi(this);
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
}

stat_dialog::~stat_dialog() = default;

void stat_dialog::update_stats() const
{
	static double max_avg_error = ga_.get_goal_image().dimensions_.width * ga_.get_goal_image().dimensions_.height * 3 * 128;
	this->relativeErrorResultLabel->setText(QString::fromStdWString(std::to_wstring(-ga_.best_solution->fitness/max_avg_error)));
	this->iterationCounterLabel->setText(QString::fromStdWString(std::to_wstring(ga_.current_iteration)));
	this->fitnessResultLabel->setText(QString::fromStdWString(std::to_wstring(static_cast<int>(ga_.best_solution->fitness))));;
	this->rectangleConuterLabel->setText(QString::fromStdWString(std::to_wstring(ga_.best_solution->current_rectangles)));;
}

void stat_dialog::on_saveButton_clicked()
{
	std::lock_guard<std::mutex> lg(ga_.run_mutex);

	QString filename = QFileDialog::getSaveFileName(this, tr("Open file"), QDir::currentPath(), "*.jpg");

	if(filename.isEmpty())
	{
		return;
	}
	
	std::wstring src_file = filename.toStdWString();

	dimensions& dim = ga_.get_goal_image().dimensions_;
	const unsigned zoom = 1000 / (dim.width > dim.height ? dim.width : dim.height);

	image result_image(ga_.get_goal_image().dimensions_.width * zoom, ga_.get_goal_image().dimensions_.height * zoom);
	result_image.draw_solution(*ga_.best_solution, zoom);

	result_image.save(src_file);
}
