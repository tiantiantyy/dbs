#pragma once

#include <QWidget>
#include "ui_personalinfo.h"
#include "updatemycode.h"

class personalinfo : public QWidget
{
	Q_OBJECT

public:
	personalinfo(QWidget *parent = Q_NULLPTR);
	~personalinfo();
	QString sno_per;//ѧ��ѧ��
	QString receive_input_per(QString info);//ѧ��ѧ�Ž���
	void personalinfo::showinfo();
protected:
	

private:
	Ui::personalinfo ui;
	
};
