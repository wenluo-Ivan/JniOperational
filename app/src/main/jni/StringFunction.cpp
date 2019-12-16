#include "logutil.h"
#include "StringFunction.h"

void StringFunction::C2J(JNIEnv *pEnv, const std::string &param, jstring &out) {
    if (!param.empty()) {
        out = pEnv->NewStringUTF(param.c_str());
    }
}

void StringFunction::J2C(JNIEnv *pEnv, const jstring &param, std::string &out) {
    if (param != 0) {
        const char *pRef = pEnv->GetStringUTFChars(param, 0);

        if (pRef) {
            out = pRef;

            pEnv->ReleaseStringUTFChars(param, pRef);
        }
    } else
        out = "";
}

void StringFunction::C2J(JNIEnv *pEnv, const std::wstring &param, jstring &out) {
    if (!param.empty()) {
        int nSize = param.length() + 1;
        nSize = (nSize + 1) * 3;

        char *sz = new char[nSize];
        memset(sz, 0, nSize);
        ConvertUnicodeToUtf8(param.c_str(), sz, nSize);

        std::string s(sz);
        delete[] sz;
        sz = NULL;

        C2J(pEnv, s, out);
    }
}

void StringFunction::J2C(JNIEnv *pEnv, const jstring &param, std::wstring &out) {
    if (param == 0) {
        return;
    }

    std::string tmp;
    J2C(pEnv, param, tmp);

    size_t len = tmp.length() + 1;
    wchar_t *buf = new wchar_t[len];
    if (buf) {
        memset(buf, 0, len);
        ConvertUtf8ToUnicode(tmp.c_str(), buf, tmp.size());
        out = buf;
        delete[] buf;
    }
}

void StringFunction::C2J(JNIEnv *pEnv, const std::list<std::string> &param, jobjectArray &out) {
    static jclass _j_class_string = (jclass) pEnv->NewGlobalRef(
            pEnv->FindClass("java/lang/String"));

    out = pEnv->NewObjectArray(param.size(), _j_class_string, NULL);

    std::list<std::string>::const_iterator it = param.begin();
    for (int i = 0; it != param.end(); it++, i++) {
        jstring _j_str = 0;
        C2J(pEnv, *it, _j_str);

        pEnv->SetObjectArrayElement(out, i, _j_str);

        pEnv->DeleteLocalRef(_j_str);
    }
}

void StringFunction::J2C(JNIEnv *pEnv, const jobjectArray &param, std::list<std::string> &out) {
    out.clear();
    if (param == 0) {
        return;
    }

    int nCount = pEnv->GetArrayLength(param);

    for (int i = 0; i < nCount; i++) {
        std::string _temp;
        J2C(pEnv, (jstring) pEnv->GetObjectArrayElement(param, i), _temp);
        out.push_back(_temp);
    }
}

void StringFunction::C2J(JNIEnv *pEnv, const std::list<std::wstring> &param, jobjectArray &out) {
    static jclass _j_class_string = (jclass) pEnv->NewGlobalRef(
            pEnv->FindClass("java/lang/String"));

    out = pEnv->NewObjectArray(param.size(), _j_class_string, NULL);

    std::list<std::wstring>::const_iterator it = param.begin();
    for (int i = 0; it != param.end(); it++, i++) {
        jstring _j_str = 0;
        C2J(pEnv, *it, _j_str);

        pEnv->SetObjectArrayElement(out, i, _j_str);

        pEnv->DeleteLocalRef(_j_str);
    }
}

void StringFunction::J2C(JNIEnv *pEnv, const jobjectArray &param, std::list<std::wstring> &out) {
    out.clear();
    if (param == 0) {
        return;
    }

    int nCount = pEnv->GetArrayLength(param);
    for (int i = 0; i < nCount; i++) {
        std::string _temp;

        J2C(pEnv, (jstring) pEnv->GetObjectArrayElement(param, i), _temp);
        size_t nSize = (_temp.size() + 1) * 3;
        wchar_t *buf = new wchar_t[nSize];

        if (buf) {
            memset(buf, 0, nSize);
            ConvertUtf8ToUnicode(_temp.c_str(), buf, _temp.size());
            out.push_back(buf);

            delete[] buf;
            buf = NULL;
        }
    }
}

