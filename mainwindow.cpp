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
#include "management.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    connect(ui->registrationMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->registrationMajorComboBox->currentText());

    connect(ui->addCourseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->addCourseMajorComboBox->currentText());

    connect(ui->updateMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->updateMajorComboBox->currentText());

    connect(ui->deleteCourseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->deleteCourseMajorComboBox->currentText());
}
void MainWindow::onTabChanged(int index)     // 탭 클릭시 행 및 내용 지우기
{
    switch (index) {
    case 0: // 검색 탭
        ui->searchTable->setRowCount(0);
        //updateSearchTable();
        break;
    case 1: // 등록 탭
        ui->registrationTable->setRowCount(0);
        registrationTable();
        break;
    case 2: // 삭제 탭
        ui->deleteTable->setRowCount(0);
        deleteStudentTable();
        break;
    case 3: // 수업 추가 탭
        //ui->addCourseTable->setRowCount(0);
        // addCourseTable(); // 수업 추가 테이블 업데이트
        break;
    case 4: // 수업 삭제 탭
        //ui->deleteCourseTable->setRowCount(0);
        // updateDeleteCourseTable(); // 수업 삭제 테이블 업데이트
        break;
    case 5: // 학점 변경 탭
        //ui->upgradeGradeTable->setRowCount(0);
        // updateUpgradeGradeTable(); // 학점 변경 테이블 업데이트
        break;

        default:
        break;
    }
}

void MainWindow::onMajorChanged(const QString &major)
{
    ui->registrationCourseNameComboBox->clear();  // 기존 과목 제거
    ui->addCourseCourseNameComboBox->clear();
    ui->updateCourseNameComboBox->clear();
    ui->deleteCourseNameComboBox->clear();

    if (major == "컴퓨터공학과") {
        ui->registrationCourseNameComboBox->addItem("");
        ui->registrationCourseNameComboBox->addItem("운영체제");
        ui->registrationCourseNameComboBox->addItem("자료구조");
        ui->registrationCourseNameComboBox->addItem("알고리즘");

        ui->addCourseCourseNameComboBox->addItem("");
        ui->addCourseCourseNameComboBox->addItem("운영체제");
        ui->addCourseCourseNameComboBox->addItem("자료구조");
        ui->addCourseCourseNameComboBox->addItem("알고리즘");

        ui->updateCourseNameComboBox->addItem("");
        ui->updateCourseNameComboBox->addItem("운영체제");
        ui->updateCourseNameComboBox->addItem("자료구조");
        ui->updateCourseNameComboBox->addItem("알고리즘");

        ui->deleteCourseNameComboBox->addItem("");
        ui->deleteCourseNameComboBox->addItem("운영체제");
        ui->deleteCourseNameComboBox->addItem("자료구조");
        ui->deleteCourseNameComboBox->addItem("알고리즘");
    }
    else if (major == "전자공학과") {
        ui->registrationCourseNameComboBox->addItem("");
        ui->registrationCourseNameComboBox->addItem("회로이론");
        ui->registrationCourseNameComboBox->addItem("신호처리");
        ui->registrationCourseNameComboBox->addItem("전자기학");

        ui->addCourseCourseNameComboBox->addItem("");
        ui->addCourseCourseNameComboBox->addItem("회로이론");
        ui->addCourseCourseNameComboBox->addItem("신호처리");
        ui->addCourseCourseNameComboBox->addItem("전자기학");

        ui->updateCourseNameComboBox->addItem("");
        ui->updateCourseNameComboBox->addItem("회로이론");
        ui->updateCourseNameComboBox->addItem("신호처리");
        ui->updateCourseNameComboBox->addItem("전자기학");

        ui->deleteCourseNameComboBox->addItem("");
        ui->deleteCourseNameComboBox->addItem("회로이론");
        ui->deleteCourseNameComboBox->addItem("신호처리");
        ui->deleteCourseNameComboBox->addItem("전자기학");
    }

    else if (major == "기계공학과") {
        ui->registrationCourseNameComboBox->addItem("");
        ui->registrationCourseNameComboBox->addItem("열역학");
        ui->registrationCourseNameComboBox->addItem("유체역학");
        ui->registrationCourseNameComboBox->addItem("재료역학");

        ui->addCourseCourseNameComboBox->addItem("");
        ui->addCourseCourseNameComboBox->addItem("열역학");
        ui->addCourseCourseNameComboBox->addItem("유체역학");
        ui->addCourseCourseNameComboBox->addItem("재료역학");


        ui->updateCourseNameComboBox->addItem("");
        ui->updateCourseNameComboBox->addItem("열역학");
        ui->updateCourseNameComboBox->addItem("유체역학");
        ui->updateCourseNameComboBox->addItem("재료역학");

        ui->deleteCourseNameComboBox->addItem("");
        ui->deleteCourseNameComboBox->addItem("열역학");
        ui->deleteCourseNameComboBox->addItem("유체역학");
        ui->deleteCourseNameComboBox->addItem("재료역학");
    }
}

