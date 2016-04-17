//
// Created by F8LEFT on 2016/4/1.
//

#ifndef FDA_LOG_H
#define FDA_LOG_H

// 补充一些Android的定义
#ifdef __ANDROID__
#include <android/log.h>
#define FLOG_TAG "F8LEFT"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, FLOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, FLOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, FLOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, FLOG_TAG, __VA_ARGS__)
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, FLOG_TAG, __VA_ARGS__)
#else
#define LOGE printf
#define LOGD printf
#define LOGW printf
#define LOGI printf
#define LOGV printf
#endif

#define ALOGE LOGE
#define ALOGV LOGV
#define ALOGW LOGW
#define ALOGD LOGD
#define ALOGI LOGI

#define TEMP_FAILURE_RETRY

#ifndef PAGE_SIZE
#define PAGE_SIZE 4096
#endif
#ifndef PAGESIZE
#define PAGESIZE PAGE_SIZE
#endif
#define PAGE_MASK (~(PAGE_SIZE) - 1)

#define PAGE_START(x)  ((x) & PAGE_MASK)
#define PAGE_OFFSET(x) ((x) & ~PAGE_MASK)
#define PAGE_END(x)    PAGE_START((x) + (PAGE_SIZE-1))

bool safe_mul(unsigned *, unsigned a, unsigned b);
bool safe_add(unsigned *, unsigned a, unsigned b);


#endif //FDA_LOG_H
