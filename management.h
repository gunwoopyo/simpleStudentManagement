#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>
#include "student.h"
class management {
public:
    static student* manageHead;
    void insertStudent(int studentID, QString name, QString major, QString year);
    void deleteStudent(int studentID);

    void addCourse(student* stn, QString courseName);
    void deleteCourse(student* stn, QString courseName);

    void updateGrade(student* stn, QString courseName, QString grade);

    bool checkStudentID(int studentID);
    student* searchStudentID(int studentID);

    void debugInsertList();
    void debugCourseList();
private slots:

public slots:
};



#endif // MANAGEMENT_H
