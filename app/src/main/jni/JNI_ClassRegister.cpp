//
// Created by liwl on 2019/12/5.
//
#include <jni.h>
#include "JNI_ClassRegister.h"
#include "JavaClassDefine.h"
#include "logutil.h"
#include "JNI_TransFunction.h"

extern "C" {
JavaVM *g_pJVM = NULL;
JNIEnv *g_pMainThreadEnv = NULL;
jint g_JNIVersion = 0;

#define REGISTERCLASSMETHODS(sig, method)   \
          JniRegisterNativeMethods(env,sig,method,sizeof(method)/sizeof(method[0]))
void RegisterClassesMethods(JNIEnv *env);

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *pEnv = NULL;
    //获取JNI版本
    if (vm->GetEnv((void **) &pEnv, JNI_VERSION_1_4) != JNI_OK) {
        LOGE("GetEnv failed!");
        return JNI_ERR;
    }
    LOGI("GetEnv success!");

    RegisterClassesMethods(pEnv);

    LOGI("JNI_OnLoad.");

    g_pJVM = vm;

    g_pMainThreadEnv = pEnv;

    g_JNIVersion = JNI_VERSION_1_4;

    LOGI("JNI_VERSION:%d.", g_JNIVersion);

    return JNI_VERSION_1_4;
}

int JniRegisterNativeMethods(JNIEnv *env, const char *className,
                             const JNINativeMethod *gMethods, int numMethods) {
    jclass clazz = env->FindClass(className);
    if (clazz == nullptr) {
        LOGE("Native registration unable to find class '%s'\n", className);
        return 0;
    }

    int result = 1;
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        LOGE("RegisterNatives failed for '%s'\n", className);
        result = 0;
    }

    env->DeleteLocalRef(clazz);
    return result;
}

JNIEXPORT void JNICALL ClassRegister_initJNI(JNIEnv *env, jobject obj);
JNIEXPORT void JNICALL ClassRegister_releaseJNIObject(JNIEnv *env, jobject obj, jobject jobj);

JNINativeMethod methods_ClassRegister[] =
        {
                {"initJNI",          "()V",                   (void *) ClassRegister_initJNI},
                {"releaseJNIObject", "(Ljava/lang/Object;)V", (void *) ClassRegister_releaseJNIObject}

        };

JNINativeMethod methods_TransFunction[] =
        {
                {"transferInt",             "(I)V",                                                         (void *) TransFunction_transferInt},
                {"transferLong",            "(J)V",                                                         (void *) TransFunction_transferLong},
                {"transferString",          "(Ljava/lang/String;)V",                                        (void *) TransFunction_transferString},
                {"transferBoolean",         "(Z)V",                                                         (void *) TransFunction_transferBoolean},
                {"transferIntArray",        "([I)V",                                                        (void *) TransFunction_transferIntArray},
                {"transferLongArray",       "([J)V",                                                        (void *) TransFunction_transferLongArray},
                {"transferStringArray",     "([Ljava/lang/String;)V",                                       (void *) TransFunction_transferStringArray},
                {"transferObject",          "(Lcom/distance/third/jniapplication/beans/CompanyUserInfo;)V", (void *) TransFunction_transferObject},
                {"transferCompositeObject", "(Lcom/distance/third/jniapplication/beans/CompanyInfo;)V",     (void *) TransFunction_transferCompositeObject}
        };

void RegisterClassesMethods(JNIEnv *env) {
    REGISTERCLASSMETHODS(JC_ClassRegister, methods_ClassRegister);
    REGISTERCLASSMETHODS(JC_TransFunction, methods_TransFunction);
}
}

JNIEXPORT void JNICALL ClassRegister_initJNI(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL ClassRegister_releaseJNIObject(JNIEnv *env, jobject obj, jobject jobj) {
}