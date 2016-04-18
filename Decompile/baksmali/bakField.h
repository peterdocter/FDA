//
// Created by F8LEFT on 2016/4/9.
//

#ifndef FDA_BAKFIELD_H
#define FDA_BAKFIELD_H


#include <libdex/DexFile.h>
#include <string>
#include <libdex/DexClass.h>
#include <base/accessFlags.h>
#include <list>
using namespace std;

class bakField {
    const DexFile *pDexFile;
    const DexField *pDexField;
    const DexFieldId *pDexFieldId;

public:
    bakField(const DexField *infield, const DexFile *index);
    const DexField* getField() { return pDexField; }
    const DexFieldId* getFieldId() { return pDexFieldId; }
    const char* getName() { return dexStringById(pDexFile, pDexFieldId->nameIdx); }
    const char* getType() { return dexStringByTypeIdx(pDexFile, pDexFieldId->typeIdx); }
    int getClassId() { return pDexFieldId->classIdx; }

    u4 getFlag() { return pDexField->accessFlags; }

    string getFlagStr() { return move(getAccessFlagField(getFlag())); }

    void decompile(list<string> &decs);
};


#endif //FDA_BAKFIELD_H
