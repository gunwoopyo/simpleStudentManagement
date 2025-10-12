#include <QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "management.h"
#include "student.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);

    connect(ui->addDeleteCourseMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->addDeleteCourseMajorComboBox->currentText());

    connect(ui->updateMajorComboBox, &QComboBox::currentTextChanged,this, &MainWindow::onMajorChanged);
    onMajorChanged(ui->updateMajorComboBox->currentText());
}
void MainWindow::onTabChanged(int index)     // 탭 클릭시 행 및 내용 지우기
{
    switch (index) {
    case 0: // 검색 탭
        ui->searchTable->setRowCount(0);
        //updateSearchTable();
        break;
    case 1: // 등록 및 삭제 탭
        ui->registrationTable->setRowCount(0);
        registrationTable();
        break;

    case 2: // 과목 탭
        ui->courseSearchTable->setRowCount(0);
        courseFrameClear();
        break;
     case 3: // 성적 탭
        ui->upgradeGradeTable->setRowCount(0);
        gradeFrameClear();
        break;

        default:
        break;
    }
}
void MainWindow::onMajorChanged(const QString &major)
{
    ui->addDeleteCourseNameComboBox->clear();// 기존 과목 제거
    ui->updateCourseNameComboBox->clear();

    if (major == "컴퓨터공학과") {
        ui->addDeleteCourseNameComboBox->addItem("");
        ui->addDeleteCourseNameComboBox->addItem("운영체제");
        ui->addDeleteCourseNameComboBox->addItem("자료구조");
        ui->addDeleteCourseNameComboBox->addItem("알고리즘");

        ui->updateCourseNameComboBox->addItem("");
        ui->updateCourseNameComboBox->addItem("운영체제");
        ui->updateCourseNameComboBox->addItem("자료구조");
        ui->updateCourseNameComboBox->addItem("알고리즘");
    }
    else if (major == "전자공학과") {
        ui->addDeleteCourseNameComboBox->addItem("");
        ui->addDeleteCourseNameComboBox->addItem("회로이론");
        ui->addDeleteCourseNameComboBox->addItem("신호처리");
        ui->addDeleteCourseNameComboBox->addItem("전자기학");

        ui->updateCourseNameComboBox->addItem("");
        ui->updateCourseNameComboBox->addItem("회로이론");
        ui->updateCourseNameComboBox->addItem("신호처리");
        ui->updateCourseNameComboBox->addItem("전자기학");
    }
    else if (major == "기계공학과") {
        ui->addDeleteCourseNameComboBox->addItem("");
        ui->addDeleteCourseNameComboBox->addItem("열역학");
        ui->addDeleteCourseNameComboBox->addItem("유체역학");
        ui->addDeleteCourseNameComboBox->addItem("재료역학");

        ui->updateCourseNameComboBox->addItem("");
        ui->updateCourseNameComboBox->addItem("열역학");
        ui->updateCourseNameComboBox->addItem("유체역학");
        ui->updateCourseNameComboBox->addItem("재료역학");
    }
}


void MainWindow::on_ascPushButton_clicked() {
    int col = ui->sortComboBox->currentIndex();
    bubbleSortTable(ui->searchTable, col-1, true);
}

void MainWindow::on_descPushButton_clicked() {
    int col = ui->sortComboBox->currentIndex();
    bubbleSortTable(ui->searchTable, col-1, false);
}

void MainWindow::bubbleSortTable(QTableWidget* table, int column, bool ascending)
{
    int rows = table->rowCount();
    int cols = table->columnCount();

    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < rows - i - 1; ++j) {
            QTableWidgetItem* a = table->item(j, column);
            QTableWidgetItem* b = table->item(j + 1, column);
            if (!a || !b) continue;

            QString aText = a->text();
            QString bText = b->text();

            // 숫자인 경우 비교
            bool okA, okB;
            double numA = aText.toDouble(&okA);
            double numB = bText.toDouble(&okB);

            bool swap = (okA && okB)
                            ? (ascending ? numA > numB : numA < numB)
                            : (ascending ? aText > bText : aText < bText);

            if (swap) {
                // 행 전체 교환
                for (int c = 0; c < cols; ++c) {
                    QTableWidgetItem* tmp = table->takeItem(j, c);
                    table->setItem(j, c, table->takeItem(j + 1, c));
                    table->setItem(j + 1, c, tmp);
                }
            }
        }
    }
}










