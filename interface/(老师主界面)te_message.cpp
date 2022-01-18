#include "te_message.h"
#include<QSqlQuery>

te_message::te_message(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(1395, 900);
	
	//connect(ui.myclassbtn, &QPushButton::clicked, [=]() {
	//	personalclass *myclass;
	//	myclass = new personalclass;
	//	myclass->show();
	//	myclass->peisonalclass_init();//�����ҵĿγ���Ϣ
	//});

	//connect(ui.gradebtn, &QPushButton::clicked, [=]() {
	//	grade *mygrade = new grade;
	//	mygrade->show();
	//	mygrade->grade_init();//�������ݿ�γ���Ϣ
	//});
	connect(ui.infobtn, &QPushButton::clicked, [=]() {
		searchtno();
		person_te = new te_personalinfo;
		person_te->receive_input_per_te(tno_te);
		person_te->show();

	});//���ظ�����Ϣ

	connect(ui.exitsystembtn_2, &QPushButton::clicked, [=]() {
		this->close();

	});
	connect(ui.stu_infobtn, &QPushButton::clicked, [=]() {
		searchtno();
		mystudent *mystu = new mystudent;
		mystu->show();
		mystu->receive_id_mystu(tno_te);//�鿴�ҵ�ѧ��
	});
	
	connect(ui.myclassbtn_2, &QPushButton::clicked, [=]() {
		searchtno();
		te_myclass *mycl= new te_myclass;
		mycl->show();
		mycl->receive_id_mycla(tno_te);//�鿴�ҵĿγ�
	});
	
	connect(ui.chooseclassbtn_2, &QPushButton::clicked, [=]() {
		searchtno();
		addcourse *addcla = new addcourse;
		addcla->show();
		addcla->receive_id_adacla(tno_te);//���ӿγ�
	});
	connect(ui.gradebtn_2, &QPushButton::clicked, [=]() {
		searchtno();
		te_grantgrade *grant = new te_grantgrade;
		grant->show();
		grant->receive_id_grade(tno_te);//�������
	});
	connect(ui.seeroombtn_2, &QPushButton::clicked, [=]() {
		searchtno();
		classroom *room = new classroom;
		room->show();
	});
	

}

te_message::~te_message()
{
}
QString te_message::receive_input(QString info)
{
	inputName_te = info;
	return inputName_te;
}
void te_message::searchtno()
{
	QSqlQuery query;
	QString sql0 = "select tno from load_te where name='" + inputName_te + "'";//���û�����
	query.exec(sql0);
	while (query.next())
	{
		tno_te = query.value(0).toString();
	}
}