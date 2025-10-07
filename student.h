#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
#include "course.h"
class student {
private:
    int studentID;
    QString name;
    QString major;
    QString year;
    double GPA;
public:
    course* courseList;

    student* studentPrev;
    student* studentNext;

    student(int ID, QString n, QString m, QString y) : studentID(ID), name(n), major(m), year(y), courseList(nullptr), studentPrev(nullptr), studentNext(nullptr) { }

    int getStudentID() { return studentID; }
    QString getName() { return name; }
    QString getMajor() { return major; }
    QString getYear() { return year; }
    double getGPA() { return GPA; }
    double SetGPA(double g) { this->GPA = g; }
    double calculateGPA(student* stn, double g);

public slots:
};


#endif // STUDENT_H
