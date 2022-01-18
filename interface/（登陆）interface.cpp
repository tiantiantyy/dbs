#include "interface.h"
#include"message.h"
#include "stu_message.h"
#include<QPixmap>
#include<QPushButton>
#include"message.h"
#include<qsqlquery.h>
#include<qmessagebox.h>
#include<qwidget.h>
#include<qdebug.h>
int idwho;


interface::interface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(590, 400);
	connect(ui.loadbtn, &QPushButton::clicked, [=]() {
		on_pushButton_login_clicked(); });//��¼��ť
	connect(ui.exitbtn, &QPushButton::clicked, [=]() {
		this->close();

	});//�˳���ť

	connect(ui.registerbtn, &QPushButton::clicked, [=]() {
		reg = new regist;
		reg->show();

	});//ע�ᰴť
	
	



}

void interface::on_pushButton_login_clicked()
{
	//qDebug() << "check";//�����źźͲ�
	//bool if_exists_account = false;
	QSqlQuery query;
	inputName = ui.lineEdit_name->text();
	QString inputPassword = ui.lineEdit_password->text();
	if (ui.lineEdit_name->text() == "")
	{
		QMessageBox::information(this, "��ʾ", "�������û���");
	}
	else 
	{
		if (ui.checkBox_admin->isChecked()) {
			if (inputName == "admin"&&inputPassword == "admin")
			{
			
				QMessageBox::about(NULL, "��ʾ", "����Ա��½�ɹ�");
				this->close();
				mess = new message;
				mess->QWidget::show();
				this->QWidget::close();
				return;
			}
			else
			{
				QMessageBox::about(NULL, "��ʾ", "�û������������");
			}

		}
		else
		{
			if (ui.checkBox_te->isChecked()) //��ʦ��½
			{
				query.exec(QString("SELECT password from load_te where name='%1'")
					.arg(inputName));
				QString realpassword;
				while (query.next())
				{
					realpassword = query.value(0).toString();
				}
				if (inputPassword == realpassword) {
					//if_exists_account = true;


					QMessageBox::about(NULL, "��ʾ", "��ʦ��¼�ɹ�");
					QString sql_te,tno;
					sql_te = "select tno from load_te where name='" + inputName + "'";
					query.exec(sql_te);
					while (query.next())
					{
						tno = query.value(0).toString();
					}
					if (tno != NULL)
					{
						this->close();
						te_message *te_mess = new te_message;
						te_mess->show();
						te_mess->receive_input(inputName);
						return;

					}
					else if (tno == NULL)
					{
						idwho = 2;
						check_id = new check_identity;
						check_id->QWidget::show();
						check_id->receive_input(inputName);
						connect(check_id, SIGNAL(send_id(QString)), this, SLOT(received_id(QString)));
						QMessageBox::about(NULL, "��ʾ", "�󶨳ɹ�");

						if (tno != 0)
						this->close();
						te_message *te_mess = NULL;
						te_mess=new te_message;
						te_mess->show();
						te_mess->receive_input(inputName);
						return;

					}

				}
				else
				{
					QMessageBox::about(NULL, "��ʾ", "�û������������");

				}
			}
			else if(ui.checkBox_stu->isChecked())//ѧ����½
			{
				query.exec(QString("SELECT password from load where name='%1'")
					.arg(inputName));
				QString realpassword;
				while (query.next())
				{
					realpassword = query.value(0).toString();
				}

				if (inputPassword == realpassword) {
					QMessageBox::about(NULL, "��ʾ", "ѧ����¼�ɹ�");
					QSqlQuery query;
					QString sql_stu,sno;
					sql_stu = "select sno from load where name='" + inputName + "'";
					query.exec(sql_stu);
					while (query.next())
					{
						sno = query.value(0).toString();
					}
					if (sno != NULL)
					{
						this->close();
						stu_mess = new stu_message;
						stu_mess->QWidget::show();
						stu_mess->receive_input(inputName);
						return;
					}
					else 
					{
						idwho = 1;
						check_id = new check_identity;
						check_id->show();
						check_id->receive_input(inputName);
						connect(check_id, SIGNAL(send_id(QString)), this, SLOT(received_id(QString info)));
						if (sno != 0)
						{
							this->close();
							stu_mess = new stu_message;
							stu_mess->QWidget::show();
							stu_mess->receive_input(inputName);
							return;
						}
					}
				}
				else
				{
					QMessageBox::about(NULL, "��ʾ", "�û������������");

				}
			}
			else if(!ui.checkBox_stu->isChecked()&&!ui.checkBox_te->isChecked())
			{
				QMessageBox::about(NULL, "��ʾ", "��ѡ�����");
			}

		}	
		
	}
	
}

void interface::received_id(QString info)
{
	QString receive_id_is = info;
	if (ui.checkBox_stu->isChecked())//ѧ��
	{
		QString sql_id;
		sql_id = "update load set sno='" + receive_id_is + "' where name='" + inputName + "'";
		QSqlQuery query;
		query.exec(sql_id);
	}
	else if (ui.checkBox_te->isChecked())//��ʦ
	{
		QString sql_id;
		sql_id = "update load_te set tno='" + receive_id_is + "' where name='" + inputName + "'";
		QSqlQuery query;
		query.exec(sql_id);
	}
}