#include "mainwindow.h"
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QCoreApplication>
#include <QApplication>
#include <QSqlQuery>
#include "management.h"


student* management::manageHead = nullptr;


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
        qDebug() << "====================================================================================================";
    }

    QSqlQuery query("SELECT s.studentID, s.name, s.major, s.year, e.courseName, e.grade FROM student s INNER JOIN enrollment e ON s.studentID = e.studentID;");


    while (query.next()) {
        int studentID = query.value(0).toInt();
        QString name = query.value(1).toString();
        QString major = query.value(2).toString();
        QString year = query.value(3).toString();
        QString courseName = query.value(4).toString();
        QString grade = query.value(5).toString();



        student* current  =  management::manageHead;

        student* targetStudent = nullptr;

        while(current != nullptr){
            if(current->getStudentID() == studentID){
                targetStudent = current;  // 이미 있는 학생
                break;
            }
            current = current->studentNext;
        }
        if(targetStudent == nullptr) {
            targetStudent = new student(studentID, name, major, year);

            if(management::manageHead == nullptr) {
                management::manageHead = targetStudent;
            } else {
                current = management::manageHead;
                while(current->studentNext != nullptr) {
                    current = current ->studentNext;
                }
                current->studentNext = targetStudent;
                targetStudent->studentPrev = current;
            }
        }
        course* newCourse = new course(courseName, grade);

        if(targetStudent->courseList == nullptr) {
            targetStudent->courseList = newCourse;
        }
        else {
            course* currentCourse = targetStudent->courseList;
            while(currentCourse->courseNext != nullptr) {
                currentCourse = currentCourse->courseNext;
            }
            currentCourse->courseNext = newCourse;
            newCourse->coursePrev = currentCourse;
        }
    }


    MainWindow w;
    w.show();

    return a.exec();
    db.close();

}

