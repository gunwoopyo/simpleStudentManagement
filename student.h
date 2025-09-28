#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "course.h"


class student {
private:
    int studentID;
    QString name;
    QString major;
    int year;
    double GPA;

public:
    course* courseList;

    student* studentPrev;
    student* studentNext;

    student(int ID, QString n, QString m, int y)
        : studentID(ID), name(n), major(m), year(y),
        courseList(nullptr), studentPrev(nullptr), studentNext(nullptr) {}

    int getStudentID() { return studentID; }
    QString getName() { return name; }
    QString getMajor() { return major; }
    int getYear() { return year; }
    double getGPA() { return GPA; }





public slots:
};


#endif // STUDENT_H
