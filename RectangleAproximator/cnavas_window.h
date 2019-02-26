#pragma once

#include <QDialog>
#include "ui_cnavas_window.h"

class cnavas_window : public QDialog, public Ui::cnavas_window
{
	Q_OBJECT

public:
	cnavas_window(QWidget *parent = Q_NULLPTR);
	~cnavas_window();
};
