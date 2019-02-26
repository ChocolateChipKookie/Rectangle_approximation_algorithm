#include "RectangleAproximator.h"
#include <QFileDialog>
#include <QMessageBox>
#include "image.h"
#include "canvas_window.h"
#include "last_rect_mutation.h"
#include <string>
#include "background_mutation.h"
#include "random_rect_mutation.h"
#include "swap_mutation.h"
#include "mutation_wrapper.h"
#include "total_mutation.h"
#include "generic_crossover.h"
#include "tournament.h"

RectangleAproximator::RectangleAproximator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.populationSizeLineEdit->setValidator(new QIntValidator(1, INT_MAX));
	ui.rectanglesLineEdit->setValidator(new QIntValidator(1, INT_MAX));
	ui.rectangleIterationLineEdit->setValidator(new QIntValidator(1, INT_MAX));
	ui.cleanupLineEdit->setValidator(new QIntValidator(0, INT_MAX));

	ui.secondaryMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.secondaryMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));

	ui.lastRectMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.lastRectMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.lastRectMutationAlphaLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.lastRectMutationAlphaLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.lastRectMutationMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.lastRectMutationMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.lastRectMutationNewGeneLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.lastRectMutationNewGeneLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));

	ui.backgroundMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.backgroundMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.backgroundMutationAlphaLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.backgroundMutationAlphaLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.backgroundMutationMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.backgroundMutationMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.backgroundMutationNewGeneLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.backgroundMutationNewGeneLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));

	ui.randomMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.randomMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.randomMutationRectanglesLineEdit->setValidator(new QIntValidator(0, INT_MAX));
	ui.randomMutationRectanglesLineEdit_2->setValidator(new QIntValidator(0, INT_MAX));
	ui.randomMutationAlphaLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.randomMutationAlphaLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.randomMutationMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.randomMutationMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.randomMutationNewGeneLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.randomMutationNewGeneLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));

	ui.swapMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.swapMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));
	ui.swapMutationSwapsLineEdit->setValidator(new QIntValidator(0, INT_MAX));
	ui.swapMutationSwapsLineEdit_2->setValidator(new QIntValidator(0, INT_MAX));

	ui.crossoverLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.crossoverLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));

	ui.K_numberLineEdit->setValidator(new QIntValidator(0, INT_MAX));
	ui.K_numberLineEdit_2->setValidator(new QIntValidator(0, INT_MAX));

	this->setFixedSize(this->size());
}

RectangleAproximator::~RectangleAproximator()
{
}

void RectangleAproximator::on_sourceFileButton_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::currentPath(), "Image File(*.*)");
	ui.srcFileLineEdit->setText(filename);
	src_file = filename.toStdWString();
}

