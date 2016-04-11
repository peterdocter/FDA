//
// Created by F8LEFT on 2016/4/1.
//

#ifndef FDA_SPLASH_H
#define FDA_SPLASH_H

#include <QMainWindow>
#include "ui_Splash.h"

namespace Ui {
    class Splash;
}

// 暂时保留，假如日后启动速度慢了就启用SplashWindow
class Splash : public QMainWindow {
    Q_OBJECT
public:
    explicit Splash(QWidget *parent = 0);
    ~Splash();

private:
    Ui::Splash *ui;
};

#endif //FDA_SPLASH_H
