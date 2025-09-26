#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "management.h"
#include "student.h"
#include "course.h"
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>



void management::insertStudent(int studentID, QString name, QString major, int year, QString courseName, QString grade) {
        student* newStudent = new student(studentID, name, major, year);
        student* current = manageHead;
        if (manageHead == nullptr) {
            manageHead = newStudent;
        }
        else {
            while (current->studentNext != nullptr) {
                current = current->studentNext;
            }
            current->studentNext = newStudent;
            newStudent->studentPrev = current;
        }



        course* newCourse = new course(courseName, grade);
        course* currentCourse = newStudent->courseList;

        if(currentCourse == nullptr) {
            currentCourse = newCourse;
        }
        else{
            while(currentCourse != nullptr){
                currentCourse = currentCourse->courseNext;
            }
            currentCourse->courseNext = newCourse;
            newCourse->coursePrev = currentCourse;
        }


        QSqlDatabase db = QSqlDatabase::database();

        QSqlQuery query1(db);
        query1.prepare("INSERT INTO student (studentID, name, major, year) VALUES (:id, :name, :major, :year)");
        query1.bindValue(":id", studentID);
        query1.bindValue(":name", name);
        query1.bindValue(":major", major);
        query1.bindValue(":year", year);
        if(!query1.exec()) {
            qDebug() << "query 1 학생 DB 추가 실패:" << query1.lastError().text();
        } else {
            qDebug() << "query 1 학생 DB 추가 성공!";
        }

        QSqlQuery query2(db);
        query2.prepare("INSERT INTO enrollment (studentID, courseName, grade) VALUES (:eID, :ename, :egrade)");
        query2.bindValue(":eID", studentID);
        query2.bindValue(":ename", courseName);
        query2.bindValue(":egrade", grade);
        if(!query2.exec()) {
            qDebug() << "query 2 학생 DB 추가 실패:" << query2.lastError().text();
        } else {
            qDebug() << "query 2 학생 DB 추가 성공!";
        }

        qDebug() << "insert head pointer : " << manageHead;
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






void management::addCourse(student* stn, QString n, QString g) {
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


void management::updateGrade(student* s, QString courseName, QString grade) {
    course* c = s->courseList;
    while(c != nullptr) {
        if(c->getCourseName() == courseName){
            c->setGrade(grade);
        }
        c = c->courseNext;
    }
}

bool management::checkStudentID(int studentID) {
    QSqlQuery query("SELECT studentID FROM student");
    while(query.next()) { // DB에서 한 행씩 읽기
        int dbStudentID = query.value(0).toInt();  // 첫번째 컬럼
            if(studentID == dbStudentID) {
                qDebug() << "Linked List와 DB에 존재 : " << dbStudentID;
                return true;
            }
    }
    return false;
}













