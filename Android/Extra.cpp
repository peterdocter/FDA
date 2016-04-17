//
// Created by F8LEFT on 2016/4/5.
//
#include <stddef.h>
#include "Extra.h"

bool safe_mul(unsigned * rel, unsigned a, unsigned b) {
    if (rel != NULL) {
        *rel = a * b;
    }
    return true;
}
bool safe_add(unsigned * rel, unsigned a, unsigned b) {
    if (rel != NULL) {
        *rel = a + b;
    }
    return true;
}
