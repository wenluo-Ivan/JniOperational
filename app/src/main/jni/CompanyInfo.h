//
// Created by liwl on 2019/12/5.
//

#include "CompanyUserInfo.h"

#ifndef JNIAPPLICATION_COMPANYINFO_H
#define JNIAPPLICATION_COMPANYINFO_H

#endif //JNIAPPLICATION_COMPANYINFO_H

class CompanyInfo {
public:
    CompanyInfo() {};

    virtual ~CompanyInfo() {};

public:
    long companyId;
    std::string companyName;
    std::string companyAddress;
    long companyUserSize;
    std::vector<CompanyUserInfo> companyUserInfos;
};
