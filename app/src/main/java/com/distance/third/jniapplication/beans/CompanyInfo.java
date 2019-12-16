package com.distance.third.jniapplication.beans;

public class CompanyInfo {
    private long companyId;
    private String companyName;
    private String companyAddress;
    private long companyUserSize;
    private CompanyUserInfo[] companyUserInfos;

    public long getCompanyId() {
        return companyId;
    }

    public void setCompanyId(long companyId) {
        this.companyId = companyId;
    }

    public String getCompanyName() {
        return companyName;
    }

    public void setCompanyName(String companyName) {
        this.companyName = companyName;
    }

    public String getCompanyAddress() {
        return companyAddress;
    }

    public void setCompanyAddress(String companyAddress) {
        this.companyAddress = companyAddress;
    }

    public long getCompanyUserSize() {
        return companyUserSize;
    }

    public void setCompanyUserSize(long companyUserSize) {
        this.companyUserSize = companyUserSize;
    }

    public CompanyUserInfo[] getCompanyUserInfos() {
        return companyUserInfos;
    }

    public void setCompanyUserInfos(CompanyUserInfo[] companyUserInfos) {
        this.companyUserInfos = companyUserInfos;
    }
}
