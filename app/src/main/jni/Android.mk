LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
APP_ABI := armeabi
APP_PLATFORM := android-14
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_CFLAGS := -Wno-psabi -DANDROID -D_ANDROID_ -D_FS_OS_ANDROID -D_FS_ARCH_32
LOCAL_CPPFLAGS :=  -D__cplusplus=201103L -fvisibility=hidden

# 这里引入当前目录下所有的cpp文件
FILE_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
LOCAL_LDFLAGS += -shared
LOCAL_C_INCLUDES += bionic
LOCAL_LDLIBS    := -lm -llog
LOCAL_MODULE := jnimodel

include $(BUILD_EXECUTABLE)
