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
#include "new_rect_mutation.h"
#include "config.h"

RectangleAproximator::RectangleAproximator(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Set validators for all inputs
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

	ui.newRectMutationLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.newRectMutationLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));

	ui.crossoverLineEdit->setValidator(new QDoubleValidator(0, 1, 5));
	ui.crossoverLineEdit_2->setValidator(new QDoubleValidator(0, 1, 5));

	ui.K_numberLineEdit->setValidator(new QIntValidator(0, INT_MAX));
	ui.K_numberLineEdit_2->setValidator(new QIntValidator(0, INT_MAX));

	//Fixate the size of the window
	this->setFixedSize(this->size());
}

RectangleAproximator::~RectangleAproximator() = default;

void RectangleAproximator::on_sourceFileButton_clicked()
{
	//Opens file dialog and sets text to the input line eidt
	QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::currentPath(), "Image File(*.*)");
	ui.srcFileLineEdit->setText(filename);
}

void RectangleAproximator::on_startButton_clicked()
{
	//Get image path
	std::wstring image_path = ui.srcFileLineEdit->text().toStdWString();

	// Check if file exists and if yes: Is it really a file and no directory?
	QFileInfo check_file(QString::fromStdWString(image_path));
	if (!(check_file.exists() && check_file.isFile())) {
		QMessageBox error_msg;
		error_msg.setText("Selected file doesn't exist!");
		error_msg.exec();
		return;
	}

	//Initializing genetic algorithm class
	image goal_image(image_path);
	const std::wstring image_name = image_path.substr(image_path.find_last_of('/') + 1);

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
		goal_image.dimensions_
	);
	const mutation_wrapper sm1w(sm1, std::stod(ui.swapMutationLineEdit->text().toStdWString()));
	swap_mutation sm2(
		goal_image.dimensions_
	);
	const mutation_wrapper sm2w(sm2, std::stod(ui.swapMutationLineEdit_2->text().toStdWString()));

	new_rect_mutation nrm1(
		goal_image.dimensions_
	);
	const mutation_wrapper nrm1w(nrm1, std::stod(ui.newRectMutationLineEdit->text().toStdWString()));
	swap_mutation nrm2(
		goal_image.dimensions_
	);
	const mutation_wrapper nrm2w(nrm2, std::stod(ui.newRectMutationLineEdit_2->text().toStdWString()));


	const double total_secondary1 = std::stod(ui.secondaryMutationLineEdit->text().toStdWString());
	const double total_secondary2 = std::stod(ui.secondaryMutationLineEdit_2->text().toStdWString());

	total_mutation tm1({lrm1w, bgm1w, rrm1w, sm1w, nrm1w}, total_secondary1);
	total_mutation tm2({lrm2w, bgm2w, rrm2w, sm2w, nrm2w }, total_secondary2);

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

	//Start training
	std::thread ga_thread(genetic_algorithm::run, &ga);

	//Hide until cw is done executing
	this->hide();
	cw.exec();
	this->show();

	//Join training thread
	ga.stop();
	ga_thread.join();
}

