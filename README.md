# JniOperational
JNI 工程实例
 1. 封装注册方法 REGISTERCLASSMETHODS 用于注册JNI类，映射JNI类与C++类对应的方法及参数
 2. 复写JNI_OnLoad方法，保存全局JVM指针以及MainThread指针
 3. 本JNI工程采用CMake方式进行编译，生成库名称为jnimodel，PlatForm为android-14，不支持64位架构，若需支持64位架构，建议platForm改成android-21, APP_ABI对应改成arm64 
 4. LOCAL_LDFLAGS += -shared 不进行设置的话，就必须增加main方法入口，加入这个 -shared 标记后，才能正常生成so库
 5. logutil.h 头文件是用于打印日志，打印方式参考代码中的调用，输出TAG为 jni_log ,如需改变，请直接修改logutil.h中的 LOG_TAG 定义
 6. JNI_Object 类封装了JNI中对变量的获取及定义，以及调用全局jvm指针来装载线程，卸载线程等操作