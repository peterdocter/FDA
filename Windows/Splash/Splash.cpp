//
// Created by F8LEFT on 2016/4/1.
//

#include "Splash.h"

Splash::Splash(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Splash) {
    ui->setupUi(this);

    setFixedSize(577,433); // 禁止改变窗口大小。
}

Splash::~Splash() {
    delete ui;
}