void MainWindow::on_registrationPushButton_clicked() {

    int studentID = ui->registrationStudentIDText->text().toInt();
    QString name = ui->registrationNameText->text();
    QString major = ui->registrationMajorComboBox->currentText();
    QString year = ui->registrationYearComboBox->currentText();
    QString courseName = ui->registrationCourseNameComboBox->currentText();
    QString grade = ui->registrationGradeCombobox->currentText();
    if(manager->checkStudentID(studentID)){  //  학번 중복되지 않으면 true 리턴
        manager->insertStudent(studentID, name, major, year, courseName, grade);
        manager->debugInsertList();
        registrationTable();
        ui->registrationStudentIDText->clear();
        ui->registrationNameText->clear();
        ui->registrationCourseNameComboBox->setCurrentIndex(0);
        ui->registrationMajorComboBox->setCurrentIndex(0);
        ui->registrationYearComboBox->setCurrentIndex(0);
        ui->registrationGradeCombobox->setCurrentIndex(0);

        return;
    }
    QMessageBox::warning(this, "실패", "이미 등록한 학번입니다.");
    ui->registrationStudentIDText->setFocus();
    return;
}
void MainWindow::registrationTable() {
    ui->registrationTable->setRowCount(0);  // 테이블 초기화
    int row = 0;
    student* currentStudent = management::manageHead;
    while (currentStudent != nullptr) { // 행으로 이동
        ui->registrationTable->insertRow(row);  // 행 추가
        ui->registrationTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
        ui->registrationTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
        ui->registrationTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getMajor()));
        ui->registrationTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getYear()));
        ui->registrationTable->setItem(row, 4, new QTableWidgetItem(currentStudent->courseList->getCourseName()));
        ui->registrationTable->setItem(row, 5, new QTableWidgetItem(currentStudent->courseList->getGrade()));
        row++;
        currentStudent = currentStudent->studentNext;
    }

}

void

void MainWindow::on_deleteStudentPushButton_clicked() {
    int studentID = ui->deleteStudentText->text().toInt();
    if(!manager->checkStudentID(studentID)){    //   중복되니까 false 지만 !로 true 만들고 함수 내로 진입
        manager->deleteStudent(studentID);
        manager->debugDeleteList();
        ui->deleteStudentText->clear();
        deleteStudentTable();
        return;
    }
    QMessageBox::warning(this, "실패", "존재하는 학번이 없습니다.");
    ui->deleteStudentText->setFocus();
    return;
}
void MainWindow::deleteStudentTable() {
    ui->deleteTable->setRowCount(0);
    int row = 0;
    student* currentStudent = management::manageHead;
    while (currentStudent != nullptr) { // 행으로 이동
        ui->deleteTable->insertRow(row);  // 행 추가
        ui->deleteTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
        ui->deleteTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
        ui->deleteTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getMajor()));
        ui->deleteTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getYear()));
        ui->deleteTable->setItem(row, 4, new QTableWidgetItem(currentStudent->courseList->getCourseName()));
        ui->deleteTable->setItem(row, 5, new QTableWidgetItem(currentStudent->courseList->getGrade()));
        row++;
        currentStudent = currentStudent->studentNext;
    }
}


void MainWindow::clearAllStudents() {
    student* currentStudent = management::manageHead;
    while (currentStudent != nullptr) {
        course* currentCourse = currentStudent->courseList;
        while(currentCourse != nullptr){
            course* tempCourse = currentCourse;
            currentCourse = currentCourse->courseNext;
            delete tempCourse;
        }
        student* tempStudent = currentStudent;
        currentStudent = currentStudent->studentNext;
        delete tempStudent;
    }
    management::manageHead = nullptr;

}


