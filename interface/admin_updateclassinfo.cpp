//#include "admin_updateclassinfo.h"
//#include<QSqlQuery>
//#include<QMessageBox>
//#ifdef WIN32  
//#pragma execution_character_set("utf-8")  
//#endif
//
//admin_updateclassinfo::admin_updateclassinfo(QWidget *parent)
//	: QWidget(parent)
//{
//	ui.setupUi(this);
//	this->setFixedSize(906, 774);
//	ui.lineEdit_cno->setPlaceholderText("�����޸ĵĿγ̺�(����)");
//	ui.lineEdit_tno->setPlaceholderText("��������ȷ�Ľ�ʦ����(����)");
//	ui.lineEdit_tname->setPlaceholderText("��������ȷ�Ľ�ʦ����(����)");
//	ui.lineEdit_cname->setPlaceholderText("������γ���(����)");
//	ui.lineEdit_credit->setPlaceholderText("������γ�ѧ��(����)");
//	ui.lineEdit_ctime->setPlaceholderText("�������Ͽο�ʼʱ��(����)");
//	ui.lineEdit_cnum->setPlaceholderText("�������Ͽ�ѧ������(����))");
//	ui.lineEdit_csite->setPlaceholderText("��������ȷ���Ͽεĵص�(����)");
//	connect(ui.ensurebtn, &QPushButton::clicked, [=]() {
//		class_updatebtn_clicked();//�޸Ŀγ���Ϣ
//	});
//
//
//
//
//}
//
//admin_updateclassinfo::~admin_updateclassinfo()
//{
//}
//
//void admin_updateclassinfo::class_updatebtn_clicked()
//{
//	QSqlQuery query;
//	QString sql_judge, cno_if;
//	QString cno_exist = ui.lineEdit_cno->text();
//	sql_judge = "select cno from Course where cno='" + cno_exist + "'";
//	query.exec(sql_judge);
//	while (query.next())
//	{
//		cno_if = query.value(0).toString();
//	}
//	if (cno_if == NULL)
//		//�γ̲�����
//	{
//		QMessageBox::about(NULL, "����", "�γ̺Ų�����");
//
//	}
//	else
//	{
//		QString cno, cname, ctype, ctno, ctname, credit, ctime, cnum, csite;
//		cno = ui.lineEdit_cno->text();
//		cname = ui.lineEdit_cname->text();
//		ctype = ui.comboBox_ctype->currentText();
//		ctno = ui.lineEdit_tno->text();
//		ctname = ui.lineEdit_tname->text();
//		credit = ui.lineEdit_credit->text();
//		ctime = ui.lineEdit_ctime->text();
//		cnum = ui.lineEdit_cnum->text();
//		csite = ui.lineEdit_csite->text();
//		QString sql;
//		sql = "update Course set cno='" + cno + "',cname='" + cname + "',ctype='" + ctype + "',ctno='" + ctno + "',ctname='" + ctname + "',credit='" + credit + "',ctime='" + ctime + "',cnum='" + cnum + "',csite='" + csite + "'";
//		if (query.exec(sql))
//		{
//			this->close();
//			QMessageBox::about(NULL, "��ʾ", "�޸ĳɹ�");
//		}
//		else
//		{
//			QMessageBox::about(NULL, "����", "��Ϣ���������¼��");
//		}
//
//
//	}
//
//
//
//
//
//}