void MainWindow::on_studentSearchButton_clicked() {
    int studentID = ui->searchStudentIDText->text().toInt();
    QString year = ui->searchYearComboBox->currentText();
    QString major = ui->searchMajorComboBox->currentText();

    if(studentID == 0 && year.isEmpty() && major.isEmpty()) {    // 모두 빈칸인 경우
        QMessageBox::warning(this, "실패", "정보를 입력해주세요");
        searchClear();
        return;
    }
    searchStudentTable(studentID, year, major);

    if (ui->searchTable->rowCount() == 0) {
        QMessageBox::warning(this, "실패", "학생 정보를 확인해주세요");
        searchClear();
        return;
    } else {
        QMessageBox::information(this, "성공", "조회가 완료되었습니다.");
        searchClear();
        return;
    }
}
void MainWindow:: on_allStudentSearchButton_clicked(){
    if(management::manageHead == nullptr) {
        QMessageBox::warning(this, "실패", "존재하는 학번이 없습니다.");
        ui->searchStudentIDText->setFocus();
        return;
    }
    else {
        ui->searchTable->setRowCount(0);
        int row = 0;
        student* currentStudent = management::manageHead;
        course* currentCourse = currentStudent->courseList;
        while (currentStudent != nullptr) { // 행으로 이동
            ui->searchTable->insertRow(row);  // 행 추가
            ui->searchTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
            ui->searchTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
            ui->searchTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
            ui->searchTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
            ui->searchTable->setItem(row, 4, new QTableWidgetItem(QString::number(currentStudent->getGPA())));

            row++;
            currentStudent = currentStudent->studentNext;
        }
    }
}
void MainWindow::searchStudentTable(int stnID, QString year, QString major) {
    ui->searchTable->setRowCount(0);
    student* currentStudent = management::manageHead;
    int row = 0;
    while (currentStudent) {
        bool match = true;
        if (stnID != 0 && currentStudent->getStudentID() != stnID)
            match = false;
        if (!year.isEmpty() && currentStudent->getYear() != year)
            match = false;
        if (!major.isEmpty() && !currentStudent->getMajor().contains(major, Qt::CaseInsensitive))
            match = false;

        if (match) {
            ui->searchTable->insertRow(row);
            ui->searchTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
            ui->searchTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
            ui->searchTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
            ui->searchTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
            ui->searchTable->setItem(row, 4, new QTableWidgetItem(QString::number(currentStudent->getGPA())));

        }
        currentStudent = currentStudent->studentNext;
    }
}
void MainWindow::searchClear() {
    ui->searchStudentIDText->clear();
    ui->searchYearComboBox->setCurrentIndex(0);
    ui->searchMajorComboBox->setCurrentIndex(0);
}








