#include "location.h"

location::location(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

location::~location()
{
}
QString location::receive_site(QString info)//��ʦ���Ž���
{
	csite = info;
	//init_mystu();
	return csite;
}
