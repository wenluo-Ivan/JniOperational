//
// Created by liwl on 2019/12/5.
//

#ifndef JNIAPPLICATION_COMPANYUSERINFO_H
#define JNIAPPLICATION_COMPANYUSERINFO_H

#endif //JNIAPPLICATION_COMPANYUSERINFO_H

class CompanyUserInfo {
public:
    CompanyUserInfo();
    virtual ~CompanyUserInfo();

public:
 long userId;
 std::string userName;
 std::string userPhone;
 int userLever;
};