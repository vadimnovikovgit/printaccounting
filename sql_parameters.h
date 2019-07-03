#ifndef SQL_PARAMETERS_H
#define SQL_PARAMETERS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class sql_parameters;
}

class sql_parameters : public QDialog
{
    Q_OBJECT

public:
    explicit sql_parameters(QWidget *parent = nullptr);
    ~sql_parameters();
     QSqlQuery *query_to_db;


    QString getDBname() const;
    void setDBname(const QString &value);

    QString getDBserver() const;
    void setDBserver(const QString &value);

    QString getLogin() const;
    void setLogin(const QString &value);

    QString getPwd() const;
    void setPwd(const QString &value);

    bool getAuth() const;
    void setAuth(bool value);

    QString connect_todb();

    QString getSQLmsg() const;
    void setSQLmsg(const QString &value);

    void close_connection();

     QString SQL_auth(QString);

private:
    Ui::sql_parameters *ui;
    QString DBname;
    QString DBserver;
    QString login;
    QString pwd;
    QString SQLmsg;
    QSqlDatabase db_handle;

    bool auth = false;

};

#endif // SQL_PARAMETERS_H
