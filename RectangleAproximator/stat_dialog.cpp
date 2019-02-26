#include "stat_dialog.h"
#include <QFileDialog>
#include <QMessageBox>

stat_dialog::stat_dialog(genetic_algorithm& ga, QWidget *parent)
	: QDialog(parent), ga_(ga)
{
	setupUi(this);
	//Disable close and minimize, and set the window title
	setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	setWindowTitle("Stats");
}

stat_dialog::~stat_dialog() = default;

void stat_dialog::update_stats() const
{
	//Retrieve stats and post them to the stat window
	static double max_avg_error = ga_.get_goal_image().dimensions_.width * ga_.get_goal_image().dimensions_.height * 3 * 128;
	this->relativeErrorResultLabel->setText(QString::fromStdWString(std::to_wstring(-ga_.best_solution->fitness/max_avg_error)));
	this->iterationCounterLabel->setText(QString::fromStdWString(std::to_wstring(ga_.current_iteration)));
	this->fitnessResultLabel->setText(QString::fromStdWString(std::to_wstring(static_cast<int>(ga_.best_solution->fitness))));;
	this->rectangleConuterLabel->setText(QString::fromStdWString(std::to_wstring(ga_.best_solution->current_rectangles)));;
}

void stat_dialog::on_saveButton_clicked()
{
	//When the save button is clicked, the mutex is locked, and the genetic algorithm loop gets halted
	std::lock_guard<std::mutex> lg(ga_.run_mutex);

	//Opens save file dialog
	QString filename = QFileDialog::getSaveFileName(this, tr("Open file"), QDir::currentPath(), "*.jpg");

	//If file dialog gets canceled, cancel the saving
	if(filename.isEmpty())
	{
		return;
	}

	//Get save and zoom parameters
	std::wstring src_file = filename.toStdWString();
	const unsigned zoom = std::stoi(this->zoomLineEdit->text().toStdWString());

	//Create "canvas", draw best solution and save the image
	image result_image(ga_.get_goal_image().dimensions_.width * zoom, ga_.get_goal_image().dimensions_.height * zoom);
	result_image.draw_solution(*ga_.best_solution, zoom);
	result_image.save(src_file);
}
