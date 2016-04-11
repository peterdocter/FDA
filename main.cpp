#include "Windows/Main/Main.h"
#include <QApplication>
#include "baksmali/bakSmali.h"

#include "dexdump/DexDump.h"

int main(int argc, char *argv[]) {
//    process("F:\\CodeSrc\\FDA\\FDA\\res\\classes.dex");
    bakSmali bc;
    bc.parseFromFile("F:\\CodeSrc\\FDA\\FDA\\res\\classes.dex");
    bc.dumpClassDef(0);
//    QApplication a(argc, argv);
//    Main w;
//    w.show();
//    return a.exec();
}

