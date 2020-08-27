/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTesting;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_Main;
    QTextEdit *console_main;
    QWidget *tab_Debug;
    QTextEdit *console_debug;
    QWidget *tab_sonfloro;
    QTextEdit *console_sonfloro;
    QWidget *tab_zoey;
    QTextEdit *console_zoey;
    QWidget *tab_lumiriss;
    QTextEdit *console_lumiriss;
    QWidget *tab_whatthehellshappened;
    QTextEdit *console_whatthehellshappened;
    QWidget *tab_armorysons;
    QTextEdit *console_armorysons;
    QWidget *tab_realmcopier;
    QTextEdit *console_realmcopier;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *chatLineEdit;
    QPushButton *chatButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(960, 458);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../.designer/backup/res/img/chadThink.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionTesting = new QAction(MainWindow);
        actionTesting->setObjectName(QString::fromUtf8("actionTesting"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("QWidget#centralWidget {background:#252525}\n"
"QTextEdit {\n"
"background:#353535;\n"
"color:white;\n"
"margin:-1px\n"
"}\n"
"\n"
"QTabWidget::pane{background:#353535}\n"
"\n"
"QTabBar::tab{\n"
"background:#252525;\n"
"padding:8;\n"
"min-width:9ex;\n"
"color:white;\n"
"text-align: center;\n"
"\n"
"}\n"
"QTabBar::tab:selected {\n"
"background:#353535;\n"
"}\n"
"QPushButton {\n"
"background:#353535;\n"
"color:white;\n"
"}\n"
"QPushButton:!enabled {\n"
"color:grey;\n"
"}\n"
"QLineEdit {\n"
"background:#353535;\n"
"color:white;\n"
"border:#424242;\n"
"}\n"
""));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 921, 381));
        QPalette palette;
        tabWidget->setPalette(palette);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab_Main = new QWidget();
        tab_Main->setObjectName(QString::fromUtf8("tab_Main"));
        console_main = new QTextEdit(tab_Main);
        console_main->setObjectName(QString::fromUtf8("console_main"));
        console_main->setGeometry(QRect(0, 0, 921, 354));
        console_main->setReadOnly(true);
        tabWidget->addTab(tab_Main, QString());
        tab_Debug = new QWidget();
        tab_Debug->setObjectName(QString::fromUtf8("tab_Debug"));
        console_debug = new QTextEdit(tab_Debug);
        console_debug->setObjectName(QString::fromUtf8("console_debug"));
        console_debug->setGeometry(QRect(0, 0, 921, 354));
        console_debug->setReadOnly(true);
        tabWidget->addTab(tab_Debug, QString());
        tab_sonfloro = new QWidget();
        tab_sonfloro->setObjectName(QString::fromUtf8("tab_sonfloro"));
        console_sonfloro = new QTextEdit(tab_sonfloro);
        console_sonfloro->setObjectName(QString::fromUtf8("console_sonfloro"));
        console_sonfloro->setEnabled(true);
        console_sonfloro->setGeometry(QRect(0, 0, 921, 354));
        QPalette palette1;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(53, 53, 53, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        console_sonfloro->setPalette(palette1);
        console_sonfloro->setReadOnly(true);
        tabWidget->addTab(tab_sonfloro, QString());
        tab_zoey = new QWidget();
        tab_zoey->setObjectName(QString::fromUtf8("tab_zoey"));
        console_zoey = new QTextEdit(tab_zoey);
        console_zoey->setObjectName(QString::fromUtf8("console_zoey"));
        console_zoey->setGeometry(QRect(0, 0, 921, 354));
        console_zoey->setReadOnly(true);
        tabWidget->addTab(tab_zoey, QString());
        tab_lumiriss = new QWidget();
        tab_lumiriss->setObjectName(QString::fromUtf8("tab_lumiriss"));
        console_lumiriss = new QTextEdit(tab_lumiriss);
        console_lumiriss->setObjectName(QString::fromUtf8("console_lumiriss"));
        console_lumiriss->setGeometry(QRect(0, 0, 921, 354));
        console_lumiriss->setLineWidth(1);
        console_lumiriss->setReadOnly(true);
        tabWidget->addTab(tab_lumiriss, QString());
        tab_whatthehellshappened = new QWidget();
        tab_whatthehellshappened->setObjectName(QString::fromUtf8("tab_whatthehellshappened"));
        console_whatthehellshappened = new QTextEdit(tab_whatthehellshappened);
        console_whatthehellshappened->setObjectName(QString::fromUtf8("console_whatthehellshappened"));
        console_whatthehellshappened->setGeometry(QRect(0, 0, 921, 354));
        console_whatthehellshappened->setReadOnly(true);
        tabWidget->addTab(tab_whatthehellshappened, QString());
        tab_armorysons = new QWidget();
        tab_armorysons->setObjectName(QString::fromUtf8("tab_armorysons"));
        console_armorysons = new QTextEdit(tab_armorysons);
        console_armorysons->setObjectName(QString::fromUtf8("console_armorysons"));
        console_armorysons->setGeometry(QRect(0, 0, 921, 354));
        console_armorysons->setReadOnly(true);
        tabWidget->addTab(tab_armorysons, QString());
        tab_realmcopier = new QWidget();
        tab_realmcopier->setObjectName(QString::fromUtf8("tab_realmcopier"));
        console_realmcopier = new QTextEdit(tab_realmcopier);
        console_realmcopier->setObjectName(QString::fromUtf8("console_realmcopier"));
        console_realmcopier->setGeometry(QRect(0, 0, 921, 354));
        console_realmcopier->setReadOnly(true);
        tabWidget->addTab(tab_realmcopier, QString());
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 400, 681, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        chatLineEdit = new QLineEdit(layoutWidget);
        chatLineEdit->setObjectName(QString::fromUtf8("chatLineEdit"));
        chatLineEdit->setEnabled(false);

        horizontalLayout->addWidget(chatLineEdit);

        chatButton = new QPushButton(layoutWidget);
        chatButton->setObjectName(QString::fromUtf8("chatButton"));
        chatButton->setEnabled(false);

        horizontalLayout->addWidget(chatButton);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GayfloroGUI", nullptr));
        actionTesting->setText(QApplication::translate("MainWindow", "Testing", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Main), QApplication::translate("MainWindow", "Main", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_Debug), QApplication::translate("MainWindow", "Debug", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_sonfloro), QApplication::translate("MainWindow", "#sonfloro", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_zoey), QApplication::translate("MainWindow", "#iTzMissZoey", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_lumiriss), QApplication::translate("MainWindow", "#lumiriss", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_whatthehellshappened), QApplication::translate("MainWindow", "#whatthehellshappened", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_armorysons), QApplication::translate("MainWindow", "#armorysons", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_realmcopier), QApplication::translate("MainWindow", "#realmcopier", nullptr));
        chatButton->setText(QApplication::translate("MainWindow", "Chat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