void MainWindow::on_registrationPushButton_clicked() {
    int studentID = ui->registrationStudentIDText->text().toInt();
    QString name = ui->registrationNameText->text();
    QString year = ui->registrationYearComboBox->currentText();
    QString major = ui->registrationMajorComboBox->currentText();
    if (studentID == 0 || name.isEmpty() || year.isEmpty() || major.isEmpty()) {
        QMessageBox::warning(this, "실패", "정보를 모두 입력해주세요");
        registrationDeleteClear();
        return;
    }
    else if(manager->checkStudentID(studentID)){
        manager->insertStudent(studentID, name, major, year);
        manager->debugInsertList();
        registrationTable();
        registrationDeleteClear();
        QMessageBox::information(this, "등록 완료", "새로운 학생이 등록되었습니다!");
        return;
    }
    else {
        QMessageBox::warning(this, "실패", "이미 등록한 학번입니다.");
        ui->registrationStudentIDText->setFocus();
        return;
    }
}
void MainWindow::on_deleteStudentPushButton_clicked() {
    int studentID = ui->registrationStudentIDText->text().toInt();
    if (!manager->checkStudentID(studentID)){    //   중복이면 false 지만   !로 true 만들고 함수 내로 진입

        manager->deleteStudent(studentID);
        manager->debugInsertList();
        ui->registrationStudentIDText->clear();
        registrationTable();
        QMessageBox::information(this, "성공", "삭제가 완료되었습니다.");

        return;
    }
    else {
        QMessageBox::warning(this, "실패", "존재하는 학번이 없습니다.");
        ui->registrationStudentIDText->clear();
        return;
    }
}
void MainWindow::registrationTable() {
    ui->registrationTable->setRowCount(0);  // 테이블 초기화
    int row = 0;
    student* currentStudent = management::manageHead;
    while (currentStudent != nullptr) { // 행으로 이동
        ui->registrationTable->insertRow(row);  // 행 추가
        ui->registrationTable->setItem(row, 0, new QTableWidgetItem(QString::number(currentStudent->getStudentID())));
        ui->registrationTable->setItem(row, 1, new QTableWidgetItem(currentStudent->getName()));
        ui->registrationTable->setItem(row, 2, new QTableWidgetItem(currentStudent->getYear()));
        ui->registrationTable->setItem(row, 3, new QTableWidgetItem(currentStudent->getMajor()));
        row++;
        currentStudent = currentStudent->studentNext;
    }
}
void MainWindow::registrationDeleteClear() {
    ui->registrationStudentIDText->clear();
    ui->registrationNameText->clear();
    ui->registrationYearComboBox->setCurrentIndex(0);
    ui->registrationMajorComboBox->setCurrentIndex(0);
}









