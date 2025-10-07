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
private slots:
    void onMajorChanged(const QString &major);  // 전공 변경 슬롯
    void onTabChanged(int index);  // 탭 변경 시 호출될 슬롯
public slots:

    void on_studentSearchButton_clicked();      // 학생 조회
    void on_allStudentSearchButton_clicked();   // 학생 전체 조회
    void searchStudentTable(int stnID, QString year, QString major);
    void searchClear();


    void on_registrationPushButton_clicked();    // 학생 등록
    void on_deleteStudentPushButton_clicked();    // 학생 삭제
    void registrationTable();
    void registrationDeleteClear();


    void on_courseSearchPushButton_clicked();   // 과목 조회
    void on_courseAddPushButton_clicked();      // 과목 추가
    void on_courseDeletePushButton_clicked();   // 과목 삭제
    void courseTable(student* stn);
    void courseFrameClear();


    void on_gradeSearchButton_clicked();         // 성적 조회
    void on_gradeRegistrationButton_clicked();   // 성적 등록
    void gradeTable(student* stn);
    void gradeFrameClear();

    void clearAllStudents();
};

#endif // MAINWINDOW_H