void StringFunction::C2J(JNIEnv *pEnv, const std::vector<std::string> &param, jobjectArray &out) {
    static jclass _j_class_string = (jclass) pEnv->NewGlobalRef(
            pEnv->FindClass("java/lang/String"));

    out = pEnv->NewObjectArray(param.size(), _j_class_string, NULL);

    std::vector<std::string>::const_iterator it = param.begin();
    for (int i = 0; it != param.end(); it++, i++) {
        jstring _j_str = 0;
        C2J(pEnv, *it, _j_str);

        pEnv->SetObjectArrayElement(out, i, _j_str);

        pEnv->DeleteLocalRef(_j_str);
    }
}

void StringFunction::J2C(JNIEnv *pEnv, const jobjectArray &param, std::vector<std::string> &out) {
    out.clear();
    if (param == 0) {
        return;
    }

    int nCount = pEnv->GetArrayLength(param);

    for (int i = 0; i < nCount; i++) {
        std::string _temp;
        J2C(pEnv, (jstring) pEnv->GetObjectArrayElement(param, i), _temp);
        out.push_back(_temp);
    }
}

void StringFunction::J2C(JNIEnv *pEnv, const jstring &param, wchar_t *out) {
    std::string tmp;

    if (param != 0) {
        tmp = pEnv->GetStringUTFChars(param, 0);
    } else {
        tmp = "";
    }

    if (!tmp.size() || !out) {
        return;
    }

    ConvertUtf8ToUnicode(tmp.c_str(), out, tmp.size());
}

void StringFunction::J2C(JNIEnv *pEnv, const jstring &param, char *out) {
    std::string tmp;

    if (param != 0) {
        tmp = pEnv->GetStringUTFChars(param, 0);
    } else {
        tmp = "";
    }

    if (out) {
        strncpy(out, tmp.c_str(), tmp.size());
    }
}

void StringFunction::C2J(JNIEnv *pEnv, const char *param, jstring &out) {
    if (param) {
        out = pEnv->NewStringUTF(param);
    }
}

void StringFunction::C2J(JNIEnv *pEnv, const wchar_t *param, jstring &out) {
    char *tmp = NULL;
    int size = 0;

    size = wcslen(param);
    if (!size) {
        return;
    }

    size = size * 3;

    tmp = (char *) malloc(size + 1);
    if (!tmp) {
        return;
    }
    memset(tmp, 0, size + 1);

    ConvertUnicodeToUtf8(param, tmp, size);
    out = pEnv->NewStringUTF(tmp);
    free(tmp);
    tmp = NULL;
}

int StringFunction::SplitString(const std::string &param, const std::string &split,
                                std::vector<std::string> &out) {
    std::string::size_type lastPos = param.find_first_not_of(split, 0);

    std::string::size_type pos = param.find_first_of(split, lastPos);
    while (std::string::npos != pos || std::string::npos != lastPos) {
        if (pos == lastPos) {
            return -1;
        }
        out.push_back(param.substr(lastPos, pos - lastPos));

        lastPos = param.find_first_not_of(split, pos);

        pos = param.find_first_of(split, lastPos);
    }
}

