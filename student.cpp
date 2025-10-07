#include <QString>
#include <QMessageBox>
#include "course.h"
#include "student.h"
#include "management.h"
#include <QDebug>


double student::calculateGPA(student* stn, double g) {

    double gradeToNumber = 0.0;
    int count = 0;
    double GPA = 0.0;

    course* currentCourse = stn->courseList;

    while(currentCourse != nullptr) {
        QString grade = currentCourse->getGrade();

        if (grade == "A+") {
            gradeToNumber += 4.5;
        }
        else if (grade == "A") {
            gradeToNumber += 4.0;
        }
        else if (grade == "B+") {
            gradeToNumber += 3.5;
        }
        else if (grade == "B") {
            gradeToNumber += 3.0;
        }
        else if (grade == "C+") {
            gradeToNumber += 2.5;
        }
        else if (grade == "C") {
            gradeToNumber += 2.0;
        }
        else if (grade == "F") {
            gradeToNumber += 0.0;
        }

        count++;
        currentCourse = currentCourse->courseNext;
    }
    GPA = gradeToNumber / count;
    qDebug() << "GPA " << GPA ;
    return GPA;
}










