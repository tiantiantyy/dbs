#pragma once

#include <QWidget>
#include "ui_te_personalinfo.h"
#include "updatemycode.h"
#include "updatecode_te.h"

class te_personalinfo : public QWidget
{
	Q_OBJECT

public:
	te_personalinfo(QWidget *parent = Q_NULLPTR);
	~te_personalinfo();
	QString tno_chuan;//��ʦ����
	QString te_personalinfo::receive_input_per_te(QString info);//��ʦ���Ž���
protected:
	void te_personalinfo::te_showinfo();//��ѯ���ݿ��ʦ��Ϣ
private:
	Ui::te_personalinfo ui;
};
