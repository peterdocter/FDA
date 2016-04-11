//
// Created by F8LEFT on 2016/4/1.
//

#ifndef FDA_SPLASH_H
#define FDA_SPLASH_H

#include <QMainWindow>
#include "ui_Main.h"

namespace Ui {
    class Main;
}

// 暂时保留，假如日后启动速度慢了就启用SplashWindow
class Main : public QMainWindow {
    Q_OBJECT
public:
    explicit Main(QWidget *parent = 0);
    ~Main();

private slots:
    void MenuQuit();
private:
    Ui::Main *ui;
};

#endif //FDA_SPLASH_H
