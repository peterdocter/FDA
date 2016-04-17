#include "Main/Main.h"
#include <QApplication>

int txtBakSmali();

#include <atomic>

int main(int argc, char *argv[]) {
//    process("F:\\CodeSrc\\FDA\\FDA\\res\\classes.dex");
    QApplication a(argc, argv);
    Main w;
    w.show();
    return a.exec();
}

#include "baksmali/baksmali.h"
#include <iostream>
using namespace std;
int txtBakSmali() {
    bakSmali bs;
    bs.parseFromFile("F:\\CodeSrc\\FDA\\FDA\\res\\classes.dex");
    vector<string> rel;
    bakClass *aClass = bs.getClassDef(0);
    aClass->decompile(rel);
    for (vector<string>::iterator itea = rel.begin();
         itea != rel.end(); itea++) {
        cout << *itea << endl;
    }
    delete aClass;
}