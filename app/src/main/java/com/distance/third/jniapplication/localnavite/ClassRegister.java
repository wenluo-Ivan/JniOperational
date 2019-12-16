package com.distance.third.jniapplication.localnavite;

public class ClassRegister {

    public native void initJni();

    public native void releaseJNIObject(Object object);
}
