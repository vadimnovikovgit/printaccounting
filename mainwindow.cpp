#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QString>
#include <QJsonDocument>
#include <QtDebug>
#include <QLabel>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    check_config();

    ui->setupUi(this);
    SQLstatus = new QLabel(this);
    SQLstatus->setText("Connected to "+SQLvar->getDBserver());
    ui->statusBar->addPermanentWidget(SQLstatus);
    ui->passwordForm->setEchoMode(QLineEdit::Password);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::check_config()
{
    QFile configFile(QDir::current().path()+"\\config.json");
    QString val;
    //Проверка файла конфига
    if(configFile.exists())
    {
        SQLvar = new sql_parameters();
        configFile.open(QIODevice::ReadOnly | QIODevice::Text);
        val = configFile.readAll();
        configFile.close();
        JsonParseData(val);
        SQLvar->setSQLmsg(SQLvar->connect_todb());

    }
    else
    {
        SQLvar = new sql_parameters();
        SQLvar->show();
    }

}

void MainWindow::on_action_triggered()
{
    SQLvar = new sql_parameters();
    SQLvar->show();
}


void MainWindow::JsonParseData(QString str)
{

    QJsonDocument doc = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject sett2 = doc.object();
    SQLvar->setDBserver(sett2["database_server"].toString());
    SQLvar->setDBname(sett2["database_name"].toString());
    if(sett2["trusted_connection"].toString()=="yes")
    {
        SQLvar->setAuth(true);
    }
    else {
        SQLvar->setAuth(false);
        SQLvar->setLogin(sett2["login"].toString());
        SQLvar->setLogin(sett2["password"].toString());

    }

}

void MainWindow::getHash(QString hashstr)
{
    QByteArray arr = QCryptographicHash::hash(hashstr.toUtf8(), QCryptographicHash::Sha1).toHex();
    pwd = arr;
}



void MainWindow::on_exitButton_clicked()
{
   QApplication::quit();
}

void MainWindow::on_EnterButton_clicked()
{
    if(ui->loginForm->text().isEmpty() || ui->passwordForm->text().isEmpty())
    {
        QMessageBox::warning(this,"Ошибка","Не введен логин или пароль");
    }
    else
    {
        getHash(ui->passwordForm->text());
        login = ui->loginForm->text();
        QString query = "SELECT [ID] \
                ,[Name] \
                ,[Login] \
                ,[Password]\
                ,[isAdmin] FROM [Cartriges].[dbo].[Users] where Login =\'"+login+"\' and Password =\'"+pwd+"\'";
        SQLvar->query_to_db = new QSqlQuery;
        SQLvar->query_to_db->exec(query);
        if(!SQLvar->query_to_db->last())
            QMessageBox::warning(this,"Ошибка","Не верный логин или пароль");
        else {
            CurUser = new user;
            SQLvar->query_to_db->first();
            CurUser->setUId(SQLvar->query_to_db->value(0).toInt());
            CurUser->setUName(SQLvar->query_to_db->value(1).toString());
            CurUser->setULogin(SQLvar->query_to_db->value(2).toString());
            CurUser->setUIsAdmin(SQLvar->query_to_db->value(4).toBool());
            qDebug() << CurUser->getUId();
            qDebug() << CurUser->getUName();
            qDebug() << CurUser->getULogin();
            qDebug() << CurUser->getUIsAdmin();
        }
        delete SQLvar->query_to_db;
    }
}
