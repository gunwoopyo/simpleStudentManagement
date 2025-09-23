#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "management.h"
#include "student.h"
#include <QMessageBox>


student* management::manageHead = nullptr;


// Definition insertStudent()
void management::insertStudent(int studentID, QString name, QString major, int year) {

        student* newStudent = new student(studentID, name, major, year);   // 객체 생
        if (manageHead== nullptr)   // 시스템의 헤드포인터가 널이면 바로 삽입.
            manageHead = newStudent;
        else { // 헤드포인터가 널이 아니면--> student 객체가 있으면
            student* current = manageHead;
            while (current->studentNext != nullptr) {
                current = current->studentNext;
            }
            // while 문 빠져나와 current next가 널일 때 링크드 리스트로 연결
            current->studentNext = newStudent;
            newStudent->studentPrev = current;
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








