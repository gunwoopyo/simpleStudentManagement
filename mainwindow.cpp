#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include "student.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->tabWidget->setTabText(0, "학생 조회");
    ui->tabWidget->setTabText(1, "학생 등록");
    ui->tabWidget->setTabText(2, "학생 삭제");
    ui->tabWidget->setTabText(3, "수강 과목 추가");
    ui->tabWidget->setTabText(4, "수강 과목 삭제");
    ui->tabWidget->setTabText(5, "학점 변경");
}


void MainWindow::on_registrationpushButton_clicked() {
    int studentID = ui->registrationStudentIDText->text().toInt();
    QString name = ui->registrationNameText->text();
    QString major = ui->registrationMajorText->text();
    int year = ui->registrationYearText->text().toInt();
    QString courseName = ui-> registrationCourseNameText->text();
    QString grade = ui-> registrationGradeText->text();


    if(!manager->checkStudentID(studentID)){  //  ~(return false)
        manager->insertStudent(studentID, name, major, year, courseName, grade);
        showRegistrationTable();
        return;
    }
    QMessageBox::warning(this, "실패", "이미 등록한 학번입니다.");
    ui->registrationStudentIDText->setFocus();
    return;
}

void MainWindow::showRegistrationTable() {
    QSqlQuery query("SELECT s.studentID, s.name, s.major, s.year, e.courseName, e.grade FROM student s INNER JOIN enrollment e ON s.studentID = e.studentID;");

     ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) { // 행으로 이동
        ui->tableWidget->insertRow(row);  // 행 추가

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // first collum
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // second collum
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));

        row++;
    }
}

void MainWindow::on_deleteStudentPushButton_clicked() {
    int studentID = ui->deleteStudentText->text().toInt();
    manager->deleteStudent(studentID);
    showDeleteTable();

}
void MainWindow::showDeleteTable() {
    QSqlQuery query("SELECT studentID, name, major, year FROM student");

    ui->tableWidget_4->setRowCount(0);

    int row = 0;
    while (query.next()) { // 행으로 이동
        ui->tableWidget_4->insertRow(row);  // 행 추가

        ui->tableWidget_4->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // first collum
        ui->tableWidget_4->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // second collum
        ui->tableWidget_4->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget_4->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));

        row++;
    }
}




void MainWindow::clearAllStudents() {
    student* current = management::manageHead;
    while (current != nullptr) {
        course* c = current->courseList;
        while(c != nullptr){
            course* tempCourse = c;
            c = c->courseNext;
            delete tempCourse;

        }
        student* tempStudent = current;
        current = current->studentNext;
        delete tempStudent;
    }
    management::manageHead = nullptr;
}


void MainWindow::on_studentSearchButton_clicked() {
    int studentID = ui->searchStudentIDText->text().toInt();
    student* stn =  management::searchStudentID(studentID); //객체 반환

    if(stn == nullptr){
        QMessageBox::warning(this, "failed", "not existing studentID.");
        ui->searchStudentIDText->setFocus();
        return;
    }
    tab1ShowStudentTable(stn);
}


void MainWindow::tab1ShowStudentTable(student* current) {  // 학생 한명만 출력
    ui->tableWidget_3->setRowCount(0);
    int row = 0;
    course* c = current->courseList;
    if(c == nullptr) {
        ui->tableWidget_3->insertRow(row); // 새로운 행 추가
        ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
        ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(current->getName()));
        ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
        ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(QString::number(current->getYear())));
    }
    while(c != nullptr) {
        ui->tableWidget_3->insertRow(row); // 새로운 행 추가

        ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
        ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(current->getName()));
        ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
        ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(QString::number(current->getYear())));
        ui->tableWidget_3->setItem(row, 4, new QTableWidgetItem(c->getCourseName()));
        ui->tableWidget_3->setItem(row, 5, new QTableWidgetItem(c->getGrade()));
        // ui->tableWidget_3->setItem(row, 5, new QTableWidgetItem(QString::number(current->)));  GPA
        row++;
        c = c->courseNext;
    }
}