void RectangleAproximator::on_saveConfigButton_clicked()
{
	QString filename = QFileDialog::getSaveFileName(this, tr("Open file"), QDir::currentPath(), "*.txt");

	//If file dialog gets canceled, cancel the saving
	if (filename.isEmpty())
	{
		return;
	}

	std::wstring savefile = filename.toStdWString();

	config c;

	c.population_size = std::stoi(ui.populationSizeLineEdit->text().toStdString());
	c.rectangles = std::stoi(ui.rectanglesLineEdit->text().toStdString());
	c.iterations_per_rectangle = std::stoi(ui.rectangleIterationLineEdit->text().toStdString());
	c.cleanup_iterations = std::stoi(ui.cleanupLineEdit->text().toStdString());
	c.switches_after = std::stoi(ui.switchesLineEdit->text().toStdString());

	c.mutations_secondary = std::stod(ui.secondaryMutationLineEdit->text().toStdString());
	c.mutations_secondary_2 = std::stod(ui.secondaryMutationLineEdit_2->text().toStdString());

	c.mutations_last_rect = std::stod(ui.lastRectMutationLineEdit->text().toStdString());
	c.mutations_last_rect_2 = std::stod(ui.lastRectMutationLineEdit_2->text().toStdString());
	c.mutations_last_rect_alpha = std::stod(ui.lastRectMutationAlphaLineEdit->text().toStdString());
	c.mutations_last_rect_alpha_2 = std::stod(ui.lastRectMutationAlphaLineEdit_2->text().toStdString());
	c.mutations_last_rect_mutation = std::stod(ui.lastRectMutationMutationLineEdit->text().toStdString());
	c.mutations_last_rect_mutation_2 = std::stod(ui.lastRectMutationMutationLineEdit_2->text().toStdString());
	c.mutations_last_rect_new = std::stod(ui.lastRectMutationNewGeneLineEdit->text().toStdString());
	c.mutations_last_rect_new_2 = std::stod(ui.lastRectMutationNewGeneLineEdit_2->text().toStdString());

	c.mutations_background = std::stod(ui.backgroundMutationLineEdit->text().toStdString());
	c.mutations_background_2 = std::stod(ui.backgroundMutationLineEdit_2->text().toStdString());
	c.mutations_background_alpha = std::stod(ui.backgroundMutationAlphaLineEdit->text().toStdString());
	c.mutations_background_alpha_2 = std::stod(ui.backgroundMutationAlphaLineEdit_2->text().toStdString());
	c.mutations_background_mutation = std::stod(ui.backgroundMutationMutationLineEdit->text().toStdString());
	c.mutations_background_mutation_2 = std::stod(ui.backgroundMutationMutationLineEdit_2->text().toStdString());
	c.mutations_background_new = std::stod(ui.backgroundMutationNewGeneLineEdit->text().toStdString());
	c.mutations_background_new_2 = std::stod(ui.backgroundMutationNewGeneLineEdit_2->text().toStdString());

	c.mutations_random = std::stod(ui.randomMutationLineEdit->text().toStdString());
	c.mutations_random_2 = std::stod(ui.randomMutationLineEdit_2->text().toStdString());
	c.mutations_random_rectangles = std::stoi(ui.randomMutationRectanglesLineEdit->text().toStdString());
	c.mutations_random_rectangles_2 = std::stoi(ui.randomMutationRectanglesLineEdit_2->text().toStdString());
	c.mutations_random_alpha = std::stod(ui.randomMutationAlphaLineEdit->text().toStdString());
	c.mutations_random_alpha_2 = std::stod(ui.randomMutationAlphaLineEdit_2->text().toStdString());
	c.mutations_random_mutation = std::stod(ui.randomMutationMutationLineEdit->text().toStdString());
	c.mutations_random_mutation_2 = std::stod(ui.randomMutationMutationLineEdit_2->text().toStdString());
	c.mutations_random_new = std::stod(ui.randomMutationNewGeneLineEdit->text().toStdString());
	c.mutations_random_new_2 = std::stod(ui.randomMutationNewGeneLineEdit_2->text().toStdString());

	c.mutations_swap = std::stod(ui.swapMutationLineEdit->text().toStdString());
	c.mutations_swap_2 = std::stod(ui.swapMutationLineEdit_2->text().toStdString());

	c.mutations_new = std::stod(ui.newRectMutationLineEdit->text().toStdString());
	c.mutations_new_2 = std::stod(ui.newRectMutationLineEdit_2->text().toStdString());

	c.crossover_chance = std::stod(ui.crossoverLineEdit->text().toStdString());
	c.crossover_chance_2 = std::stod(ui.crossoverLineEdit_2->text().toStdString());

	c.selection_kfactor = std::stoi(ui.K_numberLineEdit->text().toStdString());
	c.selection_kfactor_2 = std::stoi(ui.K_numberLineEdit_2->text().toStdString());

	c.save(savefile);
}

void RectangleAproximator::on_loadConfigButton_clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::currentPath(), "Image File(*.*)");
	std::wstring fn = filename.toStdWString();
	config c;

	c.load(fn);
	std::string tmp = std::to_string(c.population_size);
	ui.populationSizeLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.rectangles);
	ui.rectanglesLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.iterations_per_rectangle); 
	ui.rectangleIterationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.cleanup_iterations);
	ui.cleanupLineEdit->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.mutations_secondary);
	ui.secondaryMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_secondary_2);
	ui.secondaryMutationLineEdit_2->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.mutations_last_rect);
	ui.lastRectMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_last_rect_2);
	ui.lastRectMutationLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_last_rect_alpha);
	ui.lastRectMutationAlphaLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_last_rect_alpha_2);
	ui.lastRectMutationAlphaLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_last_rect_mutation);
	ui.lastRectMutationMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_last_rect_mutation_2);
	ui.lastRectMutationMutationLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_last_rect_new);
	ui.lastRectMutationNewGeneLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_last_rect_new_2);
	ui.lastRectMutationNewGeneLineEdit_2->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.mutations_background);
	ui.backgroundMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_background_2);
	ui.backgroundMutationLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_background_alpha);
	ui.backgroundMutationAlphaLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_background_alpha_2);
	ui.backgroundMutationAlphaLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_background_mutation);
	ui.backgroundMutationMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_background_mutation_2);
	ui.backgroundMutationMutationLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_background_new);
	ui.backgroundMutationNewGeneLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_background_new_2);
	ui.backgroundMutationNewGeneLineEdit_2->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.mutations_random);
	ui.randomMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_2);
	ui.randomMutationLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_rectangles);
	ui.randomMutationRectanglesLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_rectangles_2);
	ui.randomMutationRectanglesLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_alpha);
	ui.randomMutationAlphaLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_alpha_2);
	ui.randomMutationAlphaLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_mutation);
	ui.randomMutationMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_mutation_2);
	ui.randomMutationMutationLineEdit_2->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_new);
	ui.randomMutationNewGeneLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_random_new_2);
	ui.randomMutationNewGeneLineEdit_2->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.mutations_swap);
	ui.swapMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_swap_2);
	ui.swapMutationLineEdit_2->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.mutations_new);
	ui.newRectMutationLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.mutations_new_2);
	ui.newRectMutationLineEdit_2->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.crossover_chance);
	ui.crossoverLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.crossover_chance_2);
	ui.crossoverLineEdit_2->setText(QString::fromStdString(tmp));

	tmp = std::to_string(c.selection_kfactor);
	ui.K_numberLineEdit->setText(QString::fromStdString(tmp));
	tmp = std::to_string(c.selection_kfactor_2);
	ui.K_numberLineEdit_2->setText(QString::fromStdString(tmp));
}
