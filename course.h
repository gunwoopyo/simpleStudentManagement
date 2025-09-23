#ifndef COURSE_H
#define COURSE_H
#include <QString>

class course {

private:
    QString courseName;
    double grade;


public:

    course* coursePrev;
    course* courseNext;

    course(QString name, double g) : courseName(name), grade(g), coursePrev(nullptr), courseNext(nullptr) {}

    QString getCourseName() {
        return courseName;
    }
    double getGrade() {
        return grade;
    }
    void setCourseName(QString course) {
        this->courseName = course;
    }
    void setGrade(double g) {
        this->grade = g;
    }



};


#endif // COURSE_H
