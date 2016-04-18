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
        pClassData.reset(dexReadAndVerifyClassData(&pData, NULL));
    };
}

bakClass::~bakClass() {
}

shared_ptr<bakMethod> bakClass::getDirectMethod(int idx) {
    if (idx >= getDirectMethodSize()) {
        return move(shared_ptr<bakMethod>(NULL));
    }
    shared_ptr<bakMethod> method(new bakMethod(&pClassData->directMethods[idx], pDexFile));
    return move(method);
}

shared_ptr<bakMethod> bakClass::getVirtualMethod(int idx) {
    if (idx >= getVirtualMethodSize()) {
        return move(shared_ptr<bakMethod>(NULL));
    }
    shared_ptr<bakMethod> method(new bakMethod(&pClassData->virtualMethods[idx], pDexFile));
    return move(method);
}

shared_ptr<bakField> bakClass::getStaticField(int idx) {
    if (idx >= getStaticFieldSize()) {
        return move(shared_ptr<bakField>(NULL));
    }
    shared_ptr<bakField> field(new bakField(&pClassData->staticFields[idx], pDexFile));
    return move(field);
}

shared_ptr<bakField> bakClass::getInstanceField(int idx) {
    if (idx >= getInstanceFieldSize()) {
        return move(shared_ptr<bakField>(NULL));
    }
    shared_ptr<bakField> field(new bakField(&pClassData->instanceFields[idx], pDexFile));
    return move(field);
}

void bakClass::decompile(list<string> &decs) {
    string tmp;

    // .class flag name
    decs.push_back(".class " + getFlagStr() + getName());
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
            auto &&field = getStaticField(i);
            field->decompile(decs);
        }
        size = getInstanceFieldSize();
        for (i = 0; i < size; i++) {
            auto && field = getInstanceField(i);
            field->decompile(decs);
        }
        // methods
        size = getDirectMethodSize();
        for (i = 0; i < size; i++) {
            auto &&method = getDirectMethod(i);
            method->decompile(decs);
        }
        size = getVirtualMethodSize();
        for (i = 0; i < size; i++) {
            auto &&method = getVirtualMethod(i);
            method->decompile(decs);
        }
    }
}












