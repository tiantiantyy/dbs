#include "addcourse.h"
#include<QSqlQueryModel>
#include<QMessageBox>
#include<QSqlQuery>
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
addcourse::addcourse(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(906,774);
	ui.lineEdit_cno->setPlaceholderText("���������/ɾ���Ŀγ̺�(����)");
	//ui.lineEdit_tno->setPlaceholderText("��������ȷ�Ľ�ʦ����");
	//ui.lineEdit_cname->setPlaceholderText("��������ȷ�Ľ�ʦ����");
	ui.lineEdit_cname->setPlaceholderText("������γ���(���ʱ����)");
	ui.lineEdit_credit->setPlaceholderText("������γ�ѧ��(���ʱ����)");
	ui.lineEdit_ctime->setPlaceholderText("�������Ͽο�ʼʱ��(���ʱ����)");
	ui.lineEdit_cnum->setPlaceholderText("�������Ͽ�ѧ������(���ʱ����)");
	ui.lineEdit_csite->setPlaceholderText("��������ȷ���Ͽεĵص�(���ʱ����)");
	connect(ui.ensurebtn, &QPushButton::clicked, [=]() {
		addc();

	});
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		delc();

	});
	connect(ui.exitbtn, &QPushButton::clicked, [=]() {
		this->close();

	});
}

addcourse::~addcourse()
{
}
QString addcourse::receive_id_adacla(QString info)//��ʦ���Ž���
{
	tno_add = info;
	setitem();
	return tno_add;
}
void addcourse::delc()
{
	QSqlQuery query;
	QString sql_judge;
	QString cno_if;
	QString cno_exist = ui.lineEdit_cno->text();
	
	sql_judge = "select cno from Course where cno='" + cno_exist + "'and ctno='"+tno_add+"' ";
	query.exec(sql_judge);
	while (query.next())
	{
		cno_if = query.value(0).toString();
	}
	if (cno_if == NULL)
		//�γ̴���
	{
		QMessageBox::about(NULL, "����", "�γ̺Ų�����");

	}
	else
	{
		QString cno, cname, ctype, ctno, ctname, credit, ctime, cnum, csite;
		cno = ui.lineEdit_cno->text();
		cname = ui.lineEdit_cname->text();
		
		QString sql;
		QSqlQuery query;
		sql = "delete from Course where cno='" + cno_if + "'and ctno='" + tno_add + "' ";
		if (query.exec(sql))
		{
			QMessageBox msg;
			msg.setText("��ȷ��Ҫɾ���γ̣�");
			msg.setInformativeText("ȷ����ϵͳ��ɾ���ÿγ̣�����ɾ��ѧ����ص�ѡ����Ϣ");
			msg.setStandardButtons(QMessageBox::Yes);
			msg.setDefaultButton(QMessageBox::No);
			int ret = msg.exec();
			switch (ret) {
			case QMessageBox::Yes:
				this->close();
				QMessageBox::about(NULL, "��ʾ", "ɾ���ɹ�");
				break;//ȷ��ɾ��
			default:
				break;
			}

		}
		else
		{
			QMessageBox::about(NULL, "����", "���ݿ�δִ��");
		}


	}



}
void addcourse::addc() {

	QSqlQuery query;
	QString sql_judge,cno_if;
	QString cno_exist=ui.lineEdit_cno->text();
	sql_judge = "select cno from Course where cno='" + cno_exist + "'and ctno='" + tno_add + "' ";
	query.exec(sql_judge);
	while (query.next())
	{
		cno_if = query.value(0).toString();
	}
	if (cno_if != NULL)
		//�γ̴���
	{
		QMessageBox::about(NULL, "��ʾ", "�γ̺��Ѵ���");

	}
	else 
	{
		QString cno, cname, ctype, ctno, ctname, credit, ctime, cnum, csite;
		cno = ui.lineEdit_cno->text();
		cname = ui.lineEdit_cname->text();
		ctype = ui.comboBox_ctype->currentText();
		ctno = ui.lineEdit_tno->text();
		ctname = ui.lineEdit_tname->text();
		credit = ui.lineEdit_credit->text();
		ctime = ui.lineEdit_ctime->text();
		cnum = ui.lineEdit_cnum->text();
		csite = ui.lineEdit_csite->text();
		QString sql;
		sql = "insert into Course values('" + cno + "','" + cname + "','" + ctype + "','" + ctno + "','" + ctname + "','" + credit + "','" + ctime + "','"+cnum+"','" + csite + "')";
		if (query.exec(sql))
		{
			this->close();
			QMessageBox::about(NULL, "��ʾ", "��ӳɹ�");
		}
		else 
		{
			QMessageBox::about(NULL, "����", "��Ϣ���������¼��");
		}


	}
}
void addcourse::setitem()
{
	ui.lineEdit_tno->setText(tno_add);
	QString sql_tname_find, tname_if;
	QSqlQuery query1;
	sql_tname_find = "select tname from Teacher where tno='" + tno_add + "'";
	query1.exec(sql_tname_find);
	while (query1.next())
	{
		tname_if = query1.value(0).toString();
	}
	ui.lineEdit_tname->setText(tname_if);
}