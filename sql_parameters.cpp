#include "sql_parameters.h"
#include "ui_sql_parameters.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QtDebug>


sql_parameters::sql_parameters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sql_parameters)
{
    ui->setupUi(this);
}

sql_parameters::~sql_parameters()
{
    delete ui;
}



QString sql_parameters::getDBname() const
{
    return DBname;
}

void sql_parameters::setDBname(const QString &value)
{
    DBname = value;
}

QString sql_parameters::getDBserver() const
{
    return DBserver;
}

void sql_parameters::setDBserver(const QString &value)
{
    DBserver = value;
}

QString sql_parameters::getLogin() const
{
    return login;
}

void sql_parameters::setLogin(const QString &value)
{
    login = value;
}

QString sql_parameters::getPwd() const
{
    return pwd;
}

void sql_parameters::setPwd(const QString &value)
{
    pwd = value;
}

bool sql_parameters::getAuth() const
{
    return auth;
}

void sql_parameters::setAuth(bool value)
{
    auth = value;
}

QString sql_parameters::getSQLmsg() const
{
    return SQLmsg;
}

void sql_parameters::setSQLmsg(const QString &value)
{
    SQLmsg = value;
}




QString sql_parameters::connect_todb()
{
    if(this->auth==true)
    {
        db_handle = QSqlDatabase::addDatabase("QODBC3");
        db_handle.setDatabaseName("DRIVER={SQL Server};SERVER="+DBserver+";DATABASE="+DBname+";Trusted_Connection=yes;");
       // db.setUserName("sa");
        //db.setPassword("Password123");
        if(!db_handle.open())
        {

           return QSqlError(db_handle.lastError()).text();
            //ui->textEdit->insertPlainText(QSqlError(db.lastError()).text());
        }
        else
        {
            return "Подключение успешно";
        }
    }
    return "";
}

void sql_parameters::close_connection()
{
    db_handle.close();
}

//QString sql_parameters::SQL_auth(QString query)
//{
//    int i = 0;
//    QSqlQuery query_to_db;
//    query_to_db.exec(query);
//    qDebug() << query_to_db.record().count();
//    query_to_db.next();
//    while (i<5){
//       // query_to_db.nextResult();
//        qDebug() << query_to_db.value(i).toString();
//        i++;
//    }
//    return "good";
//}
