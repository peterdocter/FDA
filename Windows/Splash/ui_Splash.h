/********************************************************************************
** Form generated from reading UI file 'Splash.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SPLASH_H
#define SPLASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Splash
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Splash)
    {
        if (Splash->objectName().isEmpty())
            Splash->setObjectName(QStringLiteral("Splash"));
        Splash->resize(400, 300);
        centralWidget = new QWidget(Splash);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Splash->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Splash);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        Splash->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Splash);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Splash->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Splash);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Splash->setStatusBar(statusBar);

        retranslateUi(Splash);

        QMetaObject::connectSlotsByName(Splash);
    } // setupUi

    void retranslateUi(QMainWindow *Splash)
    {
        Splash->setWindowTitle(QApplication::translate("Splash", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class Splash: public Ui_Splash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SPLASH_H
