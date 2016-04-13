/********************************************************************************
** Form generated from reading UI file 'Main.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_H
#define UI_MAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Main
{
public:
    QAction *menuOpen;
    QAction *menuSave;
    QAction *menuSave_as;
    QAction *menuQuit;
    QAction *menuAbout;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QListView *listView;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Main)
    {
        if (Main->objectName().isEmpty())
            Main->setObjectName(QStringLiteral("Main"));
        Main->setEnabled(true);
        Main->resize(709, 551);
        menuOpen = new QAction(Main);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuSave = new QAction(Main);
        menuSave->setObjectName(QStringLiteral("menuSave"));
        menuSave_as = new QAction(Main);
        menuSave_as->setObjectName(QStringLiteral("menuSave_as"));
        menuQuit = new QAction(Main);
        menuQuit->setObjectName(QStringLiteral("menuQuit"));
        menuAbout = new QAction(Main);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        centralWidget = new QWidget(Main);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(3);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(listView);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(7);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);


        horizontalLayout->addLayout(horizontalLayout_2);

        Main->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Main);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        Main->setMenuBar(menuBar);
        toolBar = new QToolBar(Main);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Main->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menu->addAction(menuOpen);
        menu->addAction(menuSave);
        menu->addAction(menuSave_as);
        menu->addAction(menuQuit);
        menuHelp->addAction(menuAbout);

        retranslateUi(Main);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Main);
    } // setupUi

    void retranslateUi(QMainWindow *Main)
    {
        Main->setWindowTitle(QApplication::translate("Main", "FDA --- F8's Dex Analyszer", 0));
        menuOpen->setText(QApplication::translate("Main", "Open(dex,apk,odex)", 0));
#ifndef QT_NO_TOOLTIP
        menuOpen->setToolTip(QApplication::translate("Main", "Open(dex,apk,odex)", 0));
#endif // QT_NO_TOOLTIP
        menuSave->setText(QApplication::translate("Main", "Save", 0));
#ifndef QT_NO_TOOLTIP
        menuSave->setToolTip(QApplication::translate("Main", "Save", 0));
#endif // QT_NO_TOOLTIP
        menuSave_as->setText(QApplication::translate("Main", "Save as", 0));
#ifndef QT_NO_TOOLTIP
        menuSave_as->setToolTip(QApplication::translate("Main", "Save as", 0));
#endif // QT_NO_TOOLTIP
        menuQuit->setText(QApplication::translate("Main", "Quit", 0));
#ifndef QT_NO_TOOLTIP
        menuQuit->setToolTip(QApplication::translate("Main", "Quit", 0));
#endif // QT_NO_TOOLTIP
        menuAbout->setText(QApplication::translate("Main", "About FDA", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Main", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Main", "Tab 2", 0));
        menu->setTitle(QApplication::translate("Main", "File", 0));
        menuHelp->setTitle(QApplication::translate("Main", "Help", 0));
        toolBar->setWindowTitle(QApplication::translate("Main", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class Main: public Ui_Main {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_H
