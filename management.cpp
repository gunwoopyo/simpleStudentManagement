#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "management.h"
#include "student.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
student* management::manageHead = nullptr;
void management::insertStudent(int studentID, QString name, QString major, int year) {
        student* newStudent = new student(studentID, name, major, year);
        if (manageHead == nullptr) {                 // 시스템의 헤드포인터가 널이면 바로 삽입.
            manageHead = newStudent;
        }
        else {                                     // 헤드포인터가 널이 아니면--> student 객체가 있으면
            student* current = manageHead;
            while (current->studentNext != nullptr) {
                current = current->studentNext;
            }
            // while 문 빠져나와 current next가 널일 때 링크드 리스트로 연결
            current->studentNext = newStudent;
            newStudent->studentPrev = current;
        }
        QSqlDatabase db = QSqlDatabase::database();
        QSqlQuery query(db);
        query.prepare("INSERT INTO student (studentID, name, major, year) " "VALUES (:id, :name, :major, :year)");
        query.bindValue(":id", studentID);
        query.bindValue(":name", name);
        query.bindValue(":major", major);
        query.bindValue(":year", year);

        if(!query.exec()) {
            qDebug() << "학생 DB 추가 실패:" << query.lastError().text();
        } else {
            qDebug() << "학생 DB 추가 성공!";
        }
}

void management::deleteStudent(int studentID){
    student* current = manageHead;
    while(current != nullptr){
        if(current->getStudentID() == studentID) {
            int deleteStudentID =current->getStudentID();

            if(current->studentPrev == nullptr) {   // first node
                manageHead = current->studentNext;
            }
            else {    // middle or last node
                current->studentPrev->studentNext = current->studentNext;
            }

            QSqlDatabase db = QSqlDatabase::database();
            QSqlQuery query(db);
            query.prepare("DELETE FROM student WHERE studentID = :stnID");
            query.bindValue(":stnID", deleteStudentID);
            if(!query.exec()) {
                qDebug() << "학생 DB 삭제 실패:" << query.lastError().text();
            } else {
                qDebug() << "학생 DB 삭제 성공!!!!";
            }
            delete current;
    }
        current = current->studentNext;
    }
}






void management::addCourse(student* stn, QString n, double g) {
    course* newCourse = new course(n, g);

    course* current = stn->courseList;

    if(current == nullptr) {
        current->setCourseName(n);
        current->setGrade(g);
    }
    else{
        while(current != nullptr){
            current = current->courseNext;
        }
        current->courseNext = newCourse;
        newCourse->coursePrev = current;
    }
}





student* management::searchStudentID(int studentID) {
    student* current = manageHead;
    while (current != nullptr) {
        if(current->getStudentID() == studentID){
            return current;
        }
        current = current->studentNext;
    }
    return nullptr;
}


void management::updateGrade(student* s, QString courseName, double grade) {
    course* c = s->courseList;
    while(c != nullptr) {
        if(c->getCourseName() == courseName){
            c->setGrade(grade);
        }
        c = c->courseNext;
    }
}

bool management::checkStudentID(int studentID) {
    student* current = management::manageHead;
    while(current != nullptr) {
        if(current->getStudentID() == studentID){
            return true;
        }
        current = current->studentNext;
    }
    return false;
}











