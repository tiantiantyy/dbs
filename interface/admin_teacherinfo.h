#pragma once

#include <QWidget>
#include "ui_admin_teacherinfo.h"

class admin_teacherinfo : public QWidget
{
	Q_OBJECT

public:
	admin_teacherinfo(QWidget *parent = Q_NULLPTR);
	~admin_teacherinfo();

private:
	Ui::admin_teacherinfo ui;
protected:
	void admin_teacherinfo::on_pushButton_teacherinsert_clicked();//�����ʦ
	void admin_teacherinfo::on_pushButton_dele_clicked();//ɾ����ʦ
	void admin_teacherinfo::te_updatebtn_clicked();//������ʦ
};
