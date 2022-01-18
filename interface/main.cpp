#include "interface.h"
#include <QtWidgets/QApplication>
#include<QString>
#include<QtSql/qsqldatabase.h>
#include<QtSql/qsqltablemodel.h>
#include<QtSql/qsqlerror.h>
#include<qsqlquery.h>//������ѯ����
#include <QApplication>			
#include <QDebug>
#include <QMessageBox>
#include<stu_chooseclass.h>
#include <qgsapplication.h>
#include "QGIS.h"

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif
bool OpenDatabase()
{
  	QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");   //���ݿ���������ΪSQL Server
	qDebug() << "ODBC driver?" << db.isValid();
	//QString dsn = QString::fromLocal8Bit("tt");      //����Դ����
	db.setHostName("localhost");                        //ѡ�񱾵�����
	db.setDatabaseName("tt");                            //��������Դ����
	db.setUserName("sa");                               //��¼�û�
	db.setPassword("tiantian0916");                           //����
	
	if (!db.open())                                      //�����ݿ�
	{
		qDebug() << db.lastError().text();
		QMessageBox::critical(0, QObject::tr("Database error"), db.lastError().text());
		return false;                                   //��ʧ��
	}
	else
		qDebug() << "database open success!";
	return true;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QgsApplication a(argc, argv, true);
	//QgsApplication::setPrefixPath("D:/VS+Qgis/qgis���ο�������/qgis/qgis-dev", true);
	//QgsApplication::initQgis();    //��ʼ��QGISӦ��
	QGIS w;
    interface w;
	if (!OpenDatabase())
		return 1;
    w.show();
	
    return a.exec();
}
