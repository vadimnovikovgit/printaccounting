#include "user.h"

user::user()
{

}

QString user::getUName() const
{
    return uName;
}

void user::setUName(const QString &value)
{
    uName = value;
}

QString user::getULogin() const
{
    return uLogin;
}

void user::setULogin(const QString &value)
{
    uLogin = value;
}

int user::getUId() const
{
    return uId;
}

void user::setUId(const int &value)
{
    uId = value;
}

bool user::getUIsAdmin() const
{
    return uIsAdmin;
}

void user::setUIsAdmin(bool value)
{
    uIsAdmin = value;
}
