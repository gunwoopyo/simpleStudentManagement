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
    void on_registrationPushButton_clicked();
    void registrationTable(); // 학생 등록 테이블

    void on_deleteStudentPushButton_clicked();
    void deleteStudentTable();

    void on_studentSearchButton_clicked();
    void searchStudentTable(student* stn);
    void on_allStudentSearchButton_clicked();

    void on_addCoursePushButton_clicked();
    void addCourseTable(student* stn); //과목 목록 테이블

    void on_deleteCoursePushButton_clicked();
    void deleteCourseTable(student* stn); //과목 목록 테이블


    void on_updateButton_clicked();
    void upgradeGradeTable(student* stn, QString coursename);


    void clearAllStudents();

private slots:
    void onTabChanged(int index);  // 탭 변경 시 호출될 슬롯
    void onMajorChanged(const QString &major);  // 전공 변경 슬롯
};

#endif // MAINWINDOW_H






