//
// Created by F8LEFT on 2016/4/6.
//

#ifndef FDA_ACCESSFLAGS_H
#define FDA_ACCESSFLAGS_H

#include <vm/Common.h>
#include <string>
using namespace std;

#define NUM_FLAGS   18
bool getAccessFlagClass(u4 flags, string &rel);
bool getAccessFlagMethod(u4 flags, string &rel);
bool getAccessFlagField(u4 flags, string &rel);
bool getAccessFlag(u4 flags, string &rel, const char *kAccessStrings[NUM_FLAGS] = NULL);

#endif //FDA_ACCESSFLAGS_H
