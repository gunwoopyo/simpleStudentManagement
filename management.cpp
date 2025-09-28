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
        if (manageHead == nullptr) {
            manageHead = newStudent;
        }
        else {
            student* currentStudent = manageHead;
            while (currentStudent->studentNext != nullptr) {
                currentStudent = currentStudent->studentNext;
            }
            currentStudent->studentNext = newStudent;
            newStudent->studentPrev = currentStudent;
        }

        course* newCourse = new course(courseName, grade);
        newStudent->courseList = newCourse;
}


void management::deleteStudent(int studentID){
    student* currentStudent = manageHead;
    while(currentStudent != nullptr){
        if(currentStudent->getStudentID() == studentID) {

            if(currentStudent->studentPrev == nullptr) {   // 맨첫번째 노드일 경우니까 Prev 는 널이다.
                if(currentStudent->studentNext == nullptr) {
                    manageHead == nullptr;
                    delete currentStudent;
                    return;
                }
                manageHead = currentStudent->studentNext;
                currentStudent->studentNext->studentPrev = nullptr;

            }
            else if(currentStudent->studentNext == nullptr) {
                currentStudent->studentPrev->studentNext = currentStudent->studentNext;
            }

            else {    // 중간 노드일 경우
                currentStudent->studentPrev->studentNext = currentStudent->studentNext;
                currentStudent->studentNext->studentPrev = currentStudent->studentPrev;
            }
            delete currentStudent;
        }
        currentStudent = currentStudent->studentNext;
    }
}
void management::debugStudentList() {
    int index = 0;

    qDebug() << "======================================================================================";
    if(management::manageHead == nullptr) {
        qDebug() << "Student list is empty";
        return ;
    }
    student* currentStudent = management::manageHead;
    while(currentStudent != nullptr) {
        qDebug() <<  "학번" << currentStudent->getStudentID()  << " 노드"  << index  <<   " 이전 주소" << currentStudent->studentPrev <<
            " 현재 주소 :" << currentStudent <<" 다음주소 :" << currentStudent->studentNext;
        currentStudent = currentStudent ->studentNext;
        index++;
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
    student* currentStudent = manageHead;
        while(currentStudent != nullptr) {
        if(currentStudent->getStudentID() == studentID){
                return false;
        }
        currentStudent = currentStudent->studentNext;
    }
        return true;
}







