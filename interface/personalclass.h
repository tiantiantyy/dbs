#pragma once

#include <QWidget>
#include "ui_personalclass.h"

class personalclass : public QWidget
{
	Q_OBJECT

public:
	personalclass(QWidget *parent = Q_NULLPTR);
	~personalclass();
	void peisonalclass_init();//�������ݿ�γ���Ϣ
	QString personalclass::receive_input_perclass(QString info);//ѧ��ѧ�Ž���
public slots:
	void findinfo_per();//����
private:
	Ui::personalclass ui;
	QString sno_perclass;

};
