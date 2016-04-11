//
// Created by F8LEFT on 2016/4/6.
//

#include "accessFlags.h"


/*
 * Flag for use with createAccessFlagStr().
 */
enum AccessFor {
    kAccessForClass = 0, kAccessForMethod = 1, kAccessForField = 2,
    kAccessForMAX
};

bool getAccessFlagClass(u4 flags, string &rel) {
    static const char *allFlags[NUM_FLAGS] = {
            "public",           /* 0x0001 -*/
            "private",          /* 0x0002 -*/
            "protected",        /* 0x0004 -*/
            "static",           /* 0x0008 -*/
            "final",            /* 0x0010 -*/
            "?",                /* 0x0020 */
            "?",                /* 0x0040 */
            "?",                /* 0x0080 */
            "?",                /* 0x0100 */
            "interface",        /* 0x0200 -*/
            "abstract",         /* 0x0400 -*/
            "?",                /* 0x0800 */
            "synthetic",        /* 0x1000 -*/
            "annotation",       /* 0x2000 -*/
            "enum",             /* 0x4000 -*/
            "?",                /* 0x8000 */
            "verified",         /* 0x10000 */
            "optimized",        /* 0x20000 */
    };
    return getAccessFlag(flags, rel, allFlags);
}

bool getAccessFlagMethod(u4 flags, string &rel) {
    static const char *allFlags[NUM_FLAGS] = {
            "public",           /* 0x0001 -*/
            "private",          /* 0x0002 -*/
            "protected",        /* 0x0004 -*/
            "static",           /* 0x0008 -*/
            "final",            /* 0x0010 -*/
            "synchronized",     /* 0x0020 -*/
            "bridge",           /* 0x0040 -*/
            "varargs",          /* 0x0080 -*/
            "native",           /* 0x0100 -*/
            "?",                /* 0x0200 */
            "abstract",         /* 0x0400 -*/
            "strict",           /* 0x0800 -*/
            "synthetic",        /* 0x1000 -*/
            "?",                /* 0x2000 */
            "?",                /* 0x4000 */
            "miranda",          /* 0x8000 */
            "constructor",      /* 0x10000 -*/
            "declared_synchronized", /* 0x20000 -*/
    };
    return getAccessFlag(flags, rel, allFlags);
}

bool getAccessFlagField(u4 flags, string &rel) {
    static const char *allFlags[NUM_FLAGS] = {
            "public",           /* 0x0001 -*/
            "private",          /* 0x0002 -*/
            "protected",        /* 0x0004 -*/
            "static",           /* 0x0008 -*/
            "final",            /* 0x0010 -*/
            "?",                /* 0x0020 */
            "volatile",         /* 0x0040 -*/
            "transient",        /* 0x0080 -*/
            "?",                /* 0x0100 */
            "?",                /* 0x0200 */
            "?",                /* 0x0400 */
            "?",                /* 0x0800 */
            "synthetic",        /* 0x1000 -*/
            "?",                /* 0x2000 */
            "enum",             /* 0x4000 -*/
            "?",                /* 0x8000 */
            "?",                /* 0x10000 */
            "?",                /* 0x20000 */
    };
    return getAccessFlag(flags, rel, allFlags);
}

bool getAccessFlag(u4 flags, string &rel, const char *kAccessStrings[NUM_FLAGS]) {
    bool result = true;
    static const char *allFlags[NUM_FLAGS] = {
            "public",           /* 0x0001 */
            "private",          /* 0x0002 */
            "protected",        /* 0x0004 */
            "static",           /* 0x0008 */
            "final",            /* 0x0010 */
            "synchronized",     /* 0x0020 */
            "bridge",           /* 0x0040 */
            "varargs",          /* 0x0080 */
            "native",           /* 0x0100 */
            "interface",        /* 0x0200 */
            "abstract",         /* 0x0400 */
            "strict",           /* 0x0800 */
            "synthetic",        /* 0x1000 */
            "annotation",       /* 0x2000 */
            "enum",             /* 0x4000 */
            "miranda",          /* 0x8000 */
            "constructor",      /* 0x10000 */
            "declared_synchronized", /* 0x20000 */
    };
    const char **acceptFlags = kAccessStrings;
    if (acceptFlags == NULL) {
        LOGE("accessFlags:Error:no kAccessStrings Data");
        acceptFlags = allFlags;
    }
    rel.clear();
    for (int i = 0; i < NUM_FLAGS; ++i) {
        if (flags & 0x01) {
            if (*acceptFlags[i] == '?') result = false;
            rel = rel + acceptFlags[i] + " ";
        }
        flags >>= 1;
    }
    if (flags) result = false;
    return result;
}