void MainWindow::on_courseSearchPushButton_clicked() {
    int studentID = ui->addDeleteCourseStudentIDText->text().toInt();
    QString year = ui->addDeleteYearComboBox->currentText();
    QString major = ui->addDeleteCourseMajorComboBox->currentText();
    QString courseName = ui->addDeleteCourseNameComboBox->currentText();

    student* stn = manager->searchStudentID(studentID);
    if (studentID == 0) {
        QMessageBox::warning(this, "실패", "학번을 입력해주세요.");
        courseFrameClear();
        return;
    }
    else if (!year.isEmpty() || !major.isEmpty() || !courseName.isEmpty()) {
        QMessageBox::warning(this, "실패", "학번만 입력해주세요.");
        courseFrameClear();
        return;
    }
    else if (stn == nullptr) {
        QMessageBox::warning(this, "실패", "학번을 확인해주세요.");
        courseFrameClear();
        return;
    }
    else {
        courseTable(stn);
        QMessageBox::information(this, "성공", "조회가 완료되었습니다.");
        courseFrameClear();
    }
}
void MainWindow::on_courseAddPushButton_clicked() {
    int studentID = ui->addDeleteCourseStudentIDText->text().toInt();
    QString year = ui->addDeleteYearComboBox->currentText();
    QString major = ui->addDeleteCourseMajorComboBox->currentText();
    QString courseName = ui->addDeleteCourseNameComboBox->currentText();
    student* stn = manager->searchStudentID(studentID);   // 학번의 객체가 존재하면 객체 리턴
    if(studentID == 0 || year.isEmpty() || major.isEmpty() || courseName.isEmpty()) {
        QMessageBox::warning(this, "실패", "정보를 모두 입력해주세요.");
        courseFrameClear();
        return;
    }
    else if(stn == nullptr) {
        QMessageBox::warning(this, "실패", "존재하는 학번이 없습니다.");
        courseFrameClear();
        return;
    }
    else if(stn->getYear() == year && stn->getMajor() == major) {
        course* currentCourse = stn->courseList;
        if(currentCourse == nullptr) {
            manager->addCourse(stn, courseName);
            courseTable(stn);
            QMessageBox::information(this, "등록 완료", "새로운 과목이 추가되었습니다!");
            courseFrameClear();
            return;
        }
        while(currentCourse != nullptr) {
            if(currentCourse->getCourseName() == courseName) {
                QMessageBox::warning(this, "실패", "이미 추가한 과목입니다.");
                courseFrameClear();
                return;
            }
            currentCourse = currentCourse->courseNext;
        }
        // courseList 널 아니면서 과목이 겹치지 않는 경우
        manager->addCourse(stn, courseName);
        courseTable(stn);
        QMessageBox::information(this, "등록 완료", "새로운 학생이 등록되었습니다!");
        courseFrameClear();
        return;
    }
    else {
        QMessageBox::warning(this, "실패", "학생 정보가 올바르지 않습니다.");
        courseFrameClear();
        return;
    }
}
void MainWindow::on_courseDeletePushButton_clicked() {
    int studentID = ui->addDeleteCourseStudentIDText->text().toInt();
    QString year = ui->addDeleteYearComboBox->currentText();
    QString major = ui->addDeleteCourseMajorComboBox->currentText();
    QString courseName = ui->addDeleteCourseNameComboBox->currentText();
    student* stn = manager->searchStudentID(studentID);
    if (studentID == 0 || year.isEmpty() || major.isEmpty() || courseName.isEmpty()) {
        QMessageBox::warning(this, "실패", "정보를 모두 입력해주세요.");
        courseFrameClear();
        return;
    }
    else if(stn == nullptr) {
        QMessageBox::warning(this, "실패", "학번을 확인해주세요");
        courseFrameClear();
        return;

    }
    else if (stn->getStudentID() == studentID && stn->getYear() == year && stn->getMajor() == major) {
        course* currentCourse = stn->courseList;
        while(currentCourse != nullptr) {
            if(currentCourse->getCourseName() == courseName) {
                manager->deleteCourse(stn, courseName);
                courseTable(stn);
                manager->debugCourseList();
                QMessageBox::information(this, "성공", "삭제 성공하였습니다");
                courseFrameClear();
                return;
            }
            currentCourse = currentCourse->courseNext;
        }
        QMessageBox::warning(this, "실패", "삭제할 과목을 확인해주세요.");
        courseFrameClear();
        return;
    }
    else {
        QMessageBox::warning(this, "실패", "학생 정보를 확인해주세요.");
        courseFrameClear();
        return;
    }
}
void MainWindow::courseTable(student* stn) {
    ui->courseSearchTable->setRowCount(0);
    course* currentCourse = stn->courseList;
    int row = 0;
    if(currentCourse == nullptr) {
        ui->courseSearchTable->insertRow(row);
        ui->courseSearchTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
        ui->courseSearchTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
        ui->courseSearchTable->setItem(row, 2, new QTableWidgetItem(stn->getYear()));
        ui->courseSearchTable->setItem(row, 3, new QTableWidgetItem(stn->getMajor()));

    }
    else {
         while (currentCourse != nullptr) {
            ui->courseSearchTable->insertRow(row);
            ui->courseSearchTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
            ui->courseSearchTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
            ui->courseSearchTable->setItem(row, 2, new QTableWidgetItem(stn->getYear()));
            ui->courseSearchTable->setItem(row, 3, new QTableWidgetItem(stn->getMajor()));
            ui->courseSearchTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
            row++;
            currentCourse = currentCourse->courseNext;
        }
    }
}
void MainWindow::courseFrameClear() {
    ui->addDeleteCourseStudentIDText->clear();
    ui->addDeleteYearComboBox->setCurrentIndex(0);
    ui->addDeleteCourseMajorComboBox->setCurrentIndex(0);
    ui->addDeleteCourseNameComboBox->setCurrentIndex(0);
}










