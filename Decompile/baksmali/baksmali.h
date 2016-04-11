//
// Created by F8LEFT on 2016/4/5.
//

#ifndef FDA_BAKSMALI_H
#define FDA_BAKSMALI_H

//#include <libdex/DexFile.h>
#include <libdex/DexClass.h>
#include <libdex/InstrUtils.h>
#include "libdex/DexFile.h"
#include "bakClass.h"

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


class bakSmali {
private:
    struct {
        bool asSmali;       //保持smali语法兼容
        bool deodex;        // not use
        bool forceDeodex;   //强制修复Odex语句
    } option;
public:
    bakSmali();
    ~bakSmali();

    void setOption(bool deodex);
    bool parseFromFile(const char *fileName);
    bool parseFromDexFile(const DexFile *file);
public:
    const DexHeader *getHeader() {
        assert(pDexFile != NULL);
        return pDexFile->pHeader;
    }

    int getClassDefSize() { return pDexFile->pHeader->classDefsSize; }
    // INFO :下面的返回值需要进行delete释放内存
    bakClass* getClassDef(int idx);

private:
    MemMapping map;
    bool mapped;

    DexFile *pDexFile;

};


#endif //FDA_BAKSMALI_H
