#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>
#include "student.h"
class management {
public:
    static student* manageHead;
    void insertStudent(int studentID, QString name, QString major, QString year, QString courseName, QString grade);
    void deleteStudent(int studentID);

    void addCourse(student* stn, QString courseName, QString courseGrade);
    void deleteCourse(student* stn, QString courseName);

    void updateGrade(student* stn, QString courseName, QString grade);

    bool checkStudentID(int studentID);
    student* searchStudentID(int studentID);

    void debugInsertList();
    void debugDeleteList();
    void debugCourseList();




private slots:


public slots:

};



#endif // MANAGEMENT_H
