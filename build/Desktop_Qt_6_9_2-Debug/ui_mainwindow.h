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
#include <QtWidgets/QComboBox>
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
    QWidget *searchTab;
    QFrame *searchFrame;
    QLineEdit *searchStudentIDText;
    QLabel *searchStudentID;
    QPushButton *studentSearchButton;
    QPushButton *allStudentSearchButton;
    QLabel *searchMajor;
    QLabel *searchYear;
    QComboBox *searchMajorComboBox;
    QComboBox *searchYearComboBox;
    QTableWidget *searchTable;
    QLabel *label_4;
    QLabel *label_8;
    QPushButton *ascPushButton;
    QPushButton *descPushButton;
    QComboBox *sortComboBox;
    QWidget *registrationTab;
    QFrame *registrationFrame;
    QLabel *registrationStudentID;
    QLabel *registrationName;
    QLineEdit *registrationNameText;
    QLabel *registrationMajor;
    QLabel *registrationYear;
    QComboBox *registrationMajorComboBox;
    QComboBox *registrationYearComboBox;
    QPushButton *registrationPushButton;
    QLineEdit *registrationStudentIDText;
    QPushButton *deleteStudentPushButton;
    QTableWidget *registrationTable;
    QLabel *label;
    QLabel *label_7;
    QWidget *addDeleteCourseTab;
    QLabel *label_2;
    QFrame *addDeleteFrame;
    QLineEdit *addDeleteCourseStudentIDText;
    QLabel *addDeleteCourseStudentID;
    QLabel *addDeleteCourseName;
    QLabel *addDeleteMajor;
    QComboBox *addDeleteCourseMajorComboBox;
    QComboBox *addDeleteCourseNameComboBox;
    QPushButton *courseSearchPushButton;
    QPushButton *courseAddPushButton;
    QPushButton *courseDeletePushButton;
    QLabel *addDeleteCoursYear;
    QComboBox *addDeleteYearComboBox;
    QTableWidget *courseSearchTable;
    QLabel *label_10;
    QWidget *updateTab;
    QLabel *label_5;
    QFrame *updateGradeFrame;
    QLineEdit *updateStudentIDText;
    QLabel *updateStudentID;
    QLabel *updateCourse;
    QLabel *updateGrade;
    QComboBox *updateCourseGradeCombobox;
    QComboBox *updateCourseNameComboBox;
    QPushButton *gradeRegistrationButton;
    QPushButton *gradeSearchButton;
    QComboBox *updateMajorComboBox;
    QLabel *gradeMajor;
    QLabel *updateYear;
    QComboBox *updateYearComboBox;
    QTableWidget *upgradeGradeTable;
    QLabel *label_12;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1421, 912);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 60, 1281, 761));
        tabWidget->setToolTipDuration(-1);
        searchTab = new QWidget();
        searchTab->setObjectName("searchTab");
        searchFrame = new QFrame(searchTab);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setGeometry(QRect(120, 80, 1051, 71));
        searchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Shadow::Raised);
        searchStudentIDText = new QLineEdit(searchFrame);
        searchStudentIDText->setObjectName("searchStudentIDText");
        searchStudentIDText->setGeometry(QRect(120, 20, 111, 26));
        searchStudentID = new QLabel(searchFrame);
        searchStudentID->setObjectName("searchStudentID");
        searchStudentID->setGeometry(QRect(70, 20, 41, 18));
        QFont font;
        font.setPointSize(13);
        searchStudentID->setFont(font);
        studentSearchButton = new QPushButton(searchFrame);
        studentSearchButton->setObjectName("studentSearchButton");
        studentSearchButton->setGeometry(QRect(840, 20, 81, 26));
        QFont font1;
        font1.setPointSize(12);
        studentSearchButton->setFont(font1);
        allStudentSearchButton = new QPushButton(searchFrame);
        allStudentSearchButton->setObjectName("allStudentSearchButton");
        allStudentSearchButton->setGeometry(QRect(942, 20, 81, 26));
        allStudentSearchButton->setFont(font1);
        searchMajor = new QLabel(searchFrame);
        searchMajor->setObjectName("searchMajor");
        searchMajor->setGeometry(QRect(550, 20, 51, 18));
        searchMajor->setFont(font);
        searchYear = new QLabel(searchFrame);
        searchYear->setObjectName("searchYear");
        searchYear->setGeometry(QRect(300, 20, 51, 18));
        searchYear->setFont(font);
        searchMajorComboBox = new QComboBox(searchFrame);
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->addItem(QString());
        searchMajorComboBox->setObjectName("searchMajorComboBox");
        searchMajorComboBox->setGeometry(QRect(610, 20, 111, 26));
        searchYearComboBox = new QComboBox(searchFrame);
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->addItem(QString());
        searchYearComboBox->setObjectName("searchYearComboBox");
        searchYearComboBox->setGeometry(QRect(360, 20, 111, 26));
        searchTable = new QTableWidget(searchTab);
        if (searchTable->columnCount() < 5)
            searchTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        searchTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        searchTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        searchTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        searchTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        searchTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        searchTable->setObjectName("searchTable");
        searchTable->setGeometry(QRect(170, 220, 921, 431));
        searchTable->setSortingEnabled(false);
        searchTable->horizontalHeader()->setDefaultSectionSize(180);
        label_4 = new QLabel(searchTab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 30, 281, 31));
        QFont font2;
        font2.setPointSize(19);
        font2.setBold(true);
        label_4->setFont(font2);
        label_8 = new QLabel(searchTab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(150, 190, 151, 18));
        QFont font3;
        font3.setPointSize(14);
        label_8->setFont(font3);
        ascPushButton = new QPushButton(searchTab);
        ascPushButton->setObjectName("ascPushButton");
        ascPushButton->setGeometry(QRect(430, 185, 41, 21));
        descPushButton = new QPushButton(searchTab);
        descPushButton->setObjectName("descPushButton");
        descPushButton->setGeometry(QRect(480, 185, 41, 21));
        sortComboBox = new QComboBox(searchTab);
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->addItem(QString());
        sortComboBox->setObjectName("sortComboBox");
        sortComboBox->setGeometry(QRect(300, 180, 121, 31));
        sortComboBox->setFont(font1);
        tabWidget->addTab(searchTab, QString());
        registrationTab = new QWidget();
        registrationTab->setObjectName("registrationTab");
        registrationFrame = new QFrame(registrationTab);
        registrationFrame->setObjectName("registrationFrame");
        registrationFrame->setGeometry(QRect(90, 80, 1101, 111));
        registrationFrame->setFrameShape(QFrame::Shape::StyledPanel);
        registrationFrame->setFrameShadow(QFrame::Shadow::Raised);
        registrationStudentID = new QLabel(registrationFrame);
        registrationStudentID->setObjectName("registrationStudentID");
        registrationStudentID->setGeometry(QRect(40, 20, 61, 18));
        registrationStudentID->setFont(font);
        registrationName = new QLabel(registrationFrame);
        registrationName->setObjectName("registrationName");
        registrationName->setGeometry(QRect(280, 20, 51, 18));
        registrationName->setFont(font);
        registrationNameText = new QLineEdit(registrationFrame);
        registrationNameText->setObjectName("registrationNameText");
        registrationNameText->setGeometry(QRect(340, 20, 121, 26));
        registrationMajor = new QLabel(registrationFrame);
        registrationMajor->setObjectName("registrationMajor");
        registrationMajor->setGeometry(QRect(740, 20, 51, 18));
        registrationMajor->setFont(font);
        registrationYear = new QLabel(registrationFrame);
        registrationYear->setObjectName("registrationYear");
        registrationYear->setGeometry(QRect(520, 20, 51, 18));
        registrationYear->setFont(font);
        registrationMajorComboBox = new QComboBox(registrationFrame);
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->addItem(QString());
        registrationMajorComboBox->setObjectName("registrationMajorComboBox");
        registrationMajorComboBox->setGeometry(QRect(800, 20, 121, 26));
        registrationYearComboBox = new QComboBox(registrationFrame);
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->addItem(QString());
        registrationYearComboBox->setObjectName("registrationYearComboBox");
        registrationYearComboBox->setGeometry(QRect(570, 20, 121, 26));
        registrationPushButton = new QPushButton(registrationFrame);
        registrationPushButton->setObjectName("registrationPushButton");
        registrationPushButton->setGeometry(QRect(970, 20, 93, 31));
        registrationPushButton->setFont(font);
        registrationStudentIDText = new QLineEdit(registrationFrame);
        registrationStudentIDText->setObjectName("registrationStudentIDText");
        registrationStudentIDText->setGeometry(QRect(110, 20, 121, 26));
        deleteStudentPushButton = new QPushButton(registrationFrame);
        deleteStudentPushButton->setObjectName("deleteStudentPushButton");
        deleteStudentPushButton->setGeometry(QRect(970, 70, 93, 26));
        deleteStudentPushButton->setFont(font);
        registrationTable = new QTableWidget(registrationTab);
        if (registrationTable->columnCount() < 4)
            registrationTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        registrationTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        registrationTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        registrationTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        registrationTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        registrationTable->setObjectName("registrationTable");
        registrationTable->setGeometry(QRect(220, 260, 821, 391));
        registrationTable->setFont(font3);
        registrationTable->horizontalHeader()->setDefaultSectionSize(200);
        label = new QLabel(registrationTab);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 30, 201, 31));
        label->setFont(font2);
        label_7 = new QLabel(registrationTab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(170, 210, 211, 31));
        QFont font4;
        font4.setPointSize(15);
        label_7->setFont(font4);
        tabWidget->addTab(registrationTab, QString());
        addDeleteCourseTab = new QWidget();
        addDeleteCourseTab->setObjectName("addDeleteCourseTab");
        label_2 = new QLabel(addDeleteCourseTab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 30, 231, 31));
        QFont font5;
        font5.setPointSize(18);
        font5.setBold(true);
        label_2->setFont(font5);
        addDeleteFrame = new QFrame(addDeleteCourseTab);
        addDeleteFrame->setObjectName("addDeleteFrame");
        addDeleteFrame->setGeometry(QRect(100, 80, 1071, 151));
        addDeleteFrame->setFrameShape(QFrame::Shape::StyledPanel);
        addDeleteFrame->setFrameShadow(QFrame::Shadow::Raised);
        addDeleteCourseStudentIDText = new QLineEdit(addDeleteFrame);
        addDeleteCourseStudentIDText->setObjectName("addDeleteCourseStudentIDText");
        addDeleteCourseStudentIDText->setGeometry(QRect(100, 30, 113, 26));
        addDeleteCourseStudentID = new QLabel(addDeleteFrame);
        addDeleteCourseStudentID->setObjectName("addDeleteCourseStudentID");
        addDeleteCourseStudentID->setGeometry(QRect(60, 30, 51, 18));
        addDeleteCourseStudentID->setFont(font);
        addDeleteCourseName = new QLabel(addDeleteFrame);
        addDeleteCourseName->setObjectName("addDeleteCourseName");
        addDeleteCourseName->setGeometry(QRect(700, 30, 71, 18));
        addDeleteCourseName->setFont(font);
        addDeleteMajor = new QLabel(addDeleteFrame);
        addDeleteMajor->setObjectName("addDeleteMajor");
        addDeleteMajor->setGeometry(QRect(500, 30, 41, 18));
        addDeleteMajor->setFont(font);
        addDeleteCourseMajorComboBox = new QComboBox(addDeleteFrame);
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->addItem(QString());
        addDeleteCourseMajorComboBox->setObjectName("addDeleteCourseMajorComboBox");
        addDeleteCourseMajorComboBox->setGeometry(QRect(550, 30, 111, 26));
        addDeleteCourseNameComboBox = new QComboBox(addDeleteFrame);
        addDeleteCourseNameComboBox->setObjectName("addDeleteCourseNameComboBox");
        addDeleteCourseNameComboBox->setGeometry(QRect(780, 30, 111, 26));
        courseSearchPushButton = new QPushButton(addDeleteFrame);
        courseSearchPushButton->setObjectName("courseSearchPushButton");
        courseSearchPushButton->setGeometry(QRect(940, 20, 93, 26));
        courseSearchPushButton->setFont(font);
        courseAddPushButton = new QPushButton(addDeleteFrame);
        courseAddPushButton->setObjectName("courseAddPushButton");
        courseAddPushButton->setGeometry(QRect(940, 60, 93, 26));
        courseAddPushButton->setFont(font);
        courseDeletePushButton = new QPushButton(addDeleteFrame);
        courseDeletePushButton->setObjectName("courseDeletePushButton");
        courseDeletePushButton->setGeometry(QRect(940, 100, 93, 26));
        courseDeletePushButton->setFont(font);
        addDeleteCoursYear = new QLabel(addDeleteFrame);
        addDeleteCoursYear->setObjectName("addDeleteCoursYear");
        addDeleteCoursYear->setGeometry(QRect(270, 30, 51, 18));
        addDeleteCoursYear->setFont(font);
        addDeleteYearComboBox = new QComboBox(addDeleteFrame);
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->addItem(QString());
        addDeleteYearComboBox->setObjectName("addDeleteYearComboBox");
        addDeleteYearComboBox->setGeometry(QRect(320, 30, 121, 26));
        courseSearchTable = new QTableWidget(addDeleteCourseTab);
        if (courseSearchTable->columnCount() < 5)
            courseSearchTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        courseSearchTable->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        courseSearchTable->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        courseSearchTable->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        courseSearchTable->setHorizontalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        courseSearchTable->setHorizontalHeaderItem(4, __qtablewidgetitem13);
        courseSearchTable->setObjectName("courseSearchTable");
        courseSearchTable->setGeometry(QRect(180, 290, 921, 391));
        courseSearchTable->horizontalHeader()->setDefaultSectionSize(180);
        label_10 = new QLabel(addDeleteCourseTab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(180, 240, 161, 31));
        label_10->setFont(font4);
        tabWidget->addTab(addDeleteCourseTab, QString());
        updateTab = new QWidget();
        updateTab->setObjectName("updateTab");
        label_5 = new QLabel(updateTab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(60, 30, 231, 31));
        label_5->setFont(font5);
        updateGradeFrame = new QFrame(updateTab);
        updateGradeFrame->setObjectName("updateGradeFrame");
        updateGradeFrame->setGeometry(QRect(100, 70, 1091, 131));
        updateGradeFrame->setFrameShape(QFrame::Shape::StyledPanel);
        updateGradeFrame->setFrameShadow(QFrame::Shadow::Raised);
        updateStudentIDText = new QLineEdit(updateGradeFrame);
        updateStudentIDText->setObjectName("updateStudentIDText");
        updateStudentIDText->setGeometry(QRect(150, 30, 113, 26));
        updateStudentID = new QLabel(updateGradeFrame);
        updateStudentID->setObjectName("updateStudentID");
        updateStudentID->setGeometry(QRect(90, 30, 41, 18));
        updateStudentID->setFont(font);
        updateCourse = new QLabel(updateGradeFrame);
        updateCourse->setObjectName("updateCourse");
        updateCourse->setGeometry(QRect(70, 80, 71, 18));
        updateCourse->setFont(font);
        updateGrade = new QLabel(updateGradeFrame);
        updateGrade->setObjectName("updateGrade");
        updateGrade->setGeometry(QRect(330, 80, 41, 18));
        updateGrade->setFont(font);
        updateCourseGradeCombobox = new QComboBox(updateGradeFrame);
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->addItem(QString());
        updateCourseGradeCombobox->setObjectName("updateCourseGradeCombobox");
        updateCourseGradeCombobox->setGeometry(QRect(380, 80, 121, 26));
        updateCourseNameComboBox = new QComboBox(updateGradeFrame);
        updateCourseNameComboBox->setObjectName("updateCourseNameComboBox");
        updateCourseNameComboBox->setGeometry(QRect(150, 80, 111, 26));
        gradeRegistrationButton = new QPushButton(updateGradeFrame);
        gradeRegistrationButton->setObjectName("gradeRegistrationButton");
        gradeRegistrationButton->setGeometry(QRect(880, 80, 181, 31));
        gradeRegistrationButton->setFont(font1);
        gradeSearchButton = new QPushButton(updateGradeFrame);
        gradeSearchButton->setObjectName("gradeSearchButton");
        gradeSearchButton->setGeometry(QRect(950, 30, 101, 31));
        gradeSearchButton->setFont(font1);
        updateMajorComboBox = new QComboBox(updateGradeFrame);
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->addItem(QString());
        updateMajorComboBox->setObjectName("updateMajorComboBox");
        updateMajorComboBox->setGeometry(QRect(640, 30, 111, 26));
        gradeMajor = new QLabel(updateGradeFrame);
        gradeMajor->setObjectName("gradeMajor");
        gradeMajor->setGeometry(QRect(600, 30, 41, 18));
        gradeMajor->setFont(font);
        updateYear = new QLabel(updateGradeFrame);
        updateYear->setObjectName("updateYear");
        updateYear->setGeometry(QRect(330, 30, 41, 18));
        updateYear->setFont(font);
        updateYearComboBox = new QComboBox(updateGradeFrame);
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->addItem(QString());
        updateYearComboBox->setObjectName("updateYearComboBox");
        updateYearComboBox->setGeometry(QRect(380, 30, 121, 26));
        upgradeGradeTable = new QTableWidget(updateTab);
        if (upgradeGradeTable->columnCount() < 6)
            upgradeGradeTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font);
        upgradeGradeTable->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font);
        upgradeGradeTable->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        upgradeGradeTable->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setFont(font);
        upgradeGradeTable->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setFont(font);
        upgradeGradeTable->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setFont(font);
        upgradeGradeTable->setHorizontalHeaderItem(5, __qtablewidgetitem19);
        upgradeGradeTable->setObjectName("upgradeGradeTable");
        upgradeGradeTable->setGeometry(QRect(100, 280, 1101, 391));
        upgradeGradeTable->horizontalHeader()->setMinimumSectionSize(180);
        upgradeGradeTable->horizontalHeader()->setDefaultSectionSize(180);
        label_12 = new QLabel(updateTab);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(80, 240, 141, 21));
        label_12->setFont(font4);
        tabWidget->addTab(updateTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1421, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchStudentIDText->setText(QString());
        searchStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        studentSearchButton->setText(QCoreApplication::translate("MainWindow", "\354\241\260\355\232\214", nullptr));
        allStudentSearchButton->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \354\241\260\355\232\214", nullptr));
        searchMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        searchYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        searchMajorComboBox->setItemText(0, QString());
        searchMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        searchMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        searchMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        searchYearComboBox->setItemText(0, QString());
        searchYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        searchYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        searchYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        searchYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        searchYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        searchYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        QTableWidgetItem *___qtablewidgetitem = searchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = searchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = searchTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = searchTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = searchTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\354\241\270\354\227\205 \355\225\231\354\240\220", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\240\225\353\263\264 \354\241\260\355\232\214", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        ascPushButton->setText(QCoreApplication::translate("MainWindow", "\342\226\262", nullptr));
        descPushButton->setText(QCoreApplication::translate("MainWindow", "\342\226\274", nullptr));
        sortComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\354\240\225\353\240\254 \352\270\260\354\244\200", nullptr));
        sortComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        sortComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        sortComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        sortComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\355\217\211\352\267\240 \354\241\270\354\227\205 \355\225\231\354\240\220", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(searchTab), QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\240\225\353\263\264 \354\241\260\355\232\214", nullptr));
        registrationStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        registrationName->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        registrationMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        registrationYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        registrationMajorComboBox->setItemText(0, QString());
        registrationMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        registrationMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        registrationMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        registrationYearComboBox->setItemText(0, QString());
        registrationYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        registrationYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        registrationYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        registrationYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        registrationYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        registrationYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        registrationPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235", nullptr));
        deleteStudentPushButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \354\202\255\354\240\234", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = registrationTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = registrationTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = registrationTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = registrationTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235 \353\260\217 \354\202\255\354\240\234", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264 \355\225\231\354\203\235 \353\246\254\354\212\244\355\212\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(registrationTab), QCoreApplication::translate("MainWindow", "\355\225\231\354\203\235 \353\223\261\353\241\235 \353\260\217 \354\202\255\354\240\234", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251 \354\266\224\352\260\200 \353\260\217 \354\202\255\354\240\234", nullptr));
        addDeleteCourseStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        addDeleteCourseName->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        addDeleteMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        addDeleteCourseMajorComboBox->setItemText(0, QString());
        addDeleteCourseMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        addDeleteCourseMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        addDeleteCourseMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        courseSearchPushButton->setText(QCoreApplication::translate("MainWindow", " \355\225\231\353\262\210 \354\241\260\355\232\214", nullptr));
        courseAddPushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\266\224\352\260\200", nullptr));
        courseDeletePushButton->setText(QCoreApplication::translate("MainWindow", "\352\263\274\353\252\251 \354\202\255\354\240\234", nullptr));
        addDeleteCoursYear->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        addDeleteYearComboBox->setItemText(0, QString());
        addDeleteYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        addDeleteYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        addDeleteYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        addDeleteYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        addDeleteYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        addDeleteYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        QTableWidgetItem *___qtablewidgetitem9 = courseSearchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = courseSearchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = courseSearchTable->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = courseSearchTable->horizontalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = courseSearchTable->horizontalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251 \353\246\254\354\212\244\355\212\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(addDeleteCourseTab), QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251 \354\266\224\352\260\200 \353\260\217 \354\202\255\354\240\234", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\354\204\261\354\240\201 \353\223\261\353\241\235 \353\260\217 \354\210\230\354\240\225", nullptr));
        updateStudentID->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        updateCourse->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        updateGrade->setText(QCoreApplication::translate("MainWindow", "\354\204\261\354\240\201", nullptr));
        updateCourseGradeCombobox->setItemText(0, QString());
        updateCourseGradeCombobox->setItemText(1, QCoreApplication::translate("MainWindow", "A+", nullptr));
        updateCourseGradeCombobox->setItemText(2, QCoreApplication::translate("MainWindow", "A", nullptr));
        updateCourseGradeCombobox->setItemText(3, QCoreApplication::translate("MainWindow", "B+", nullptr));
        updateCourseGradeCombobox->setItemText(4, QCoreApplication::translate("MainWindow", "B", nullptr));
        updateCourseGradeCombobox->setItemText(5, QCoreApplication::translate("MainWindow", "C+", nullptr));
        updateCourseGradeCombobox->setItemText(6, QCoreApplication::translate("MainWindow", "C", nullptr));
        updateCourseGradeCombobox->setItemText(7, QCoreApplication::translate("MainWindow", "F", nullptr));

        gradeRegistrationButton->setText(QCoreApplication::translate("MainWindow", "\354\204\261\354\240\201 \353\223\261\353\241\235 \353\260\217 \354\210\230\354\240\225", nullptr));
        gradeSearchButton->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210 \354\241\260\355\232\214", nullptr));
        updateMajorComboBox->setItemText(0, QString());
        updateMajorComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\354\273\264\355\223\250\355\204\260\352\263\265\355\225\231\352\263\274", nullptr));
        updateMajorComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\354\240\204\354\236\220\352\263\265\355\225\231\352\263\274", nullptr));
        updateMajorComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\352\270\260\352\263\204\352\263\265\355\225\231\352\263\274", nullptr));

        gradeMajor->setText(QCoreApplication::translate("MainWindow", "\354\240\204\352\263\265", nullptr));
        updateYear->setText(QCoreApplication::translate("MainWindow", " \355\225\231\353\205\204", nullptr));
        updateYearComboBox->setItemText(0, QString());
        updateYearComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        updateYearComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        updateYearComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        updateYearComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        updateYearComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        updateYearComboBox->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));

        QTableWidgetItem *___qtablewidgetitem14 = upgradeGradeTable->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\262\210", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = upgradeGradeTable->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\354\235\264\353\246\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = upgradeGradeTable->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "\355\225\231\353\205\204", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = upgradeGradeTable->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", " \354\240\204\352\263\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = upgradeGradeTable->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = upgradeGradeTable->horizontalHeaderItem(5);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\354\204\261\354\240\201", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\354\210\230\352\260\225 \352\263\274\353\252\251 \353\246\254\354\212\244\355\212\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(updateTab), QCoreApplication::translate("MainWindow", "\354\204\261\354\240\201 \353\223\261\353\241\235 \353\260\217 \354\210\230\354\240\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
