#pragma once

#include <QWidget>
#include "ui_admin_changeclass.h"

class admin_changeclass : public QWidget
{
	Q_OBJECT

public:
	admin_changeclass(QWidget *parent = Q_NULLPTR);
	~admin_changeclass();
protected:
	void on_pushButton_enter_clicked();//���
	void class_updatebtn_clicked();//�Ŀ�
	void delbtn_clicked();//ɾ��
private:
	Ui::admin_changeclass ui;
};
