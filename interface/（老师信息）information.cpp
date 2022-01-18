#include "information.h"
#include<QtSql/qsqlquery.h>
#include<QSqlQueryModel>
#include<QTableView>
#include<QLineEdit>
#include<QTextEdit>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>


extern int techinfo_trigger;
information::information(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setFixedSize(1658, 1088);
	ui.lineEdit_te->setPlaceholderText(QString::fromLocal8Bit("��������ҵĽ�ʦ����/ѧԺ/ְλ"));
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	connect(ui.lineEdit_te, SIGNAL(textChanged(QString)), this, SLOT(findinfo()));

	connect(ui.te_insertbtn, &QPushButton::clicked, [=]() {
		techinfo_trigger = 1;
		teinfo_change = new admin_teacherinfo;
		teinfo_change->show();
		
	});
	connect(ui.te_updatebtn, &QPushButton::clicked, [=]() {
		techinfo_trigger = 2;
		teinfo_change = new admin_teacherinfo;
		teinfo_change->show();

	});
	connect(ui.te_deletebtn, &QPushButton::clicked, [=]() {
		techinfo_trigger = 3;
		teinfo_change = new admin_teacherinfo;
		teinfo_change->show();
	});
	connect(ui.outputbtn, &QPushButton::clicked, [=]() {
		su_output();
	});
}

information::~information()
{
}

void information::teacher_init()//�������ݿ���ʦ��Ϣ
{
	QSqlQueryModel *model = new QSqlQueryModel;
	QString sql;
	sql = "select tno,tname,tsdept,tposition,tel from Teacher";
	model->setQuery(sql);
	ui.tableView->setModel(model);
}
void information::findinfo()//����
{
	QSqlQueryModel *modell = new QSqlQueryModel;
	QString find, sql0;
	find = ui.lineEdit_te->text();
	sql0 = "select tno,tname,tsdept,tposition,tel from Teacher where tname LIKE '%" + find + "%'or tposition LIKE '%" + find + "%'or tsdept LIKE '%" + find + "%'";
	modell->setQuery(sql0);
	ui.tableView->setModel(modell);

}

void information::su_output()
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
			QMessageBox::about(NULL, "��ʾ", "�ļ��򿪴������ݵ���ʧ��");
		}
	}
}