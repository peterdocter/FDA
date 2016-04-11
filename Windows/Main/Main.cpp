//
// Created by F8LEFT on 2016/4/1.
//

#include "Main.h"

Main::Main(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Main) {
    ui->setupUi(this);

    connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(MenuQuit()));
}

Main::~Main() {
    delete ui;
}

void Main::MenuQuit() {
    this->close();
}