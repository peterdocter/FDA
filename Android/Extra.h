//
// Created by F8LEFT on 2016/4/1.
//

#ifndef FDA_LOG_H
#define FDA_LOG_H

// 补充一些Android的定义
#ifdef __ANDROID__
#include <android/log.h>
#define LOG_TAG "F8LEFT"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
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


bool safe_mul(unsigned *, unsigned a, unsigned b);
bool safe_add(unsigned *, unsigned a, unsigned b);

#endif //FDA_LOG_H
