/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Search;
    QFrame *frame_4;
    QLineEdit *searchStudentIDText;
    QLabel *searchStudentID;
    QPushButton *studentSearchButton;
    QPushButton *allStudentSearchButton;
    QTableWidget *tableWidget_3;
    QLabel *label_4;
    QWidget *regstration;
    QFrame *frame;
    QLineEdit *registrationStudentIDText;
    QLabel *registrationStudentID;
    QLabel *registrationName;
    QLineEdit *registrationNameText;
    QLabel *registrationMajor;
    QLineEdit *registrationMajorText;
    QLabel *registrationYear;
    QLineEdit *registrationYearText;
    QPushButton *registrationpushButton;
    QLabel *registrationCourseName;
    QLineEdit *registrationCourseNameText;
    QLabel *registrationGrade;
    QLineEdit *registrationGradeText;
    QTableWidget *tableWidget;
    QLabel *label;
    QWidget *tab;
    QLabel *label_3;
    QFrame *frame_6;
    QLineEdit *deleteStudentText;
    QLabel *deleteStudent;
    QPushButton *deleteStudentPushButton;
    QTableWidget *tableWidget_4;
    QWidget *Course;
    QLabel *label_2;
    QFrame *frame_2;
    QLineEdit *AddCourseStudentIDText;
    QLabel *AddCourseStudentID;
    QLabel *AddCourse;
    QLineEdit *AddCourseText;
    QLabel *AddCourseGrade;
    QLineEdit *AddCourseGradeText;
    QPushButton *AddCoursePushButton;
    QTableWidget *tableWidget_2;
    QWidget *tab_2;
    QLabel *label_6;
    QWidget *Update;
    QLabel *label_5;
    QFrame *frame_5;
    QLineEdit *updateStudentIDText;
    QLabel *updateStudentID;
    QLabel *updateCourse;
    QLineEdit *updateCourseText;
    QLabel *updateGrade;
    QLineEdit *updateGradeText;
    QPushButton *updateButton;
    QTableWidget *tableWidget_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1233, 799);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(100, 20, 1061, 721));
        Search = new QWidget();
        Search->setObjectName("Search");
        frame_4 = new QFrame(Search);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(110, 70, 701, 81));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        searchStudentIDText = new QLineEdit(frame_4);
        searchStudentIDText->setObjectName("searchStudentIDText");
        searchStudentIDText->setGeometry(QRect(170, 30, 261, 26));
        searchStudentID = new QLabel(frame_4);
        searchStudentID->setObjectName("searchStudentID");
        searchStudentID->setGeometry(QRect(30, 30, 91, 18));
        studentSearchButton = new QPushButton(frame_4);
        studentSearchButton->setObjectName("studentSearchButton");
        studentSearchButton->setGeometry(QRect(460, 30, 93, 26));
        allStudentSearchButton = new QPushButton(frame_4);
        allStudentSearchButton->setObjectName("allStudentSearchButton");
        allStudentSearchButton->setGeometry(QRect(580, 30, 93, 26));
        tableWidget_3 = new QTableWidget(Search);
        if (tableWidget_3->columnCount() < 7)
            tableWidget_3->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget_3->setObjectName("tableWidget_3");
        tableWidget_3->setGeometry(QRect(120, 200, 701, 321));
        label_4 = new QLabel(Search);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 30, 341, 31));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        label_4->setFont(font);
        tabWidget->addTab(Search, QString());
        regstration = new QWidget();
        regstration->setObjectName("regstration");
        frame = new QFrame(regstration);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 70, 931, 161));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        registrationStudentIDText = new QLineEdit(frame);
        registrationStudentIDText->setObjectName("registrationStudentIDText");
        registrationStudentIDText->setGeometry(QRect(100, 30, 113, 26));
        registrationStudentID = new QLabel(frame);
        registrationStudentID->setObjectName("registrationStudentID");
        registrationStudentID->setGeometry(QRect(20, 30, 91, 18));
        registrationName = new QLabel(frame);
        registrationName->setObjectName("registrationName");
        registrationName->setGeometry(QRect(230, 30, 51, 18));
        registrationNameText = new QLineEdit(frame);
        registrationNameText->setObjectName("registrationNameText");
        registrationNameText->setGeometry(QRect(280, 30, 113, 26));
        registrationMajor = new QLabel(frame);
        registrationMajor->setObjectName("registrationMajor");
        registrationMajor->setGeometry(QRect(410, 30, 51, 18));
        registrationMajorText = new QLineEdit(frame);
        registrationMajorText->setObjectName("registrationMajorText");
        registrationMajorText->setGeometry(QRect(460, 30, 113, 26));
        registrationYear = new QLabel(frame);
        registrationYear->setObjectName("registrationYear");
        registrationYear->setGeometry(QRect(590, 30, 51, 18));
        registrationYearText = new QLineEdit(frame);
        registrationYearText->setObjectName("registrationYearText");
        registrationYearText->setGeometry(QRect(630, 30, 113, 26));
        registrationpushButton = new QPushButton(frame);
        registrationpushButton->setObjectName("registrationpushButton");
        registrationpushButton->setGeometry(QRect(810, 30, 93, 26));
        registrationCourseName = new QLabel(frame);
        registrationCourseName->setObjectName("registrationCourseName");
        registrationCourseName->setGeometry(QRect(20, 90, 91, 18));
        registrationCourseNameText = new QLineEdit(frame);
        registrationCourseNameText->setObjectName("registrationCourseNameText");
        registrationCourseNameText->setGeometry(QRect(120, 90, 113, 26));
        registrationGrade = new QLabel(frame);
        registrationGrade->setObjectName("registrationGrade");
        registrationGrade->setGeometry(QRect(260, 90, 51, 18));
        registrationGradeText = new QLineEdit(frame);
        registrationGradeText->setObjectName("registrationGradeText");
        registrationGradeText->setGeometry(QRect(320, 90, 113, 26));
        tableWidget = new QTableWidget(regstration);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(200, 310, 601, 351));
        label = new QLabel(regstration);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 341, 31));
        label->setFont(font);
        tabWidget->addTab(regstration, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 30, 341, 31));
        label_3->setFont(font);
        frame_6 = new QFrame(tab);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(30, 90, 931, 81));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        deleteStudentText = new QLineEdit(frame_6);
        deleteStudentText->setObjectName("deleteStudentText");
        deleteStudentText->setGeometry(QRect(120, 30, 201, 26));
        deleteStudent = new QLabel(frame_6);
        deleteStudent->setObjectName("deleteStudent");
        deleteStudent->setGeometry(QRect(30, 30, 91, 18));
        deleteStudentPushButton = new QPushButton(frame_6);
        deleteStudentPushButton->setObjectName("deleteStudentPushButton");
        deleteStudentPushButton->setGeometry(QRect(810, 30, 93, 26));
        tableWidget_4 = new QTableWidget(tab);
        if (tableWidget_4->columnCount() < 4)
            tableWidget_4->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        tableWidget_4->setObjectName("tableWidget_4");
        tableWidget_4->setGeometry(QRect(220, 210, 401, 351));
        tabWidget->addTab(tab, QString());
        Course = new QWidget();
        Course->setObjectName("Course");
        label_2 = new QLabel(Course);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 20, 161, 31));
        label_2->setFont(font);
        frame_2 = new QFrame(Course);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(40, 60, 801, 81));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        AddCourseStudentIDText = new QLineEdit(frame_2);
        AddCourseStudentIDText->setObjectName("AddCourseStudentIDText");
        AddCourseStudentIDText->setGeometry(QRect(110, 30, 113, 26));
        AddCourseStudentID = new QLabel(frame_2);
        AddCourseStudentID->setObjectName("AddCourseStudentID");
        AddCourseStudentID->setGeometry(QRect(20, 30, 91, 18));
        AddCourse = new QLabel(frame_2);
        AddCourse->setObjectName("AddCourse");
        AddCourse->setGeometry(QRect(260, 30, 51, 18));
        AddCourseText = new QLineEdit(frame_2);
        AddCourseText->setObjectName("AddCourseText");
        AddCourseText->setGeometry(QRect(320, 30, 113, 26));
        AddCourseGrade = new QLabel(frame_2);
        AddCourseGrade->setObjectName("AddCourseGrade");
        AddCourseGrade->setGeometry(QRect(480, 30, 51, 18));
        AddCourseGradeText = new QLineEdit(frame_2);
        AddCourseGradeText->setObjectName("AddCourseGradeText");
        AddCourseGradeText->setGeometry(QRect(530, 30, 113, 26));
        AddCoursePushButton = new QPushButton(frame_2);
        AddCoursePushButton->setObjectName("AddCoursePushButton");
        AddCoursePushButton->setGeometry(QRect(690, 30, 93, 26));
        tableWidget_2 = new QTableWidget(Course);
        if (tableWidget_2->columnCount() < 6)
            tableWidget_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setGeometry(QRect(140, 180, 611, 301));
        tabWidget->addTab(Course, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 30, 161, 31));
        label_6->setFont(font);
        tabWidget->addTab(tab_2, QString());
        Update = new QWidget();
        Update->setObjectName("Update");
        label_5 = new QLabel(Update);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 20, 161, 31));
        label_5->setFont(font);
        frame_5 = new QFrame(Update);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(30, 60, 801, 81));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        updateStudentIDText = new QLineEdit(frame_5);
        updateStudentIDText->setObjectName("updateStudentIDText");
        updateStudentIDText->setGeometry(QRect(110, 30, 113, 26));
        updateStudentID = new QLabel(frame_5);
        updateStudentID->setObjectName("updateStudentID");
        updateStudentID->setGeometry(QRect(20, 30, 91, 18));
        updateCourse = new QLabel(frame_5);
        updateCourse->setObjectName("updateCourse");
        updateCourse->setGeometry(QRect(260, 30, 51, 18));
        updateCourseText = new QLineEdit(frame_5);
        updateCourseText->setObjectName("updateCourseText");
        updateCourseText->setGeometry(QRect(320, 30, 113, 26));
        updateGrade = new QLabel(frame_5);
        updateGrade->setObjectName("updateGrade");
        updateGrade->setGeometry(QRect(480, 30, 51, 18));
        updateGradeText = new QLineEdit(frame_5);
        updateGradeText->setObjectName("updateGradeText");
        updateGradeText->setGeometry(QRect(530, 30, 113, 26));
        updateButton = new QPushButton(frame_5);
        updateButton->setObjectName("updateButton");
        updateButton->setGeometry(QRect(690, 30, 93, 26));
        tableWidget_5 = new QTableWidget(Update);
        if (tableWidget_5->columnCount() < 6)
            tableWidget_5->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(3, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(4, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(5, __qtablewidgetitem28);
        tableWidget_5->setObjectName("tableWidget_5");
        tableWidget_5->setGeometry(QRect(150, 190, 611, 301));
        tabWidget->addTab(Update, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1233, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchStudentIDText->setText(QString());
        searchStudentID->setText(QCoreApplication::translate("MainWindow", "StudentID", nullptr));
        studentSearchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        allStudentSearchButton->setText(QCoreApplication::translate("MainWindow", "All Search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "studentID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "major", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_3->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "year", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "courseName", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_3->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "GPA", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Student Search", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Search), QCoreApplication::translate("MainWindow", "Page", nullptr));
        registrationStudentID->setText(QCoreApplication::translate("MainWindow", "StudentID", nullptr));
        registrationName->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        registrationMajor->setText(QCoreApplication::translate("MainWindow", "Major", nullptr));
        registrationYear->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        registrationpushButton->setText(QCoreApplication::translate("MainWindow", "Registration", nullptr));
        registrationCourseName->setText(QCoreApplication::translate("MainWindow", "courseName", nullptr));
        registrationGrade->setText(QCoreApplication::translate("MainWindow", "grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "studentID", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "major", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "year", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "courseName", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "grade", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Student Registration", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(regstration), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Delete Student", nullptr));
        deleteStudent->setText(QCoreApplication::translate("MainWindow", "StudentID", nullptr));
        deleteStudentPushButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "studentID", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "major", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "year", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Page", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Add course", nullptr));
        AddCourseStudentID->setText(QCoreApplication::translate("MainWindow", "StudentID", nullptr));
        AddCourse->setText(QCoreApplication::translate("MainWindow", "Course", nullptr));
        AddCourseGrade->setText(QCoreApplication::translate("MainWindow", "Grade", nullptr));
        AddCoursePushButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "studentID", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "New Column", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "major", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_2->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "courseName", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_2->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "grade", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Course), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "course Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Page", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Update grade", nullptr));
        updateStudentID->setText(QCoreApplication::translate("MainWindow", "StudentID", nullptr));
        updateCourse->setText(QCoreApplication::translate("MainWindow", "Course", nullptr));
        updateGrade->setText(QCoreApplication::translate("MainWindow", "Grade", nullptr));
        updateButton->setText(QCoreApplication::translate("MainWindow", "Update", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "studentID", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_5->horizontalHeaderItem(1);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_5->horizontalHeaderItem(2);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "major", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_5->horizontalHeaderItem(3);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "year", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_5->horizontalHeaderItem(4);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "courseName", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_5->horizontalHeaderItem(5);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "grade", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Update), QCoreApplication::translate("MainWindow", "Page", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
