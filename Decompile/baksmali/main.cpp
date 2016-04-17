//
// Created by F8LEFT on 2016/4/17.
//

#include "baksmali/bakSmali.h"

#include <vector>
using namespace std;
int main(int argc, char *argv[]) {
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
    return 0;
}

