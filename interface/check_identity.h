#pragma once

#include <QWidget>
#include "ui_check_identity.h"

class check_identity : public QWidget
{
	Q_OBJECT

public:
	check_identity(QWidget *parent = Q_NULLPTR);
	~check_identity();
	void check_identity::pushButton_checked();
	void check_identity::pushButton_checked_te();
	QString receive_input(QString info);
signals:
	void send_id(QString);//����id��Ϣ
public slots:
	//void receive_input(QString info);//����inputName

private:
	Ui::check_identity ui;
	QString inputName_chuan;
};