void MainWindow:: on_allStudentSearchButton_clicked(){
    if(management::manageHead == nullptr){
        QMessageBox::warning(this, "failed", "not existing studentID.");
        ui->searchStudentIDText->setFocus();
        return;
    }
    AllStudentSearchButton();
}
void MainWindow::AllStudentSearchButton() {
    ui->tableWidget_3->setRowCount(0);
    int row = 0;
    student* current = management::manageHead;
    while(current != nullptr) {
        course* c = current ->courseList;
        if(c == nullptr) {
            ui->tableWidget_3->insertRow(row);
            ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
            ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(current->getName()));
            ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
            ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(QString::number(current->getYear())));
            row++;
        }
        while(c != nullptr) {
            ui->tableWidget_3->insertRow(row);
            ui->tableWidget_3->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
            ui->tableWidget_3->setItem(row, 1, new QTableWidgetItem(current->getName()));
            ui->tableWidget_3->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
            ui->tableWidget_3->setItem(row, 3, new QTableWidgetItem(QString::number(current->getYear())));
            ui->tableWidget_3->setItem(row, 4, new QTableWidgetItem(c->getCourseName()));
            ui->tableWidget_3->setItem(row, 5, new QTableWidgetItem(c->getGrade()));

            row++;
            c = c->courseNext;
        }

        current = current->studentNext;
    }
}











void MainWindow::showCourseTable(student* current) {
    ui->tableWidget_2->setRowCount(0);
    int row = 0;
    course* c = current->courseList;
    while(c != nullptr) {
        ui->tableWidget_2->insertRow(row);
        ui->tableWidget_2->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
        ui->tableWidget_2->setItem(row, 1, new QTableWidgetItem(current->getName()));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(QString::number(current->getYear())));
        ui->tableWidget_2->setItem(row, 2, new QTableWidgetItem(c->getCourseName()));
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(c->getGrade()));

        c = c->courseNext; // 다음 과목으로 이동
        row++;       // 다음 행으로 이동
    }
}















void MainWindow::on_addCoursePushButton_clicked(){
    int studentID = ui->AddCourseStudentIDText->text().toInt();
    QString course = ui->AddCourseText->text();
    QString grade = ui->AddCourseGradeText->text();
    student* stn = manager->searchStudentID(studentID);
    if(stn != nullptr) {
        QMessageBox::warning(this, "failed", "not existing studentID.");
        ui->AddCourseStudentIDText->setFocus();
        return;
    }
    manager->addCourse(stn, course, grade);
}








void MainWindow::on_updateButton_clicked() {

    int studentID = ui->updateStudentIDText->text().toInt();
    QString grade = ui->updateGradeText->text();
    QString coursename = ui->updateCourseText->text();

    student* stn = management::searchStudentID(studentID); //return object
    if(stn->courseList == nullptr){
        QMessageBox::warning(this, "failed", "not existing the course.");
        ui->updateGradeText->setFocus();
        return ;
    }
    course* c = stn->courseList;

    int count = 0;
    while(c != nullptr) {
        if(c->getCourseName() == coursename){
            count++;
        }
        c = c->courseNext;
    }
    if(count == 0) {
        QMessageBox::warning(this, "failed", "not existing the coursename.");
        ui->updateGradeText->setFocus();
        return;
    }


    //qDebug() << "stn address " << stn;
    manager->updateGrade(stn, coursename, grade );
    tab5_studentTable(stn, coursename);
    qDebug() << "table call";
}

// 변경된 학점 그 줄 한개만 출력
void MainWindow::tab5_studentTable(student* current, QString coursename) {  // 학생 한명만 출력
    qDebug() << "table start";
    ui->tableWidget_5->setRowCount(0);
    int row = 0;
    course* c = current->courseList;
    while(c != nullptr) {
        if(c->getCourseName() == coursename) {
            ui->tableWidget_5->insertRow(row); // 새로운 행 추가
            ui->tableWidget_5->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
            ui->tableWidget_5->setItem(row, 1, new QTableWidgetItem(current->getName()));
            ui->tableWidget_5->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
            ui->tableWidget_5->setItem(row, 3, new QTableWidgetItem(QString::number(current->getYear())));
            ui->tableWidget_5->setItem(row, 4, new QTableWidgetItem(c->getCourseName()));
            ui->tableWidget_5->setItem(row, 5, new QTableWidgetItem(c->getGrade()));
        }

        //row++;
        c = c->courseNext;
        qDebug() << "table finished";
        qDebug() << "============================";
    }
}


MainWindow::~MainWindow()
{
    clearAllStudents();
    qDebug() << "finish head pointer" << management::manageHead;
    delete ui;
}




