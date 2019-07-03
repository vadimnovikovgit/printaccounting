#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sql_parameters.h"
#include "ui_sql_parameters.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QLabel>
#include <QFile>
#include "user.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    //проверка файла config.ini
    void check_config();
    ~MainWindow();

    void JsonParseData(QString str);
    void getHash(QString);
private slots:
    void on_action_triggered();
    void on_exitButton_clicked();

    void on_EnterButton_clicked();

private:
    Ui::MainWindow *ui;
    QLabel *SQLstatus;
    QString login, pwd;
    sql_parameters* SQLvar;
    user *CurUser;

};

#endif // MAINWINDOW_H
