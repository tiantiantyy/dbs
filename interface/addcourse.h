#pragma once

#include <QWidget>
#include "ui_addcourse.h"

class addcourse : public QWidget
{
	Q_OBJECT

public:
	addcourse(QWidget *parent = Q_NULLPTR);
	~addcourse();
	QString addcourse::receive_id_adacla(QString info);//��ʦ���Ž���
protected:
	void addcourse::addc();//��ӿγ�
	void addcourse::delc();//ɾ���γ�
	void addcourse::setitem();//����tno��tname
private:
	Ui::addcourse ui;
	QString tno_add;
};
