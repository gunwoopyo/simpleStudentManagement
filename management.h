#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QString>
#include "student.h"



class management {
public:
    static student* manageHead;


    void insertStudent(int studentID, QString name, QString major, int year);
    //bool checkStudentID(int studnetID);   // if not existing studentID --> true
    static student* searchStudentID(int studentID);

    void updateGrade(student* stn, QString courseName, double grade);






private slots:


public slots:

};






#endif // MANAGEMENT_H
