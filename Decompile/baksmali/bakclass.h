//
// Created by F8LEFT on 2016/4/8.
//

#ifndef FDA_BAKCLASS_H
#define FDA_BAKCLASS_H


#include <vm/Dalvik.h>

#include <string>
#include <libdex/DexClass.h>
#include <base/accessFlags.h>
#include "bakMethod.h"
#include "bakField.h"

using namespace std;

class bakClass {
private:
    const DexClassDef *pClassDef;
    const DexFile *pDexFile;
    const DexClassData* pClassData;
public:
    bakClass(const DexClassDef *indef, const DexFile *index);
    ~bakClass();

    const char *getName() { return dexStringByTypeIdx(pDexFile, pClassDef->classIdx); }
    const char *getSuperClassName() { return dexStringByTypeIdx(pDexFile, pClassDef->superclassIdx); }
    const char* getSourceFileName() { return dexStringById(pDexFile, pClassDef->sourceFileIdx); }

    u4 getFlag() { return pClassDef->accessFlags; }
    bool getFlag(string &des) { return getAccessFlagClass(getFlag(), des); }

    const DexClassDef *getClassDef() { return pClassDef; }
    const DexClassData* getClassData() { return pClassData; }
    int getStaticFieldSize() { return pClassData != NULL ? pClassData->header.staticFieldsSize : 0; }
    int getInstanceFieldSize() { return pClassData != NULL ? pClassData->header.instanceFieldsSize : 0; }
    int getDirectMethodSize() { return pClassData != NULL ? pClassData->header.directMethodsSize : 0; }
    int getVirtualMethodSize() { return pClassData != NULL ? pClassData->header.virtualMethodsSize : 0; }

    // INFO 下面的返回值需要进行delete释放内存
    bakField *getStaticField(int idx);
    bakField *getInstanceField(int idx);

    bakMethod *getDirectMethod(int idx);
    bakMethod* getVirtualMethod(int idx);

    void decompile(vector<string> &decs);
};


#endif //FDA_BAKCLASS_H
