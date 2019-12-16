//
// Created by liwl on 2019/12/5.
//
#include "JNI_Object.h"
#include "CompanyInfoAdaptor.h"
#include "logutil.h"

jfieldID get_j_static_field(CompanyInfoAdaptor, companyId) = 0;
jfieldID get_j_static_field(CompanyInfoAdaptor, companyName) = 0;
jfieldID get_j_static_field(CompanyInfoAdaptor, companyAddress) = 0;
jfieldID get_j_static_field(CompanyInfoAdaptor, companyUserSize) = 0;
jfieldID get_j_static_field(CompanyInfoAdaptor, companyUserInfos) = 0;

CompanyInfoAdaptor::CompanyInfoAdaptor(JNIEnv *pEnv, const jobject &param) {
    init(pEnv);
    get_field_long(pEnv, param, get_j_field(companyId), cObj.companyId);
    get_field_string(pEnv,param,get_j_field(companyName),cObj.companyName);
    get_field_string(pEnv,param,get_j_field(companyAddress),cObj.companyAddress);
    get_field_long(pEnv,param,get_j_field(companyUserSize),cObj.companyUserSize);
}

CompanyInfoAdaptor::CompanyInfoAdaptor(JNIEnv *pEnv, const CompanyInfo &param) {
    init(pEnv);
    set_field_long(pEnv, jObj, get_j_field(companyId), param.companyId);
}

void CompanyInfoAdaptor::init(JNIEnv *pEnv) {
    if (_j_class_Adaptor == 0) {
        _j_class_Adaptor = (jclass) pEnv->NewGlobalRef(
                pEnv->FindClass("com/distance/third/jniapplication/beans/CompanyInfo"));
        initMethod(pEnv);
        get_j_field(companyId) = pEnv->GetFieldID(_j_class_Adaptor, "companyId", "J");
        get_j_field(companyName) = pEnv->GetFieldID(_j_class_Adaptor, "companyName",
                                                    "Ljava/lang/String;");
        get_j_field(companyAddress) = pEnv->GetFieldID(_j_class_Adaptor, "companyAddress",
                                                       "Ljava/lang/String;");
        get_j_field(companyUserSize) = pEnv->GetFieldID(_j_class_Adaptor, "companyUserSize", "J");
        get_j_field(companyUserInfos) = pEnv->GetFieldID(_j_class_Adaptor, "companyUserInfos",
                                                         "[Lcom/distance/third/jniapplication/beans/CompanyUserInfo;");
    }
}

