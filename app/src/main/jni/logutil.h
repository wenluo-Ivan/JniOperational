
#include <android/log.h>

#define LOG_TAG		"jni_log"
#define LOGV(...)	__android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)
#define LOGD(...)	__android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGI(...)	__android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGW(...)	__android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)
#define LOGE(...)	__android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

#if __WORDSIZE == 64

typedef long int                 int64_t;//NOLINT(legal/name)
typedef unsigned long int       uint64_t;//NOLINT(legal/name)
#else

#endif