void MainWindow::on_gradeSearchButton_clicked() {
    int studentID = ui->updateStudentIDText->text().toInt();
    QString year = ui->updateYearComboBox->currentText();
    QString major = ui->updateMajorComboBox->currentText();
    QString courseName = ui->updateCourseNameComboBox->currentText();

    student* stn = manager->searchStudentID(studentID);
    if (studentID == 0) {
        QMessageBox::warning(this, "실패", "학번을 입력해주세요.");
        gradeFrameClear();
        return;
    }
    else if (stn == nullptr) {
        QMessageBox::warning(this, "실패", "학번을 확인해주세요.");
        gradeFrameClear();
        return;
    }
    else if (!year.isEmpty() || !major.isEmpty() || !courseName.isEmpty()) {
        QMessageBox::warning(this, "실패", "학번만 입력해주세요.");
        gradeFrameClear();
        return;
    }
    else {
        gradeTable(stn);
        QMessageBox::information(this, "성공", "조회가 완료되었습니다.");
        gradeFrameClear();
    }
}
void MainWindow::on_gradeRegistrationButton_clicked() {
    int studentID = ui->updateStudentIDText->text().toInt();
    QString year = ui->updateYearComboBox->currentText();
    QString major = ui->updateMajorComboBox->currentText();
    QString courseName = ui-> updateCourseNameComboBox->currentText();
    QString grade = ui-> updateCourseGradeCombobox->currentText();
    student* stn = manager->searchStudentID(studentID);
    if(studentID == 0 || year.isEmpty() || major.isEmpty() || courseName.isEmpty() || grade.isEmpty()) {
        QMessageBox::warning(this,"실패","정보를 모두 입력해주세요");
        gradeFrameClear();
        return;
    }
    else if(stn == nullptr) {
        QMessageBox::warning(this, "실패", "학번을 확인해주세요");
        gradeFrameClear();
        return;
    }
    else if(stn->courseList == nullptr){
        QMessageBox::warning(this,"실패","수강 과목을 등록해주세요.");
        gradeFrameClear();
        return;
    }
    else if(stn->getYear() == year && stn->getMajor() == major) {
        course* currentCourse = stn->courseList;
        while(currentCourse != nullptr) {
            if(currentCourse->getCourseName() == courseName) {
                manager->updateGrade(stn, courseName, grade);
                double GPA =  stn->calculateGPA();
                stn->SetGPA(GPA);
                gradeTable(stn);
                QMessageBox::information(this,"성공","성적 등록에 성공했습니다.");
                gradeFrameClear();
                return;
            }
            currentCourse = currentCourse->courseNext;
        }
            QMessageBox::warning(this,"실패","수강 과목을 등록해주세요.");
            gradeFrameClear();
            return;
    }
    QMessageBox::warning(this,"실패","학생 정보를 확인해주세요.");
    gradeFrameClear();
    return;
}
void MainWindow::gradeTable(student* stn) {
    ui->upgradeGradeTable->setRowCount(0);
    course* currentCourse = stn->courseList;
    int row = 0;
    if(currentCourse == nullptr) {
        ui->upgradeGradeTable->insertRow(row);
        ui->upgradeGradeTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
        ui->upgradeGradeTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
        ui->upgradeGradeTable->setItem(row, 2, new QTableWidgetItem(stn->getYear()));
        ui->upgradeGradeTable->setItem(row, 3, new QTableWidgetItem(stn->getMajor()));

    }
    else {
        while (currentCourse != nullptr) {
            ui->upgradeGradeTable->insertRow(row);
            ui->upgradeGradeTable->setItem(row, 0, new QTableWidgetItem(QString::number(stn->getStudentID())));
            ui->upgradeGradeTable->setItem(row, 1, new QTableWidgetItem(stn->getName()));
            ui->upgradeGradeTable->setItem(row, 2, new QTableWidgetItem(stn->getYear()));
            ui->upgradeGradeTable->setItem(row, 3, new QTableWidgetItem(stn->getMajor()));
            ui->upgradeGradeTable->setItem(row, 4, new QTableWidgetItem(currentCourse->getCourseName()));
            ui->upgradeGradeTable->setItem(row, 5, new QTableWidgetItem(currentCourse->getGrade()));
            row++;
            currentCourse = currentCourse->courseNext;
        }
    }
}
void MainWindow::gradeFrameClear() {
    ui->updateStudentIDText->clear();
    ui->updateYearComboBox->setCurrentIndex(0);
    ui->updateMajorComboBox->setCurrentIndex(0);
    ui->updateCourseNameComboBox->setCurrentIndex(0);
    ui->updateCourseGradeCombobox->setCurrentIndex(0);
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









MainWindow::~MainWindow()
{
    clearAllStudents();
    qDebug() << "클리어 후 헤드 포인터 주소 : " << management::manageHead  << "  main window.cpp ";
    delete ui;
}




