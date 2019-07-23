#ifndef ADMIN_WND_H
#define ADMIN_WND_H

#include <QWidget>

namespace Ui {
class admin_wnd;
}

class admin_wnd : public QWidget
{
    Q_OBJECT

public:
    explicit admin_wnd(QWidget *parent = nullptr);
    ~admin_wnd();

private:
    Ui::admin_wnd *ui;
};

#endif // ADMIN_WND_H
