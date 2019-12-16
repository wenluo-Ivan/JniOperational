package com.distance.third.jniapplication.beans;

public class CompanyUserInfo {
    private long userId;
    private String userName;
    private String userPhone;
    private int userLever;

    public long getUserId() {
        return userId;
    }

    public void setUserId(long userId) {
        this.userId = userId;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getUserPhone() {
        return userPhone;
    }

    public void setUserPhone(String userPhone) {
        this.userPhone = userPhone;
    }

    public int getUserLever() {
        return userLever;
    }

    public void setUserLever(int userLever) {
        this.userLever = userLever;
    }
}
