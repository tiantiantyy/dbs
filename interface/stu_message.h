#pragma once

#include <QWidget>
#include "ui_stu_message.h"
#include "stu_chooseclass.h"
#include "personalclass.h"
#include "grade.h"
#include"personalinfo.h"
#include "classroom.h"

class stu_message : public QWidget
{
	Q_OBJECT

public:
	stu_message(QWidget *parent = Q_NULLPTR);
	~stu_message();
	QString inputName_stu;//ѧ���û���
	QString sno_load;//ѧ��ѧ��
	QString receive_input(QString info);//ѧ���û���
protected:
	void searchsno();
private:
	Ui::stu_message ui;

};
