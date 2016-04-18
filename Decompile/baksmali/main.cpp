//
// Created by F8LEFT on 2016/4/17.
//

#include "baksmali/bakSmali.h"

#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
    bakSmali bs;
    bs.parseFromFile("F:\\CodeSrc\\FDA\\FDA\\res\\classes.dex");
    list<string> rel;
    auto && aClass = bs.getClassDef(0);
    aClass->decompile(rel);
    for (auto item : rel) {
        cout << item << endl;
    }
    return 0;
}

