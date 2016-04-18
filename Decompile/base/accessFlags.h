//
// Created by F8LEFT on 2016/4/6.
//

#ifndef FDA_ACCESSFLAGS_H
#define FDA_ACCESSFLAGS_H

#include <vm/Common.h>
#include <string>
using namespace std;

#define NUM_FLAGS   18

string getAccessFlagClass(u4 flags);

string getAccessFlagMethod(u4 flags);

string getAccessFlagField(u4 flags);

string getAccessFlag(u4 flags, const char *kAccessStrings[18]);

#endif //FDA_ACCESSFLAGS_H
