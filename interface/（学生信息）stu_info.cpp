#include "stu_info.h"
#include<QTableWidgetItem>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<qdebug.h>
#include<QMessageBox>
#include<QModelIndexList>
#include<qtableview.h>
#include<QTextEdit>
#include<QFileDialog>

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
extern int event_trigger;

stu_info::stu_info(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(1658, 1088);
	ui.lineEdit_stu->setPlaceholderText("��������ҵ�ѧ������/�༶/רҵ/ѧԺ");
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	connect(ui.lineEdit_stu, SIGNAL(textChanged(QString)), this, SLOT(find()));
	connect(ui.stu_insertbtn, &QPushButton::clicked, [=]() {
		event_trigger = 1;
		ad = new admin_change;
		ad->show();
		//qDebug() << "��ad";
		//connect(ad, SIGNAL(emit insert_succeed()), this, SLOT(init_go()));//�����ˢ�½���
		});
	connect(ui.stu_updatebtn, &QPushButton::clicked, [=]() {
		event_trigger = 2;
		ad = new admin_change;
		ad->show();
	
	});
	connect(ui.stu_btn, &QPushButton::clicked, [=]() {
		init();
	});
	connect(ui.stu_deletebtn, &QPushButton::clicked, [=]() {
		event_trigger = 3;
		ad = new admin_change;
		ad->show();

	});
	connect(ui.outputbtn, &QPushButton::clicked, [=]() {
		su_output();
	});

}

stu_info::~stu_info()
{
}

void stu_info::init()//�������ݿ�ѧ����Ϣ
{
	QSqlQueryModel *model = new QSqlQueryModel;
	QString sql;
	//sql = "select sno as ѧ��,sname as ����,sclass as �༶,ssex as �Ա�,smajor as רҵ,ssdept as �꼶,sbirth as �������� from Student";
	sql = "select sno,sname,sclass,ssex,smajor,ssdept,sbirth from Student";
	model->setQuery(sql);
	ui.tableView->setModel(model);
}
void stu_info::find()//����
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString find,sql0;
    find=ui.lineEdit_stu->text();
    sql0="select sno,sname,sclass,ssex,smajor,ssdept,sbirth from Student where sname LIKE '%"+find+"%'or sclass LIKE '%" + find + "%'or ssdept LIKE '%" + find + "%' or smajor LIKE '%" + find + "%'";
    modell->setQuery(sql0);
    ui.tableView->setModel(modell);

}
void stu_info::stu_insertbtn_clicked() {
	QSqlQueryModel *modell = new QSqlQueryModel;
	QString find, sql0;
	find = ui.lineEdit_stu->text();
	sql0 = "select sno,sname,sclass,ssex,smajor,ssdept,sbirth from Student where sname LIKE '%" + find + "%'";
	modell->setQuery(sql0);
	ui.tableView->setModel(modell);
}

void stu_info::su_output()
{
	QString filepath = QFileDialog::getSaveFileName(this, tr("Save as..."),
		QString(), tr("EXCEL files (*.xls);;HTML-Files (*.txt);;"));

	if (filepath != "")
	{
		int row = ui.tableView->model()->rowCount();
		int col = ui.tableView->model()->columnCount();
		QList<QString> list;
		//����б���
		QString HeaderRow;
		for (int i = 0; i < col; i++)
		{
			HeaderRow.append(ui.tableView->model()->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\t");
		}
		list.push_back(HeaderRow);
		for (int i = 0; i < row; i++)
		{
			QString rowStr = "";
			for (int j = 0; j < col; j++) {
				QModelIndex index = ui.tableView->model()->index(i, j);
				rowStr += ui.tableView->model()->data(index).toString() + "\t";
			}
			list.push_back(rowStr);
		}
		QTextEdit textEdit;
		for (int i = 0; i < list.size(); i++)
		{
			textEdit.append(list.at(i));
		}

		QFile file(filepath);
		if (file.open(QFile::WriteOnly | QIODevice::Text))
		{
			QTextStream ts(&file);
			ts.setCodec("GB2312");//����ط�����Լ��ж��Ƿ��á�utf-8��
			ts << textEdit.document()->toPlainText();
			file.close();
			QMessageBox::about(NULL, "��ʾ", "���ݵ����ɹ�");
		}
		else {
			QMessageBox::about(NULL,"��ʾ", "�ļ��򿪴������ݵ���ʧ��");
		}
	}
}