void RectangleAproximator::on_startButton_clicked()
{
	std::wstring image_path = ui.srcFileLineEdit->text().toStdWString();

	QFileInfo check_file(QString::fromStdWString(image_path));
	// check if file exists and if yes: Is it really a file and no directory?
	
	if (!(check_file.exists() && check_file.isFile())) {
		QMessageBox error_msg;
		error_msg.setText("Selected file doesn't exist!");
		error_msg.exec();
		return;
	}

	image goal_image(image_path);
	std::wstring image_name = image_path.substr(image_path.find_last_of('/') + 1);

	last_rect_mutation lrm1(
		std::stod(ui.lastRectMutationAlphaLineEdit->text().toStdWString()),
		std::stod(ui.lastRectMutationMutationLineEdit->text().toStdWString()),
		std::stod(ui.lastRectMutationNewGeneLineEdit->text().toStdWString()),
		goal_image.dimensions_
	);
	const mutation_wrapper lrm1w(lrm1, std::stod(ui.lastRectMutationLineEdit->text().toStdWString()));
	last_rect_mutation lrm2(
		std::stod(ui.lastRectMutationAlphaLineEdit_2->text().toStdWString()),
		std::stod(ui.lastRectMutationMutationLineEdit_2->text().toStdWString()),
		std::stod(ui.lastRectMutationNewGeneLineEdit_2->text().toStdWString()),
		goal_image.dimensions_
	);
	const mutation_wrapper lrm2w(lrm2, std::stod(ui.lastRectMutationLineEdit_2->text().toStdWString()));

	background_mutation bgm1(
		std::stod(ui.backgroundMutationAlphaLineEdit->text().toStdWString()),
		std::stod(ui.backgroundMutationMutationLineEdit->text().toStdWString()),
		std::stod(ui.backgroundMutationNewGeneLineEdit->text().toStdWString())
	);
	const mutation_wrapper bgm1w(bgm1, std::stod(ui.backgroundMutationLineEdit->text().toStdWString()));
	background_mutation bgm2(
		std::stod(ui.backgroundMutationAlphaLineEdit_2->text().toStdWString()),
		std::stod(ui.backgroundMutationMutationLineEdit_2->text().toStdWString()),
		std::stod(ui.backgroundMutationNewGeneLineEdit_2->text().toStdWString())
	);
	const mutation_wrapper bgm2w(bgm2, std::stod(ui.backgroundMutationLineEdit_2->text().toStdWString()));

	random_rect_mutation rrm1(
		std::stod(ui.randomMutationAlphaLineEdit->text().toStdWString()),
		std::stod(ui.randomMutationMutationLineEdit->text().toStdWString()),
		std::stod(ui.randomMutationNewGeneLineEdit->text().toStdWString()),
		std::stoi(ui.randomMutationRectanglesLineEdit->text().toStdWString()),
		goal_image.dimensions_
	);
	const mutation_wrapper rrm1w(rrm1, std::stod(ui.randomMutationLineEdit->text().toStdWString()));
	random_rect_mutation rrm2(
		std::stod(ui.randomMutationAlphaLineEdit_2->text().toStdWString()),
		std::stod(ui.randomMutationMutationLineEdit_2->text().toStdWString()),
		std::stod(ui.randomMutationNewGeneLineEdit_2->text().toStdWString()),
		std::stoi(ui.randomMutationRectanglesLineEdit_2->text().toStdWString()),
		goal_image.dimensions_
	);
	const mutation_wrapper rrm2w(rrm2, std::stod(ui.randomMutationLineEdit_2->text().toStdWString()));

	swap_mutation sm1(
		std::stoi(ui.swapMutationSwapsLineEdit->text().toStdWString())
	);
	const mutation_wrapper sm1w(sm1, std::stod(ui.swapMutationLineEdit->text().toStdWString()));
	swap_mutation sm2(
		std::stoi(ui.swapMutationSwapsLineEdit_2->text().toStdWString())
	);
	const mutation_wrapper sm2w(sm2, std::stod(ui.swapMutationLineEdit_2->text().toStdWString()));

	const double total_secondary1 = std::stod(ui.secondaryMutationLineEdit->text().toStdWString());
	const double total_secondary2 = std::stod(ui.secondaryMutationLineEdit_2->text().toStdWString());

	total_mutation tm1({lrm1w, bgm1w, rrm1w, sm1w}, total_secondary1);
	total_mutation tm2({lrm2w, bgm2w, rrm2w, sm2w}, total_secondary2);

	generic_crossover gc1(std::stod(ui.crossoverLineEdit->text().toStdWString()), true);
	generic_crossover gc2(std::stod(ui.crossoverLineEdit_2->text().toStdWString()), true);

	tournament t1(std::stoi(ui.K_numberLineEdit->text().toStdWString()));
	tournament t2(std::stoi(ui.K_numberLineEdit_2->text().toStdWString()));

	const unsigned population_size = std::stoi(ui.populationSizeLineEdit->text().toStdWString());
	const unsigned iterations_per_rect = std::stoi(ui.rectangleIterationLineEdit->text().toStdWString());
	const unsigned rectangles = std::stoi(ui.rectanglesLineEdit->text().toStdWString());
	const unsigned cleanup_iterations = std::stoi(ui.cleanupLineEdit->text().toStdWString());
	const unsigned cleanup_after = std::stoi(ui.switchesLineEdit->text().toStdWString());

	genetic_algorithm ga(tm1, tm2, gc1, gc2, t1, t2, cleanup_after, population_size, iterations_per_rect, rectangles, cleanup_iterations, goal_image);

	canvas_window cw(ga);
	
	cw.setWindowTitle(QString::fromStdWString(image_name));
	cw.setModal(true);

	std::thread ga_thread(genetic_algorithm::run, &ga);

	
	this->hide();
	cw.exec();
	this->show();

	ga.stop();
	ga_thread.join();

}
