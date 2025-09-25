#include "mainwindow.h"
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    qDebug() << "드라이버" << QSqlDatabase::drivers();
    db.setHostName("localhost");      // DB 서버 주소
    db.setDatabaseName("student_db"); // 사용할 DB 이름
    db.setUserName("gunwoopyo");   // DB 사용자
    db.setPassword("rjsdn2939");   // DB 비밀번호
    db.setPort(3306);                  // 포트 (기본 3306)
    if (!db.open()) {
        qDebug() << "DB 연결 실패:" << db.lastError().text();
    } else {
        qDebug() << "DB 연결 성공!";
    }

    // 사용 후 닫기
    db.close();


    qDebug() << "Application Dir Path:" << QCoreApplication::applicationDirPath();








    MainWindow w;
    w.show();
    return a.exec();
}
