#pragma once

#include <QWidget>
#include "ui_classroom.h"
#include "location.h"

class classroom : public QWidget
{
	Q_OBJECT

public:
	classroom(QWidget *parent = Q_NULLPTR);
	~classroom();
	void classroom::initTableWidget();//��Ķ���
public slots:
	void SearchByText(QString text);//��������
protected:
	//void classroom::su_output();
private:
	Ui::classroom ui;
};
