#pragma once

#include <QWidget>
#include "ui_grade.h"
#include "grade.h"

class grade : public QWidget
{
	Q_OBJECT

public:
	grade(QWidget *parent = Q_NULLPTR);
	~grade();
	void grade::grade_init();//�������ݿ�ѧ����Ϣ
	QString grade::receive_input_grade(QString info);//ѧ��ѧ�Ž���
protected:
	/*void grade::point();*/

private:
	Ui::grade ui;
	QString sno_grade;
};

