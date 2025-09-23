#include <QString>
#include <QMessageBox>
#include "course.h"
#include "student.h"
#include "management.h"
#include <QDebug>

void student::addCourse(QString n, double g) {

    course* newCourse = new course(n, g);

    if(courseList == nullptr){
        courseList = newCourse;
    }
    else {
        course* current = courseList;
        while(current->courseNext != nullptr){
            current = current ->courseNext;
        }
        current->courseNext = newCourse;
        newCourse->coursePrev = current;
    }
}


