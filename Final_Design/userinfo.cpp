#include "userinfo.h"


UserInfo usr; //全局变量，记录用户信息

QString UserInfo::getNo() const
{
    return No;
}

void UserInfo::setNo(const QString &newNo)
{
    No = newNo;
}

QString UserInfo::getUsername() const
{
    return username;
}

void UserInfo::setUsername(const QString &newUsername)
{
    username = newUsername;
}

QString UserInfo::getPwd() const
{
    return pwd;
}

void UserInfo::setPwd(const QString &newPwd)
{
    pwd = newPwd;
}

QString UserInfo::getGender() const
{
    return gender;
}

void UserInfo::setGender(const QString &newGender)
{
    gender = newGender;
}

QString UserInfo::getPosition() const
{
    return position;
}

void UserInfo::setPosition(const QString &newPosition)
{
    position = newPosition;
}

QString UserInfo::getRole() const
{
    return role;
}

void UserInfo::setRole(const QString &newRole)
{
    role = newRole;
}

QString UserInfo::getDate() const
{
    return date;
}

void UserInfo::setDate(const QString &newDate)
{
    date = newDate;
}

QString UserInfo::getDepartment() const
{
    return department;
}

void UserInfo::setDepartment(const QString &newDepartment)
{
    department = newDepartment;
}

QString UserInfo::getTelephone() const
{
    return telephone;
}

void UserInfo::setTelephone(const QString &newTelephone)
{
    telephone = newTelephone;
}

QString UserInfo::getEmail() const
{
    return email;
}

void UserInfo::setEmail(const QString &newEmail)
{
    email = newEmail;
}

QString UserInfo::getPhotograph() const
{
    return photograph;
}

void UserInfo::setPhotograph(const QString &newPhotograph)
{
    photograph = newPhotograph;
}

UserInfo::UserInfo() {}

UserInfo::UserInfo(const QString &No, const QString &username, const QString &gender, const QString &date, const QString &department, const QString &position, const QString &telephone, const QString &email, const QString &role, const QString &photograph, const QString &pwd) : No(No),
    username(username),
    gender(gender),
    date(date),
    department(department),
    position(position),
    telephone(telephone),
    email(email),
    role(role),
    photograph(photograph),
    pwd(pwd)
{}
