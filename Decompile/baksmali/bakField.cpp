//
// Created by F8LEFT on 2016/4/9.
//

#include "bakField.h"

bakField::bakField(const DexField *infield, const DexFile *index) {
    assert(infield != NULL);assert(index != NULL);
    pDexField = infield;
    pDexFile = index;
    pDexFieldId = dexGetFieldId(pDexFile, pDexField->fieldIdx);
}

void bakField::decompile(vector<string> &decs) {
    string tmp;
    getFlag(tmp);
    decs.push_back(".field " + tmp  + getName() + ':' + getType());
}





