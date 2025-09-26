#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>
#include "student.h"

class management {
public:
    static student* manageHead;

    void insertStudent(int studentID, QString name, QString major, int year, QString courseName, QString grade);
    void deleteStudent(int studentID);

    void addCourse(student* stn, QString courseName, QString courseGrade);
    void deleteCourse(student* stn);

    bool checkStudentID(int studentID);
    static student* searchStudentID(int studentID);



    void updateGrade(student* stn, QString courseName, QString grade);






private slots:


public slots:

};






#endif // MANAGEMENT_H
