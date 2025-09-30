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
void management::insertStudent(int studentID, QString name, QString major, QString year, QString courseName, QString grade) {
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
    while(currentStudent != nullptr) {
        if(currentStudent->getStudentID() == studentID) {
            if(currentStudent->studentPrev == nullptr) {
                if (currentStudent->studentNext == nullptr) {
                    // 노드가 마지막 1개 존재하는 경우.
                    manageHead = nullptr;
                } else {
                    // 헤드 노드가 가리키는 맨첫번째 노드인 경우
                    manageHead = currentStudent->studentNext;
                    currentStudent->studentNext->studentPrev = nullptr;
                }
            }

            else if(currentStudent->studentNext == nullptr) {
                currentStudent->studentPrev->studentNext = currentStudent->studentNext;
            }

            else {    // 중간 노드일 경우
                currentStudent->studentPrev->studentNext = currentStudent->studentNext;
                currentStudent->studentNext->studentPrev = currentStudent->studentPrev;
            }
            delete currentStudent;
            return;
        }
        currentStudent = currentStudent->studentNext;
    }
}

void management::debugInsertList() {
    int index = 0;

    qDebug() << "===================================================================================================";
    if(management::manageHead == nullptr) {
        qDebug() << "Student list is empty";
        return ;
    }
    student* currentStudent = management::manageHead;
    while(currentStudent != nullptr) {
        qDebug()<<"학번"<<currentStudent->getStudentID()<<" 이름"<<currentStudent->getName()<<"학년"<<currentStudent->getYear()<<" 전공"<<currentStudent->getMajor()<< " 수강과목"
                 << currentStudent->courseList->getCourseName()<<" 점수"<<currentStudent->courseList->getGrade()<<
            " 노드"<<index  <<   " 이전 주소" << currentStudent->studentPrev <<
            " 현재 주소 :" << currentStudent <<" 다음주소 :" << currentStudent->studentNext;
        currentStudent = currentStudent ->studentNext;
        index++;
    }
}

void management::debugCourseList() {
    qDebug() << "======================================================================================";
    if(management::manageHead->courseList == nullptr) {
        qDebug() << "Student courseList is empty";
        return;
    } else {
        student* currentStudent = management::manageHead;
        while(currentStudent != nullptr) {
            course* currentCourse = currentStudent->courseList;
            while(currentCourse != nullptr) {
                qDebug() <<  "학번" << currentStudent->getStudentID()  <<  " 추가한 과목 " << currentCourse->getCourseName()   <<   " 이전 과목 주소" << currentCourse->coursePrev <<
                    " 현재 주소 :" << currentCourse <<" 다음주소 :" << currentCourse->courseNext;
                currentCourse = currentCourse->courseNext;
            }
            return;
        }
    }
}

void management::addCourse(student* stn, QString n, QString g) {
    course* newCourse = new course(n, g);
    if(stn->courseList == nullptr) {
        stn->courseList = newCourse;
        newCourse->coursePrev = nullptr;
    }
    else {
        course* currentCourse = stn->courseList;
        while(currentCourse->courseNext != nullptr){
            currentCourse = currentCourse->courseNext;
        }
        currentCourse->courseNext = newCourse;
        newCourse->coursePrev = currentCourse;
    }
}

void management::deleteCourse(student* stn, QString courseName) {
    course* currentCourse = stn->courseList;
    while(currentCourse != nullptr) {
        if(currentCourse->getCourseName() == courseName)
        {  // 지우려는 객체로 진입
            if(currentCourse->coursePrev == nullptr){
                if(currentCourse->courseNext == nullptr) {;
                    stn->courseList = nullptr;
                }
                else {
                    stn->courseList = currentCourse->courseNext ;
                    currentCourse->courseNext->coursePrev = nullptr;
                    qDebug() << "지울 주소 :" << currentCourse;
                }
            }
            else if (currentCourse->coursePrev != nullptr && currentCourse->courseNext != nullptr) {
                currentCourse->coursePrev->courseNext = currentCourse->courseNext;
                currentCourse->courseNext->coursePrev = currentCourse->coursePrev;
            }
            else {
                currentCourse->coursePrev->courseNext = nullptr;
            }
            delete currentCourse;
            return;
        }
        currentCourse = currentCourse->courseNext;
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

void management::updateGrade(student* stn, QString courseName, QString grade) {
    course* currentCourse = stn->courseList;
    while(currentCourse != nullptr) {
        if(currentCourse->getCourseName() == courseName){
            currentCourse->setGrade(grade);
        }
        currentCourse = currentCourse->courseNext;
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







