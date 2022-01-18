#include "check_identity.h"
#include<qsqlquery.h>
#include<qmessagebox.h>
#include<qpushbutton.h>
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

extern int idwho;
check_identity::check_identity(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		
		if(idwho==1)//ѧ�����
			pushButton_checked();
		else
			pushButton_checked_te();
	});
	connect(ui.pushButton_2, &QPushButton::clicked, [=]() {
		this->close();
	});
	



}

check_identity::~check_identity()
{
}
void check_identity::pushButton_checked()
{
	QString sno_again, sql_stu, sql_succeed,idmess;
	idmess = ui.lineEdit->text();
	sql_stu = "select sno from load where sno='" + idmess + "'";

	sql_succeed="update load set sno='"+idmess+"'where name='"+inputName_chuan+"'";
	QSqlQuery query;
	query.exec(sql_stu);
	while (query.next())
	{
		sno_again = query.value(0).toString();
	}
	if (sno_again != 0)
		QMessageBox::about(NULL, "����", "��Ϣ�Ѱ�");
	else
	{
		//��Student/teacher�����Ƿ���ѧ�Ż��߹���
		//if�� �󶨳ɹ�
		QSqlQuery query2;
		QString sql_find, sno_find;
		sql_find = "select sno from Student where sno='" + idmess + "'";
		query2.exec(sql_find);
		while (query2.next())
		{
			sno_find = query2.value(0).toString();
		}
		if (sno_find != NULL)
		{
			query.exec(sql_succeed);
			QMessageBox::about(NULL, "��ʾ", "�󶨳ɹ�");
			emit send_id(idmess);
			this->close();
		}
		else// �� ��ʧ�� ������
		{
			QMessageBox::about(NULL, "����", "�����ѧ����Ϣ����ʧ��");
		}
	}
}
void check_identity::pushButton_checked_te()
{
	QString sno_again, sql_stu, sql_succeed, idmess;
	idmess = ui.lineEdit->text();
	sql_stu = "select tno from load_te where tno='" + idmess + "'";

	sql_succeed = "update load_te set tno='" + idmess + "'where name='" + inputName_chuan + "'";
	QSqlQuery query;
	query.exec(sql_stu);
	while (query.next())
	{
		sno_again = query.value(0).toString();
	}
	if (sno_again != 0)
		QMessageBox::about(NULL, "����", "��Ϣ�Ѱ�");
	else
	{
		//��Student/teacher�����Ƿ���ѧ�Ż��߹���
		//if�� �󶨳ɹ�
		QSqlQuery query2;
		QString sql_find,tno_find;
		sql_find = "select tno from Teacher where tno='" + idmess + "'";
		query2.exec(sql_find);
		while (query2.next())
		{
			tno_find = query2.value(0).toString();
		}
		if (tno_find != NULL)
		{
			query.exec(sql_succeed);
			QMessageBox::about(NULL, "��ʾ", "�󶨳ɹ�");
			emit send_id(idmess);
			this->close();
		}
		else// �� ��ʧ�� ������
		{
			QMessageBox::about(NULL, "����", "����ع�����Ϣ����ʧ��");
		}
	}
}
QString check_identity::receive_input(QString info)
{
	inputName_chuan = info;
	return inputName_chuan;
}