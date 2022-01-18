#include "admin_teacherinfo.h"
#include<QSqlQueryModel>
#include<QMessageBox>
#include<qlineedit.h>
#include<qpushbutton.h>
#include<QSqlQuery>
int techinfo_trigger;
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

admin_teacherinfo::admin_teacherinfo(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowModality(Qt::ApplicationModal);//���ô���ģ̬
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		if(techinfo_trigger==1)
			on_pushButton_teacherinsert_clicked();
		if (techinfo_trigger==2)
			on_pushButton_teacherinsert_clicked();
		if (techinfo_trigger == 3)
			on_pushButton_dele_clicked();

	});//�����ʦ��Ϣ

}

admin_teacherinfo::~admin_teacherinfo()
{
}
void admin_teacherinfo::on_pushButton_teacherinsert_clicked()
{
	QString tno, tname, tsdept,tposition,tel;
	tno = ui.lineEdit_tno->text();
	tname = ui.lineEdit_tname->text();
	tsdept = ui.lineEdit_tsdept->text();
	tposition = ui.lineEdit_tposition->text();
	tel = ui.lineEdit_tel->text();
	QSqlQuery query;
	QString sql1;
	sql1 = "select count (*) from	Teacher where tno='" + tname + "'";
	query.exec(sql1);
	QString realtno;
	while (query.next())
	{
		realtno = query.value(0).toString();
	}
	if (realtno!=NULL)
	{
		QMessageBox::about(NULL, "����", "ϵͳ��������λ��ʦ");
	}
	else
	{
		QString sql2;
		QSqlQueryModel *model2 = new QSqlQueryModel;
		sql2 = "insert into Teacher values ('" + tno + "','" + tname + "','" + tsdept + "','" + tposition + "','" + tel + "')";
		model2->setQuery(sql2);
		this->close();
		QMessageBox::about(NULL, "��ʾ", "ϵͳ��Ϣ��ӳɹ�");


	}
}
void admin_teacherinfo::on_pushButton_dele_clicked()
{
	QString tno, tname, tsdept,tposition,tel;
	tno = ui.lineEdit_tno->text();
	tname = ui.lineEdit_tname->text();
	tsdept = ui.lineEdit_tsdept->text();
	tposition = ui.lineEdit_tposition->text();
	tel = ui.lineEdit_tel->text();
	QString sql,sql2,realtno;
	sql2 = "select count (*) from Teacher where tno='" + tno + "'and tname='" + tname + "'";
	QSqlQuery query;
	query.exec(sql2);
	while (query.next())
	{
		realtno = query.value(0).toString();
	}
	if (realtno==NULL)
	{
		QMessageBox::about(NULL, "����", "ϵͳ�в��޴���");
	}
	else
	{

		sql = "delete from Teacher where tno='" + tno + "'and tname='" + tname + "'";
		query.exec(sql);
		this->close();
		QMessageBox::about(NULL, "��ʾ", "ɾ���ɹ�");
	}
}
void admin_teacherinfo::te_updatebtn_clicked() {//���°�ť����
	QString tno, tname, tsdept, tposition, tel;
	tno = ui.lineEdit_tno->text();
	tname = ui.lineEdit_tname->text();
	tsdept = ui.lineEdit_tsdept->text();
	tposition = ui.lineEdit_tposition->text();
	tel = ui.lineEdit_tel->text();

	QString sql1;
	sql1 = "select count (*) from Teacher where tno='" + tno + "'";
	QSqlQuery query;
	query.exec(sql1);
	QString realtno;
	while (query.next())
	{
		realtno = query.value(0).toString();
	}
	if (realtno==NULL)
	{
		QMessageBox::about(NULL, "����", "ϵͳ��û����λ��ʦ");
	}
	else
	{
		QString sql2;
		QSqlQueryModel *model2 = new QSqlQueryModel;
		sql2 = "update Teacher set tno='" + tno + "',tname='" + tname + "',tsdept='" + tsdept + "',tposition='" + tposition + "',tel='" + tel + "' where tno='" + tno + "'";
		model2->setQuery(sql2);
		this->close();
		QMessageBox::about(NULL, "��ʾ", "ϵͳ��Ϣ�޸ĳɹ�");

	}


}