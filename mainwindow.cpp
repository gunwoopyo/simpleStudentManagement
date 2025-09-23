#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "mainwindow.h"
#include "student.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "학생 조회");
    ui->tabWidget->setTabText(1, "학생 등록");
    ui->tabWidget->setTabText(2, "학생 삭제");
    ui->tabWidget->setTabText(3, "수업 추가");
    ui->tabWidget->setTabText(4, "학점 변경");
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
    showStudentTable(stn);
}

void MainWindow::showStudentTable(student* current) {  // 학생 한명만 출력
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
        ui->tableWidget_3->setItem(row, 5, new QTableWidgetItem(QString::number(c->getGrade())));
        // ui->tableWidget_3->setItem(row, 5, new QTableWidgetItem(QString::number(current->)));  GPA
        row++;
        c = c->courseNext;
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
        ui->tableWidget_2->setItem(row, 3, new QTableWidgetItem(QString::number(c->getGrade())));

        c = c->courseNext; // 다음 과목으로 이동
        row++;       // 다음 행으로 이동
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
            ui->tableWidget_3->setItem(row, 5, new QTableWidgetItem(QString::number(c->getGrade())));

            row++;
            c = c->courseNext;
        }

        current = current->studentNext;
    }
}










void MainWindow::showRegistrationTable() {

    ui->tableWidget->setRowCount(0); // 기존 내용 초기화
    student* current = management::manageHead;
    int row = 0;
    while(current != nullptr) {
        ui->tableWidget->insertRow(row); // 새로운 행 추가

        // 각 셀에 데이터 삽입
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(current->getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(current->getYear())));

        current = current->studentNext;
        row++;
    }
}




void MainWindow::on_AddCoursePushButton_clicked(){
    int studentID = ui->AddCourseStudentIDText->text().toInt();
    QString course = ui->AddCourseText->text();
    double grade = ui->AddCourseGradeText->text().toDouble();
    student* stn =  management::searchStudentID(studentID);

    if(stn == nullptr){
        QMessageBox::warning(this, "failed", "not existing studentID.");
        ui->AddCourseStudentIDText->setFocus();
        return;

    }
    stn->addCourse(course, grade);
    showCourseTable(stn);
}





void MainWindow::on_registrationpushButton_clicked() {
    int studentID = ui->studentIDText->text().toInt();
    QString name = ui->nameText->text();
    QString major = ui->majorText->text();
    int year = ui->yearText->text().toInt();

    student* current = management::manageHead;
    while(current != nullptr){
        if(current->getStudentID() == studentID){
            QMessageBox::warning(this, "failed", "existing studentID.");
            ui->studentIDText->setFocus();
            return;
        }
        current = current->studentNext;
    }
    manager->insertStudent(studentID, name, major, year);
    showRegistrationTable();
}

//qDebug() << "find!!!!" <<  " current address : " << current <<  "id : " <<    current->getStudentID();


// 학점 변경에서 학번의 과목과 입력받은 과목 일치하지 않으면 경고 메시지
void MainWindow::on_updateButton_clicked() {

    int studentID = ui->updateStudentIDText->text().toInt();
    double grade = ui->updateGradeText->text().toDouble();
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
            ui->tableWidget_5->setItem(row, 5, new QTableWidgetItem(QString::number(c->getGrade())));
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
    delete ui;
}






