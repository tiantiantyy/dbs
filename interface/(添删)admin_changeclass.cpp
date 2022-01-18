#include "admin_changeclass.h"
#include<QSqlQuery>
#include<QMessageBox>
#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

admin_changeclass::admin_changeclass(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(906, 774);
	ui.lineEdit_cno->setPlaceholderText("���������/ɾ���Ŀγ̺�(����)");
	ui.lineEdit_tno->setPlaceholderText("��������ȷ�Ľ�ʦ����(���ʱ����)");
	ui.lineEdit_tname->setPlaceholderText("��������ȷ�Ľ�ʦ����(���ʱ����)");
	ui.lineEdit_cname->setPlaceholderText("������γ���(���ʱ����)");
	ui.lineEdit_credit->setPlaceholderText("������γ�ѧ��(��α���)");
	ui.lineEdit_ctime->setPlaceholderText("�������Ͽο�ʼʱ��(��α���)");
	ui.lineEdit_cnum->setPlaceholderText("�������Ͽ�ѧ������(���ʱ����))");
	ui.lineEdit_csite->setPlaceholderText("��������ȷ���Ͽεĵص�(���ʱ����)");

	connect(ui.ensurebtn, &QPushButton::clicked, [=]() {
		on_pushButton_enter_clicked();
		//��ӿγ���Ϣ
	});
	connect(ui.pushButton, &QPushButton::clicked, [=]() {
		
		delbtn_clicked();//ɾ������

	});//ɾ���γ���Ϣ
	connect(ui.exitbtn, &QPushButton::clicked, [=]() {
		this->close();

	});//�˳�





}

admin_changeclass::~admin_changeclass()
{
}

void admin_changeclass::on_pushButton_enter_clicked()
{
	QSqlQuery query;
	QString sql_judge, cno_if;
	QString cno_exist = ui.lineEdit_cno->text();
	sql_judge = "select cno from Course where cno='" + cno_exist + "'";
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
		sql = "insert into Course values('" + cno + "','" + cname + "','" + ctype + "','" + ctno + "','" + ctname + "','" + credit + "','" + ctime + "','" + cnum + "','" + csite + "')";
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

void admin_changeclass::class_updatebtn_clicked()
{
	QSqlQuery query;
	QString sql_judge, cno_if;
	QString cno_exist = ui.lineEdit_cno->text();
	sql_judge = "select cno from Course where cno='" + cno_exist + "'";
	query.exec(sql_judge);
	while (query.next())
	{
		cno_if = query.value(0).toString();
	}
	if (cno_if == NULL)
		//�γ̲�����
	{
		QMessageBox::about(NULL, "����", "�γ̺Ų�����");

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
		sql = "update Course set cno='" + cno + "',cname='" + cname + "',ctype='" + ctype + "',ctno='" + ctno + "',ctname='" + ctname + "',credit='" + credit + "',ctime='" + ctime + "',cnum='" + cnum + "',csite='" + csite + "'";
		if (query.exec(sql))
		{
			this->close();
			QMessageBox::about(NULL, "��ʾ", "�޸ĳɹ�");
		}
		else
		{
			QMessageBox::about(NULL, "����", "��Ϣ���������¼��");
		}


	}

}

void admin_changeclass::delbtn_clicked()
{
	QSqlQuery query;
	QString sql_judge;
	QString cno_if;
	QString cno_exist = ui.lineEdit_cno->text();

	sql_judge = "select cno from Course where cno='" + cno_exist + "'";
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
		sql = "delete from Course where cno='" + cno_if + "'";
		
			QMessageBox msg;
			msg.setText("��ȷ��Ҫɾ���γ̣�");
			msg.setInformativeText("ȷ����ϵͳ��ɾ���ÿγ̣�����ɾ��ѧ����ص�ѡ����Ϣ");
			msg.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
			msg.setDefaultButton(QMessageBox::No);
			int ret = msg.exec();
			switch (ret) {
			case QMessageBox::Yes:
				if(query.exec(sql))
					QMessageBox::about(NULL, "��ʾ", "ɾ���ɹ�");
				else
				{
					QMessageBox::about(NULL, "����", "���ݿ�δִ��");
				}
				this->close();
				break;//ȷ��ɾ��
			case QMessageBox::No:
				this->close();
				break;//ȡ��ɾ��
			default:
				break;
			}

	

	}

}