int StringFunction::ConvertUnicodeToUtf8(const wchar_t *wszIn, char *szOut, int nSize) {
    int len = 0; //记录转换后的Utf8字符串的字节数
    while (*wszIn)
    {
        //处理一个unicode字符
        char low = *wszIn;//取出unicode字符的低8位
        wszIn++;
        char high = *wszIn;//取出unicode字符的高8位
        unsigned  wchar = (high<<8)+low;//高8位和低8位组成一个unicode字符,加法运算级别高

        if (wchar <= 0x7F ) //英文字符
        {
            szOut[len] = (char)wchar;  //取wchar的低8位
            len++;
        }
        else if (wchar >=0x80 && wchar <= 0x7FF)  //可以转换成双字节szOut字符
        {
            szOut[len] = 0xc0 |((wchar >> 6)&0x1f);  //取出unicode编码低6位后的5位，填充到110yyyyy 10zzzzzz 的yyyyy中
            len++;
            szOut[len] = 0x80 | (wchar & 0x3f);  //取出unicode编码的低6位，填充到110yyyyy 10zzzzzz 的zzzzzz中
            len++;
        }
        else if (wchar >=0x800 && wchar < 0xFFFF)  //可以转换成3个字节的szOut字符
        {
            szOut[len] = 0xe0 | ((wchar >> 12)&0x0f);  //高四位填入1110xxxx 10yyyyyy 10zzzzzz中的xxxx
            len++;
            szOut[len] = 0x80 | ((wchar >> 6) & 0x3f);  //中间6位填入1110xxxx 10yyyyyy 10zzzzzz中的yyyyyy
            len++;
            szOut[len] = 0x80 | (wchar & 0x3f);  //低6位填入1110xxxx 10yyyyyy 10zzzzzz中的zzzzzz
            len++;
        }
        else //对于其他字节数的unicode字符不进行处理
        {
            return -1;
        }
        wszIn ++;//处理下一个unicode字符
    }
    //utf8字符串后面，有个\0
    szOut [len]= 0;
    return len;
}

int StringFunction::ConvertUtf8ToUnicode(const char *szIn, wchar_t *wszOut, int nSize) {
    int outputSize = 0; //记录转换后的Unicode字符串的字节数

    while (*szIn)
    {
        if (*szIn > 0x00 && *szIn <= 0x7F) //处理单字节UTF8字符（英文字母、数字）
        {
            *wszOut = *szIn;
            wszOut++;
            *wszOut = 0; //小端法表示，在高地址填补0
        }
        else if (((*szIn) & 0xE0) == 0xC0) //处理双字节UTF8字符
        {
            char high = *szIn;
            szIn++;
            char low = *szIn;
            if ((low & 0xC0) != 0x80)  //检查是否为合法的UTF8字符表示
            {
                return -1; //如果不是则报错
            }

            *wszOut = (high << 6) + (low & 0x3F);
            wszOut++;
            *wszOut = (high >> 2) & 0x07;
        }
        else if (((*szIn) & 0xF0) == 0xE0) //处理三字节UTF8字符
        {
            char high = *szIn;
            szIn++;
            char middle = *szIn;
            szIn++;
            char low = *szIn;
            if (((middle & 0xC0) != 0x80) || ((low & 0xC0) != 0x80))
            {
                return -1;
            }
            *wszOut = (middle << 6) + (low & 0x3F);//取出middle的低两位与low的低6位，组合成unicode字符的低8位
            wszOut++;
            *wszOut = (high << 4) + ((middle >> 2) & 0x0F); //取出high的低四位与middle的中间四位，组合成unicode字符的高8位
        }
        else //对于其他字节数的UTF8字符不进行处理
        {
            return -1;
        }
        szIn ++;//处理下一个utf8字符
        wszOut ++;
        outputSize += 2;
    }
    //unicode字符串后面，有两个\0
    *wszOut = 0;
    wszOut++;
    *wszOut = 0;
    return outputSize;
}

//void StringFunction::C2J( JNIEnv *pEnv,const std::list<std::string> &param,jobjectArray &out )
//{
//    static jclass _j_class_string = (jclass)pEnv->NewGlobalRef(pEnv->FindClass("java/lang/String"));
//
//    out  = pEnv->NewObjectArray(param.size(),_j_class_string,NULL);
//
//    std::list<std::string>::const_iterator it = param.begin();
//    for (int i = 0; it != param.end() ; it++,i++)
//    {
//        jstring _j_str = 0;
//        C2J(pEnv,*it,_j_str);
//
//        pEnv->SetObjectArrayElement(out,i,_j_str);
//
//        pEnv->DeleteLocalRef(_j_str);
//    }
//}
