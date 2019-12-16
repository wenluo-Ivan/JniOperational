#pragma once

#include <jni.h>

#include <string>
#include <list>
#include <vector>
#include <stdlib.h>

class StringFunction
{
	StringFunction(void){};
	~StringFunction(void){};

public:

	static void C2J(JNIEnv *pEnv,const std::string &param,jstring &out);//NOLINT(runtime/references)
	static void J2C(JNIEnv *pEnv,const jstring &param,std::string &out);//NOLINT(runtime/references)

	static void C2J(JNIEnv *pEnv,const std::list<std::string> &param,jobjectArray &out);//NOLINT(runtime/references)
	static void J2C(JNIEnv *pEnv,const jobjectArray &param,std::list<std::string> &out);//NOLINT(runtime/references)

	static void C2J(JNIEnv *pEnv,const std::wstring &param,jstring &out);//NOLINT(runtime/references)
	static void J2C(JNIEnv *pEnv,const jstring &param,std::wstring &out);//NOLINT(runtime/references)
    
	static void C2J(JNIEnv *pEnv,const std::list<std::wstring> &param,jobjectArray &out);//NOLINT(runtime/references)
	static void J2C(JNIEnv *pEnv,const jobjectArray &param,std::list<std::wstring> &out);//NOLINT(runtime/references)

	static void C2J(JNIEnv *pEnv,const std::vector<std::string> &param,jobjectArray &out);//NOLINT(runtime/references)
	static void J2C(JNIEnv *pEnv,const jobjectArray &param,std::vector<std::string> &out);//NOLINT(runtime/references)

	static void J2C(JNIEnv *pEnv,const jstring &param, wchar_t *out);//NOLINT(runtime/references)
	static void C2J(JNIEnv *pEnv, const wchar_t *param,jstring& out);//NOLINT(runtime/references)

	static void J2C(JNIEnv *pEnv,const jstring &param,char *out);//NOLINT(runtime/references)
	static void C2J(JNIEnv *pEnv, const char *param,jstring& out);//NOLINT(runtime/references)

	static int SplitString(
	    const std::string &param,const std::string &split,std::vector<std::string> &out);//NOLINT(runtime/references)
	static int ConvertUnicodeToUtf8(const wchar_t * wszIn, char *szOut, int nSize);

    static int ConvertUtf8ToUnicode(const char * szIn, wchar_t *wszOut, int nSize);

};
