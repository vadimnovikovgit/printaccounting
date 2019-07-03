#ifndef USER_H
#define USER_H
#include <QString>

class user
{
public:
    user();

    QString getUName() const;
    void setUName(const QString &value);

    QString getULogin() const;
    void setULogin(const QString &value);

    int getUId() const;
    void setUId(const int &value);

    bool getUIsAdmin() const;
    void setUIsAdmin(bool value);

private:
    QString uLogin, uName;
    int uId;
    bool uIsAdmin;

};

#endif // USER_H
