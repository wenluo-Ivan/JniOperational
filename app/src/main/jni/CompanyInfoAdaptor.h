//
// Created by liwl on 2019/12/5.
//
#include <jni.h>
#include "AdaptorTemplate.h"
#include "CompanyInfo.h"
#include "JNI_Object.h"

def_jni_adaptor_class(CompanyInfo){
public:
    CompanyInfoAdaptor(JNIEnv *pEnv, const CompanyInfo &param);
    CompanyInfoAdaptor(JNIEnv *pEnv, const jobject &param);
    ~CompanyInfoAdaptor(){};

    void init(JNIEnv * pEnv);
    def_j_static_field(companyId);
    def_j_static_field(companyName);
    def_j_static_field(companyAddress);
    def_j_static_field(companyUserSize);
    def_j_static_field(companyUserInfos);
};

