//
// Created by F8LEFT on 2016/4/5.
//
#include "bakSmali.h"

#include <libdex/CmdUtils.h>
#include <c++/cstring>
#include <base/accessFlags.h>
#include <libdex/DexClass.h>
#include <vm/Dalvik.h>
#include <libdex/DexOpcodes.h>
#include <libdex/InstrUtils.h>
#include <libdex/DexCatch.h>

void bakSmali::setOption(bool deodex) {
    option.deodex = deodex;
}

bakSmali::bakSmali() {
    option.asSmali = true;

    mapped = false;
    pDexFile = NULL;
}

bakSmali::~bakSmali() {
    if (mapped)
        sysReleaseShmem(&map);
    if (pDexFile != NULL)
        dexFileFree(pDexFile);
}

bool bakSmali::parseFromFile(const char *fileName) {
    assert(pDexFile == NULL); assert(mapped == false);

    bool result = false;
    if (dexOpenAndMap(fileName, NULL, &map, false) != 0) {
        return result;
    }

    pDexFile = dexFileParse((u1 *) map.addr, map.length, kDexParseContinueOnError);
    if (pDexFile == NULL) {
        LOGE("ERROR:bakSmali: DEX parse failed\n");
        goto bail;
    }
    result = true;
    bail:
    return result;
}

bool bakSmali::parseFromDexFile(const DexFile *file) {
    assert(pDexFile == NULL);
    pDexFile = new DexFile;
    memcpy(pDexFile, file, sizeof(DexFile));
    return true;
}

shared_ptr<bakClass> bakSmali::getClassDef(int idx) {
    if (idx >= getClassDefSize()) {
        return move(shared_ptr<bakClass>(NULL));
    }
    const DexClassDef *pClassDef = dexGetClassDef(pDexFile, idx);
    shared_ptr<bakClass>  newClass(new bakClass(pClassDef, pDexFile));
    return move(newClass);
}
