#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "management.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    management* manager= new management();

private:
    Ui::MainWindow *ui;
public slots:
    void clearAllStudents();

    void on_registrationpushButton_clicked();
    void showRegistrationTable(); // 학생 등록 테이블

    void on_deleteStudentPushButton_clicked();
    void showDeleteTable();




    void on_studentSearchButton_clicked();
    void tab1ShowStudentTable(student* stn);

    void on_allStudentSearchButton_clicked();
    void AllStudentSearchButton();       // 모든 학생 조회

    void on_addCoursePushButton_clicked();
    void showCourseTable(student* stn); //과목 목록 테이블

    void on_updateButton_clicked();
    void tab5_studentTable(student* s, QString qn);

private slots:
};

#endif // MAINWINDOW_H






