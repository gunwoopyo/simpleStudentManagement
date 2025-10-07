#ifndef COURSE_H
#define COURSE_H
#include <QString>
class course {
private:
    QString courseName;
    QString grade;
public:
    course* coursePrev;
    course* courseNext;

    course(QString name) : courseName(name), grade(""), coursePrev(nullptr), courseNext(nullptr) {}

    QString getCourseName() {
        return courseName;
    }
    QString getGrade() {
        return grade;
    }
    void setCourseName(QString course) {
        this->courseName = course;
    }
    void setGrade(QString g) {
        this->grade = g;
    }
};


#endif // COURSE_H