void MainWindow::on_studentSearchButton_clicked() {
    int studentID = ui->searchStudentIDText->text().toInt();
    student* stn =  manager->searchStudentID(studentID); //  학번 검색해 객체 존재하면 객체 반환
    if(stn == nullptr){
        QMessageBox::warning(this, "실패", "존재하지 않는 학번입니다.");
        ui->searchStudentIDText->setFocus();
        return;
    }
    searchStudentTable(stn);
    ui->searchStudentIDText->clear();
}
void MainWindow::searchStudentTable(student* stn) {  // 학생 한명만 출력
    ui->searchTable->setRowCount(0);
    int row = 0;
    course* currentCourse = stn->courseList;



    while(currentCourse != nullptr) {
        ui->searchTable->insertRow(row); // 새로운 행 추가
        ui->searchTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
        ui->searchTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
        ui->searchTable->setItem(row, 2, new QTableWidgetItem(stn->getMajor()));
        ui->searchTable->setItem(row, 3, new QTableWidgetItem(stn->getYear()));
        ui->searchTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
        ui->searchTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
        row++;
        currentCourse = currentCourse->courseNext;
    }
}



void MainWindow:: on_allStudentSearchButton_clicked(){
    if(management::manageHead == nullptr) {
        QMessageBox::warning(this, "실패", "존재하는 학번이 없습니다.");
        ui->searchStudentIDText->setFocus();
        return;
    }
    ui->searchTable->setRowCount(0);
    int row = 0;
    student* currentStudent = management::manageHead;
    course* currentCourse = currentStudent->courseList;
    while (currentStudent != nullptr) { // 행으로 이동
        while(currentCourse != nullptr) {
        ui->searchTable->insertRow(row);  // 행 추가
        ui->searchTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
        ui->searchTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
        ui->searchTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getMajor()));
        ui->searchTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getYear()));
        ui->searchTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
        ui->searchTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
        row++;
        currentCourse = currentCourse->courseNext;
        }
        row++;
        currentStudent = currentStudent->studentNext;
    }
}



void MainWindow::on_addCoursePushButton_clicked(){
    int studentID = ui->addCourseStudentIDText->text().toInt();
    QString major = ui->addCourseMajorComboBox->currentText();
    QString courseName = ui->addCourseCourseNameComboBox->currentText();
    QString grade = ui->addCourseGradeComboBox->currentText();

    student* stn = manager->searchStudentID(studentID);   // 학번의 객체가 존재하면 객체 리턴
    if(stn == nullptr) {
        QMessageBox::warning(this, "실패", "존재하지 않는 학번입니다.");
        ui->addCourseStudentIDText->setFocus();
        return;
    }
    else {
        if(stn->getMajor() == major) {
            course * currentCourse = stn->courseList;
            while(currentCourse != nullptr) {
                if(currentCourse->getCourseName() == courseName) {
                    QMessageBox::warning(this, "실패", "과목이 중복됩니다.");
                    ui->addCourseStudentIDText->setFocus();
                    return;
                }
                currentCourse = currentCourse->courseNext;
            }
            manager->addCourse(stn, courseName, grade);
            addCourseTable(stn);
            manager->debugCourseList();
            ui->addCourseStudentIDText->clear();
            ui->addCourseMajorComboBox->setCurrentIndex(0);
            ui->addCourseCourseNameComboBox->setCurrentIndex(0);
            ui->addCourseGradeComboBox->setCurrentIndex(0);
            return;
        }
        QMessageBox::warning(this, "실패", "전공을 다시 선택해주세요");
        ui->addCourseStudentIDText->setFocus();
        return;
    }
}

void MainWindow::addCourseTable(student* current) {
    ui->addCourseTable->setRowCount(0);
    int row = 0;
    course* currentCourse= current->courseList;
    while(currentCourse != nullptr) {
        ui->addCourseTable->insertRow(row);
        ui->addCourseTable->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
        ui->addCourseTable->setItem(row, 1, new QTableWidgetItem(current->getName()));
        ui->addCourseTable->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
        ui->addCourseTable->setItem(row, 3, new QTableWidgetItem(current->getYear()));
        ui->addCourseTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
        ui->addCourseTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
        row++;
        currentCourse = currentCourse->courseNext;
    }
}

void MainWindow::on_deleteCoursePushButton_clicked() {
    int studentID = ui->deleteCourseStudentIDText->text().toInt();
    QString major = ui->deleteCourseMajorComboBox->currentText();
    QString courseName = ui->deleteCourseNameComboBox->currentText();

    student* stn = manager->searchStudentID(studentID);    // 학번 있으면 객체 반환.
    qDebug() << "stn 주소 : "<< stn;
    if (stn == nullptr) {
        QMessageBox::warning(this, "실패", "존재하는 학번이 없습니다.");
        ui->updateCourseNameComboBox->setFocus();
        return ;
    }
    else {
        qDebug() << "111111111111 ";
        course* currentCourse = stn->courseList;
        while(currentCourse != nullptr)
        {
            qDebug() << "222222222222 ";
            if(currentCourse->getCourseName() == courseName)
            {
                qDebug() << "33333333333333 ";
                manager->deleteCourse(stn, courseName);
                ui->deleteStudentText->clear();
                deleteCourseTable(stn);
                return;
            }
            currentCourse = currentCourse->courseNext;
        }
        QMessageBox::warning(this, "실패", "존재하는 과목이 없습니다.");
        ui->updateCourseNameComboBox->setFocus();
        return ;
    }
}

