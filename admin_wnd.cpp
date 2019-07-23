#include "admin_wnd.h"
#include "ui_admin_wnd.h"

admin_wnd::admin_wnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::admin_wnd)
{
    ui->setupUi(this);
}

admin_wnd::~admin_wnd()
{
    delete ui;
}
