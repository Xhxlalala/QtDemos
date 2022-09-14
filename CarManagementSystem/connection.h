#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>
#include "qdom.h"


static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setHostName("easybook-3313b0");
    db.setDatabaseName("data.db");
    db.setUserName("xhx");
    db.setPassword("123456");

    if(!db.open())
    {
        // 错误
        return false;
    }

    QSqlQuery query;

    // 创建厂家表
    query.exec("create table factory(id varchar primary key,name varchar)");
    query.exec(QString("insert into factory values('0', '请选择厂家')"));
    query.exec(QString("insert into factory values('01', '小鹏')"));
    query.exec(QString("insert into factory values('02', '理想')"));
    query.exec(QString("insert into factory values('03', '蔚来')"));

    // 创建品牌表
    query.exec("create table brand(id varchar primary key,name varchar,factory varchar,price int,sum int,sell int,last int)");
    query.exec(QString("insert into brand values('01', '小鹏P1', '小鹏', 36, 50, 10, 40)"));
    query.exec(QString("insert into brand values('02', '小鹏P2', '小鹏', 34, 20, 5, 15)"));
    query.exec(QString("insert into brand values('03', '小鹏P3', '小鹏', 41, 80, 20, 60)"));
    query.exec(QString("insert into brand values('04', '理想one', '理想', 83, 40, 15, 25)"));
    query.exec(QString("insert into brand values('05', '理想L9', '理想', 39, 50, 15, 35)"));
    query.exec(QString("insert into brand values('06', '理想x', '理想', 28, 60, 10, 50)"));
    query.exec(QString("insert into brand values('07', '蔚来es6', '蔚来', 27, 70, 20, 50)"));
    query.exec(QString("insert into brand values('08', '蔚来es7', '蔚来', 25, 75, 25, 50)"));
    query.exec(QString("insert into brand values('09', '蔚来et5', '蔚来', 27, 65, 20, 45)"));

    //创建密码表
    query.exec("create table password(pwd varchar primary key)");
    query.exec("insert into password values('123456')");


    return true;

}


static bool createXml()
{
    QFile file("data.xml");
    if(file.exists())return true;
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return false;
    QDomDocument doc;
    QDomProcessingInstruction instruction;
    instruction = doc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"UTF-8\"");
    doc.appendChild(instruction);
    QDomElement root = doc.createElement(QString("日销售清单"));
    doc.appendChild(root);
    QTextStream out(&file);
    doc.save(out,4);
    file.close();
    return true;
}

#endif // CONNECTION_H
