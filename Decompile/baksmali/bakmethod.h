//
// Created by F8LEFT on 2016/4/8.
//

#ifndef FDA_BAKMETHOD_H
#define FDA_BAKMETHOD_H


#include <libdex/DexClass.h>

#include <string>
#include <libdex/InstrUtils.h>

#include <iostream>
#include <sstream>

#include <base/accessFlags.h>
#include <list>
#include <memory>
using namespace std;

class bakMethod {
private:
    const DexMethod* pDexMethd;
    const DexMethodId* pDexMethodId;
    const DexFile *pDexFile;

    const DexCode *pCode;
public:
    bakMethod(const DexMethod *inmethod, const DexFile *index);

    const DexMethod* getMethod() { return pDexMethd; }
    const DexMethodId* getMethodId() { return pDexMethodId; }

    const char *getName() { return dexStringById(pDexFile, pDexMethodId->nameIdx); }

    string getProto();
    int getClassId() { return pDexMethodId->classIdx; }

    u4 getFlag() { return pDexMethd->accessFlags; }

    string getFlagStr() { return move(getAccessFlagMethod(getFlag())); }


    u4 getInsSize() { return pCode ? pCode->insnsSize : 0; }
    u4 getTriesSize() { return pCode ? pCode->triesSize : 0; }
    bool decompileIns(u4 insnIdx, string &rel, u4 &insWidth);
    bool decompileTries(u4 insnIdx, string &exception, u4 &start, u4 &end, u4 &addr);

    void decompile(list<string> &decs);

private:
    void getInsString(string &exception, const DecodedInstruction *pDecInsn);
};


#endif //FDA_BAKMETHOD_H
