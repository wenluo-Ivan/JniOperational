package com.distance.third.jniapplication.localnavite;

import com.distance.third.jniapplication.beans.CompanyInfo;
import com.distance.third.jniapplication.beans.CompanyUserInfo;

/**
 * JNI基本数据转换操作
 */
public class TransFunction {
    // 传递int值到底层
    public native void transferInt(int index);

    // 传递long值到底层
    public native void transferLong(long index);

    // 传递String值到底层
    public native void transferString(String str);

    // 传递布尔值到底层
    public native void transferBoolean(boolean isTrue);

    // 传递int数组
    public native void transferIntArray(int[] ints);

    // 传递long数组
    public native void transferLongArray(long[] longs);

    // 传递string数组
    public native void transferStringArray(String[] strings);

    // 传递对象
    public native void transferObject(CompanyUserInfo companyUserInfo);

    // 传递复合对象
    public native void transferCompositeObject(CompanyInfo companyInfo);
}
