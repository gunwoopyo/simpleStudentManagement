#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>
#include "student.h"



class management {
public:
    static student* manageHead;


    void insertStudent(int studentID, QString name, QString major, int year);
    void deleteStudent(int studentID);


    void addCourse(student* stn, QString courseName, double courseGrade);
    void deleteCourse(student* stn);

    static student* searchStudentID(int studentID);

    bool checkStudentID(int studentID);

    void updateGrade(student* stn, QString courseName, double grade);






private slots:


public slots:

};






#endif // MANAGEMENT_H
