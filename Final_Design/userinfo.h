#ifndef USERINFO_H
#define USERINFO_H
#include "QDate"

//extern QString usr_str;
//extern QString pwd_str;

class UserInfo
{
private:
    //登录用户的信息
    QString No;
    QString username ;
    QString gender;
    QString date;
    QString department;
    QString position;
    QString telephone;
    QString email;
    QString role;
    QString photograph;
    QString pwd;
public:
    UserInfo();
    UserInfo(const QString &No, const QString &username, const QString &gender, const QString &date, const QString &department, const QString &position, const QString &telephone, const QString &email, const QString &role, const QString &photograph, const QString &pwd);
    QString getNo() const;
    void setNo(const QString &newNo);
    QString getUsername() const;
    void setUsername(const QString &newUsername);
    QString getPwd() const;
    void setPwd(const QString &newPwd);
    QString getGender() const;
    void setGender(const QString &newGender);
    QString getPosition() const;
    void setPosition(const QString &newPosition);
    QString getRole() const;
    void setRole(const QString &newRole);
    QString getDate() const;
    void setDate(const QString &newDate);
    QString getDepartment() const;
    void setDepartment(const QString &newDepartment);
    QString getTelephone() const;
    void setTelephone(const QString &newTelephone);
    QString getEmail() const;
    void setEmail(const QString &newEmail);
    QString getPhotograph() const;
    void setPhotograph(const QString &newPhotograph);
};


extern UserInfo usr;        //定义全局变量记录用户信息

#endif // USERINFO_H
