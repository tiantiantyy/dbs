#pragma once

#include <QWidget>
#include "ui_location.h"

class location : public QWidget
{
	Q_OBJECT

public:
	location(QWidget *parent = Q_NULLPTR);
	~location();
	QString location::receive_site(QString info);//ΩÃ “∫≈Ω” ’
private:
	Ui::location ui;
	QString csite;
};
