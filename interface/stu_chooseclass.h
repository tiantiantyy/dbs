#pragma once

#include <QWidget>
#include "ui_stu_chooseclass.h"

class stu_chooseclass : public QWidget
{
	Q_OBJECT

public:
	stu_chooseclass(QWidget *parent = Q_NULLPTR);
	~stu_chooseclass();
	void stu_chooseclass::initTableWidget();//��Ķ���
	QString stu_chooseclass::receive_input_per(QString info);//ѧ��ѧ�Ž���
	QString sno_class;
public slots:
	//void on_pushbutton_chooseclass_clicked();//ѡ�ΰ�ť
	void tbSearchByText(QString text);//��������
protected:
	//void stu_chooseclass::showinfo_class();//���ݿ�ѧ�Ų�ѯ
	//void stu_chooseclass::stu_class();
private:
	Ui::stu_chooseclass ui;
};
