#include "stu_message.h"
#include<QSqlQuery>

stu_message::stu_message(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(1395, 900);
	
	connect(ui.myclassbtn, &QPushButton::clicked, [=]() {
		personalclass *myclass = NULL;
		myclass = new personalclass;
		searchsno();
		myclass->receive_input_perclass(sno_load);
		myclass->show();
		myclass->peisonalclass_init();//�����ҵĿγ���Ϣ
	});

	connect(ui.gradebtn, &QPushButton::clicked, [=]() {
		grade *mygrade = new grade;
		searchsno();
		mygrade->receive_input_grade(sno_load);
		mygrade->show();
		mygrade->grade_init();//�������ݿ�γ���Ϣ

	});
	connect(ui.infobtn, &QPushButton::clicked, [=]() {
		searchsno();
		personalinfo *person_stu = NULL;
		person_stu = new personalinfo;
		person_stu->receive_input_per(sno_load);
		person_stu->show();

	});//���ظ�����Ϣ
	connect(ui.chooseclassbtn, &QPushButton::clicked, [=]() {
		stu_chooseclass *stuc = NULL;
		stuc = new stu_chooseclass;
		searchsno();
		stuc->receive_input_per(sno_load);
		stuc->show();//�������ݿ�ѡ����Ϣ

	});
	connect(ui.seeroombtn, &QPushButton::clicked, [=]() {
		classroom *room = new classroom;
		room->show();
	});//ѡ�����

	connect(ui.exitsystembtn, &QPushButton::clicked, [=]() {
		this->close();

	});
	

}

stu_message::~stu_message()
{
}
QString stu_message::receive_input(QString info)
{
	inputName_stu = info;
	return inputName_stu;
}
void stu_message::searchsno()
{
	QSqlQuery query;
	QString sql0 = "select sno from load where name='" + inputName_stu + "'";//���û�ѧ��
	query.exec(sql0);
	while (query.next())
	{
		sno_load = query.value(0).toString();
	}
	
}