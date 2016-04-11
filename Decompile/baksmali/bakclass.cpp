//
// Created by F8LEFT on 2016/4/8.
//

#include "bakClass.h"

bakClass::bakClass(const DexClassDef *indef, const DexFile *index) {
    assert(indef != NULL); assert(index != NULL);
    pClassDef = indef;
    pDexFile = index;

    if (pClassDef->classDataOff) {
        const u1 *pData = dexGetClassData(pDexFile, pClassDef);
        pClassData = dexReadAndVerifyClassData(&pData, NULL);
    } else pClassData = NULL;
}

bakClass::~bakClass() {
    if (pClassData) {
        free((void*)pClassData);
    }
}

bakMethod *bakClass::getDirectMethod(int idx) {
    if (idx >= getDirectMethodSize()) {
        return NULL;
    }
    bakMethod *method = new bakMethod(&pClassData->directMethods[idx], pDexFile);
    return method;
}

bakMethod *bakClass::getVirtualMethod(int idx) {
    if (idx >= getVirtualMethodSize()) {
        return NULL;
    }
    bakMethod *method = new bakMethod(&pClassData->virtualMethods[idx], pDexFile);
    return method;
}

bakField *bakClass::getStaticField(int idx) {
    if (idx >= getStaticFieldSize()) {
        return NULL;
    }
    bakField *field = new bakField(&pClassData->staticFields[idx], pDexFile);
    return field;
}

bakField *bakClass::getInstanceField(int idx) {
    if (idx >= getInstanceFieldSize()) {
        return NULL;
    }
    bakField *field = new bakField(&pClassData->instanceFields[idx], pDexFile);
    return field;
}

void bakClass::decompile(vector<string> &decs) {
    string tmp;
    string tmp2;

    getFlag(tmp);
    // .class flag name
    decs.push_back(".class " + tmp + getName());
    // .super className
    tmp = ".super ";
    decs.push_back(tmp + getSuperClassName());

    // .source file (if exist)
    tmp = ".source ";
    decs.push_back(tmp + getSourceFileName());

    if (pClassData) {
        u4 i, size;
        // fields
        size = getStaticFieldSize();
        for (i = 0; i < size; i++) {
            bakField *field = getStaticField(i);
            field->decompile(decs);
            delete field;
        }
        size = getInstanceFieldSize();
        for (i = 0; i < size; i++) {
            bakField *field = getInstanceField(i);
            field->decompile(decs);
            delete field;
        }
        // methods
        size = getDirectMethodSize();
        for (i = 0; i < size; i++) {
            bakMethod *method = getDirectMethod(i);
            method->decompile(decs);
            delete method;
        }
        size = getVirtualMethodSize();
        for (i = 0; i < size; i++) {
            bakMethod *method = getVirtualMethod(i);
            method->decompile(decs);
            delete method;
        }
    }
}