void MainWindow::deleteCourseTable(student* stn) {
    course* currentCourse = stn->courseList;
    ui->addCourseTable->setRowCount(0);
    int row = 0;
    while(stn != nullptr) {
        ui->deleteCourseTable->insertRow(row);
        ui->deleteCourseTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
        ui->deleteCourseTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
        ui->deleteCourseTable->setItem(row, 2, new QTableWidgetItem(stn->getMajor()));
        ui->deleteCourseTable->setItem(row, 3, new QTableWidgetItem(stn->getYear()));
        ui->deleteCourseTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
        ui->deleteCourseTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
        row++;
        currentCourse = currentCourse->courseNext;
    }

}





void MainWindow::on_updateButton_clicked() {

    int studentID = ui->updateStudentIDText->text().toInt();
    QString major = ui->updateMajorComboBox->currentText();
    QString coursename = ui->updateCourseNameComboBox->currentText();
    QString grade = ui->updateCourseGradeCombobox->currentText();

    student * currentStudent = management::manageHead;
    while(currentStudent != nullptr) {
        if(currentStudent->getStudentID() == studentID) {
            student* stn = manager->searchStudentID(studentID); //   객체 존재하면 객체 주소 리턴
            qDebug() << "stn 주소 " << stn;
            qDebug() << "stn 과목 리스트 헤드 주소 " << stn->courseList;

            if(stn->courseList == nullptr){
                QMessageBox::warning(this, "실패", "수강 과목이 존재하지 않습니다.");
                ui->updateCourseNameComboBox->setFocus();
                return ;
            }

            int count = 0;
            course* currentCourse = stn->courseList;
            while(currentCourse != nullptr) {
                qDebug() << "22222222 " ;
                if(currentCourse->getCourseName() == coursename)
                    count++;

                currentCourse = currentCourse->courseNext;
            }
            if(count == 0) {
                QMessageBox::warning(this, "실패", "존재하지 않는 과목 이름입니다.");
                ui->updateCourseNameComboBox->setFocus();
                return;
            }
            qDebug() << "3333333 " ;
            manager->updateGrade(stn, coursename, grade);
            upgradeGradeTable(stn,coursename);
            ui->updateStudentIDText->clear();
            ui->updateMajorComboBox->setCurrentIndex(0);
            ui->updateCourseNameComboBox->setCurrentIndex(0);
            ui->updateCourseGradeCombobox->setCurrentIndex(0);
            return;

        }
        currentStudent = currentStudent->studentNext;
    }
    QMessageBox::warning(this, "실패", "존재하는 학번이 없습니다.");
    ui->updateCourseNameComboBox->setFocus();
    return ;

}

// 변경된 학점 그 줄 한개만 출력
void MainWindow::upgradeGradeTable(student* current, QString coursename) {  // 학생 한명만 출력
    qDebug() << "table start";
    ui->upgradeGradeTable->setRowCount(0);
    int row = 0;
    course* currentCourse = current->courseList;
    while(currentCourse != nullptr) {
        if(currentCourse->getCourseName() == coursename) {
            ui->upgradeGradeTable->insertRow(row); // 새로운 행 추가
            ui->upgradeGradeTable->setItem(row, 0, new QTableWidgetItem(QString::number(current->getStudentID())));
            ui->upgradeGradeTable->setItem(row, 1, new QTableWidgetItem(current->getName()));
            ui->upgradeGradeTable->setItem(row, 2, new QTableWidgetItem(current->getMajor()));
            ui->upgradeGradeTable->setItem(row, 3, new QTableWidgetItem(current->getYear()));
            ui->upgradeGradeTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
            ui->upgradeGradeTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
        }
        currentCourse = currentCourse->courseNext;
    }
}



MainWindow::~MainWindow()
{
    clearAllStudents();
    qDebug() << "클리어 후 헤드 포인터 주소 : " << management::manageHead  << "  main window.cpp ";
    delete ui;
}




