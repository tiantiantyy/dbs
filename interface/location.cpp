#include "location.h"

location::location(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

location::~location()
{
}
QString location::receive_site(QString info)//教师工号接收
{
	csite = info;
	//init_mystu();
	return csite;
}
